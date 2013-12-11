#include "Eval.h"
extern char path[];
extern Sociaty ns;
extern char *eve;
extern char *evalstr;
extern char *argsstr;
extern char *namestr;
extern char *valuestr;
extern char *elementstr;


#define EVALDEBUG
char* Eval(Role *r){

	char *eval;
	Role *t;
	t = Sociaty_RoleEmploy(r, evalstr);

//	p.title = evalstr;
//	p.len = strlen(evalstr);
//	Sociaty_AddNewRole(str);
	eval = GetDymValue(t);
	if(eval != NULL)
//	printf("xxx%s\n", str);
		return EvalString(r, eval, 2);
	return NULL;
}
char* EvalString(Role *r, char *str, char adddone){
	char result_buf[MAX_BLOCK_SIZE];
  char *result = &result_buf[0];
  InterpretValue(r, str, &result);
	switch(adddone){
	case 2:
		result[0] = '\n';
		result[1] = '\0';
		strcat(result, r->_Name);
		strcat(result, ".Done = 1\n");
		break;
	case 1:
		result[0] = '\n';
    result[1] = '\0';
		break;
	default:
		result[0] = '\0';
	}
  result =  &result_buf[0];
#ifdef EVALDEBUG
	fprintf(ns.Err, "\t---->Result: \n========\n%s\n========\n", result);
#endif
	return result;
}
char GetFlag(char *str){
	return 0;
}
char* GetPath(char *id){
	char *token;
	char tpath[MAX_FILE_NAME];
	char *fname;
	FILE *tfp;
	strcpy(tpath, path);
	token = strtok(tpath ,":");

	fname = (char *)malloc(MAX_FILE_NAME);

	while ( token = strtok(NULL, ":") ){
		strcpy(fname, token);
		strcat(fname, id);
		if(eisfile(fname)) return fname;

		strcpy(fname, token);
		strcat(fname, id);
		strcat(fname, ".e");	
		if(eisfile(fname)) return fname;
	}	
	return NULL;
}
char* UseFile(char *str){
  char* fpath;
  fpath=GetPath(str);
  if(fpath == NULL){
    eerror("fail to include file");
    eerror(str);
    exit(1);
  }

  if(Sociaty_SearchUsedFile(fpath) == -1){
    Sociaty_AddUsedFile(fpath);
		return fpath;
  }
	return NULL;
}
/*
getdymvalue criteria:
1. value or target->value GetValue
2. each level, each SupPrts, search Role GetDeepValue

each SupPrts
1. sup->parents
2. sup->parents->target
3. sup->target->parents
4. sup->target->parents->target
5. ns.Root

search Role
 */

static char* GetValue(Role *r){
	if(r== NULL) return NULL;
  Role *tr = r;
	if(tr->_Value !=NULL) return tr->_Value;
  while(tr->_Target != NULL){
    tr = tr->_Target;
		if(tr->_Value !=NULL) return tr->_Value;
	}
  return NULL;
}
static Role* GetRoleKeyIndex(Role *p, Role *r, int level){
	Role *t, *t2;
	t2 = Role_GetSup(r, level);
	t = RoleHash_Get(p->Subs, t2->Key);
	if(t2->Index != -1){
		if(t->_Elements->Length <= t2->Index) return NULL;
		t = t->_Elements->Values[t2->Index];
	}
	if(t != NULL)
		return t;
	return NULL;
}

static char* GetValueSub(Role *p, Role *r, int level){
	char *v;
	int i;
	Role *t = p;
	Role *t2, *t3;
	RoleArray *ra;
	int pi;
#ifdef EVALDEBUG
	fprintf(ns.Err, "GetValueSub %s %s %d\n", t->_Name, r->_Name, level);
#endif
	//make sure walk to end
	for(i=level; i>=0; i--){
		t2 = GetRoleKeyIndex(t, r, i);
		if(t2 == NULL){
			if(t!=ns.Root){
				ra = t->Prts;
				for(pi = ra->Length-1; pi>=0; pi--){
					t3 = ra->Values[pi];
					v = GetValueSub(t3, r, i);
					if(v!=NULL) return v;
				}
				t3 = t;
				if(t3->_Target != NULL){
					t3 = t3->_Target;
					v = GetValueSub(t3, r, i);
					if(v!=NULL) return v;
				}
			}
			return NULL;
		}
		t = t2;
	}
	return GetValue(t);
/*
	if(t != NULL){
		v = GetValue(t);
		if(v != NULL) return v;
	
		if(p != ns.Root){
			ra = t->Prts;
			for(pi = ra->Length-1; pi>=0; pi--){
				t2 = ra->Values[pi];
				v = GetValueSub(t2, r, level);
				if(v!=NULL) return v;
			}
			
			while(t->_Target != NULL){
				t = t->_Target;
				v = GetValueSub(t, r, level);
				if(v!=NULL) return v;
				ra = t->Prts;
				for(pi = ra->Length-1; pi>=0; pi--){
					t = ra->Values[pi];
					v = GetValueSub(t, r, level);
					if(v!=NULL) return v;
				}
			}
		}
	}
*/
	return NULL;
}
char* GetDymValue(Role *r){
	char *v;
	v = GetValue(r);
#ifdef EVALDEBUG
  fprintf(ns.Err, "GetValue %s", v);
#endif
	if(v == NULL) v = GetNoDefaultValue(r);
#ifdef EVALDEBUG
  fprintf(ns.Err, "GetNoDefaultValue %s", v);
#endif
	if(v == NULL) v = GetDefaultValue(r);
#ifdef EVALDEBUG
	fprintf(ns.Err, "GetDefaltValue %s\n%s\n", r->_Name, v);
#endif

  return v;
}
			

char* GetDefaultValue(Role *r){
	Role *t, *sup;
	char *v;
	
	int i, level;
//	Role_Print(r);
//	Role_Print(ns.Root);
	level=0;
	while(1){
		sup = Role_GetSup(r, level+1);
		if(sup == ns.Root) break;
//		printf("level %d\n", level);
		v = GetValueSub(ns.Root, r, level);
		if(v != NULL) return v;
		level ++;
	}
	return NULL;
}
char* GetNoDefaultValue(Role *r){
	Role *t, *sup;
	char *v;
	int pi, i, level;
	RoleArray *ra;
//	Role_Print(r);
//	Role_Print(ns.Root);
	level=0;
	while(1){
		sup = Role_GetSup(r, level+1);
		if(sup == ns.Root) break;
		ra = sup->Prts;
		for(pi = ra->Length-1; pi>=0; pi--){
			t = ra->Values[pi];			
			v = GetValueSub(t, r, level);
			if(v != NULL) return v;
		}
		t = sup;
		while(t->_Target != NULL){
			t=t->_Target;
			v = GetValueSub(t, r, level);
			if(v!=NULL) return v;
			ra = t->Prts;
			for(pi = ra->Length-1; pi>=0; pi--){
				t = ra->Values[pi];
				v = GetValueSub(t, r, level);
				if(v!=NULL) return v;
			}
		}		

		level ++;		
	}
	return NULL;
}
/*
char ExistValue(Role *r){
	if(!estrisnull(r->_Value)) return 1;
	if(r->_TargetIndex != -1) return 1;
	return 0;
}
char *GetParentName(Role *r){
	if(r->Parents.Length == 0) return NULL;
	return Sociaty_GetRole(r->Parents.Values[r->Parents.Length-1])->_Name;
}
char* GetValue(Role *r){
	if(!estrisnull(r->_Value)) return r->_Value;
	if(r->_TargetIndex != -1)
		return Sociaty_GetRole(r->_TargetIndex)->_Value;
	return "";
}
char* GetFinalValue(Role *r){
	if(!estrisnull(r->_Value)) return r->_Value;
	Role *tmpr = r;
	while(tmpr->_TargetIndex != -1)
		 tmpr = Sociaty_GetRole(tmpr->_TargetIndex);
	return tmpr->_Value;
}
char* GetDymValueNoEve(char *name){
	int ind;
	Role *r;
	char *val;
#ifdef EVALDEBUG
  fprintf(ns.Err,"GetDymValue %s\n", name);
#endif

	ind = Sociaty_SearchRole(name);
	if(ind != -1){
		r = Sociaty_GetRole(ind);
		if(ExistValue(r)){
			val = GetFinalValue(r);
			if(!estrisnull(val)) return val;
		}
	}
	return GetValueDeep(name);

}

char* GetNoDefaultValue(Role *r){
  Role *t, *p, *t2;
  char *v;
  int i, level, pi, plen;
  for(level=0; level<r->Depth; level++){
		plen = Role_GetSup(r, level)->Prts->Length;
		if(!plen) continue;
    for(pi=Role_GetSup(r, level)->Prts->Length
    for(i=level; level>=0; level--){
      t = RoleHash_Get(t, Role_GetSup(r, i)->Key);
      if(t == NULL) break;
    }
    if(t != NULL){
      v = Role_GetFinalValue(t);
      if(v != NULL) return v;
    }
  }
}

char* GetValueDeep(char *name){
//	printf("name %s\tlevel %d\n",name,level);
#ifdef EVALDEBUG
	fprintf(ns.Err,"GetValueDeep %s\n", name);
#endif
	Role *pr, *ppr;
	char *ni;
	int len, ind, j;
	char name2[255], pre[255], suf[255];
	Role *r;
	char *rtn;


	int slen = strlen(name);
	len = 0; 
	ni = &name[0];
	while(len++ < slen){
		ni ++;
		if(ni[0] == '.'){

//			level --;
//			if(level>0) continue;
			strcpy(suf, ni +1); //dump suffix

			strncpy(pre, name, len);
			pre[len] = '\0';
//			printf("see. %c  %d  %s   %s\n",ni[0],len,pre,suf);
			ind = Sociaty_SearchRole(pre);
			if(ind == -1) continue;
			pr = Sociaty_GetRole(ind); //get apprent role from prefix
			if(pr->_TargetIndex != -1){ //if a pointer do eval
				pr = Sociaty_GetFinalRole(ind);
				strcpy(name2, pr->_Name);
        strcat(name2, ".");
        strcat(name2, suf);

        rtn = GetDymValueNoEve(name2);
        if(!estrisnull(rtn)) return rtn;
			}
			
			for(j=pr->Parents.Length; j>0; --j){
				ppr = Sociaty_GetFinalRole(pr->Parents.Values[j-1]);
				strcpy(name2, ppr->_Name);
				strcat(name2, ".");
				strcat(name2, suf);
				
				rtn = GetDymValueNoEve(name2);
				if(!estrisnull(rtn)) return rtn;
			}
		}
	}	
	return "";

}
*/
static char* PrintArray(Role *a, char *sep, char *end, char* format){
	int i;
	char v[MAX_BLOCK_SIZE];
	char *p;
	int seplen = strlen(sep);
	if(a->_Elements->Length == 0) return;
//	printf("sep %s, end %s, format %s\n",sep, end, format);
	sprintf(v, format, GetValue(a->_Elements->Values[0]));
//	printf("xxxxx%s\n",v);
	p = &v[strlen(v)];
	for(i=1; i<a->_Elements->Length; i++){
		sprintf(p, sep);
		p+=seplen;
		sprintf(p, format, GetValue(a->_Elements->Values[i]));
		p = &v[strlen(v)];
	}
	sprintf(p, end);
	p = &v[0];

	return p;
}
static char* PrintHash(Role *a, char *sep, char *kvsep, char *end, char format){
	return NULL;
}
Role *GetRoleParam(TokenParam *pp, Scanner *ps){
	Role *r;
	int opi,i;
	char *tmp;

	tmp = &pp->op[0];
  opi = pp->oplen;

	if(pp->op[0] == '%'){
		tmp ++;
    opi --;
		r = ns.Curr;
	}
	else if(pp->op[0] == '&'){ //relative name
		tmp ++;
		opi --;
		r = ps->r;
	}
	else{
		r = ps->r;
	}
	
	while(opi>0){
		switch(tmp[0]){
		case '$':
			if(r->Prts->Length)
				r = r->Prts->Values[r->Prts->Length-1];
			else 
				r = ns.Root;
			break;
		case '@':
			r = r->Sup;
			break;
		default:
			return 0;
		}
		opi--;
		tmp++;
	}
//	Parameter, r: gene.AdvancedCheck.Run;
	for(i=0; i<pp->steplen; i++)
		if(pp->issubs[i])
			r = Sociaty_RoleEmploy(r, pp->keys[i]);
		else
			r = Sociaty_RoleExpend(r, atoi(pp->keys[i]));
	return r;	
}
char EvalParam(TokenParam *pp, Scanner *ps){
	char *tmpname;
	Role *r;
	int ind;
	char *sep, *kvsep, *end, *format;
	char *name;
	char *v;
	r = GetRoleParam(pp, ps);
	switch(pp->c){
	case 'v': //VALUE
		v = GetDymValue(r);
		if(v == NULL) return 1;
		if(pp->op[0] != '%'){
			InterpretValue(r, v, ps->out_curr);
		}
		else{
			InterpretValue(ps->r, v, ps->out_curr);
		}
		return 1;
		break;
	case 'a':
		sep = (pp->argc>0 && strlen(pp->argv[0])>0)?pp->argv[0]:",";
		end = (pp->argc>1 && strlen(pp->argv[1])>0)?pp->argv[1]:"";
		format = (pp->argc>2 && strlen(pp->argv[2])>0)?pp->argv[2]:"%s";
		sprintf((*ps->out_curr),"%s",PrintArray(r, sep ,end, format));
		break;
	case 'h':
		sep = pp->argc>0?pp->argv[0]:",";
		kvsep = pp->argc>1?pp->argv[1]:"=";
		end = pp->argc>2?pp->argv[2]:"";
		format = pp->argc>3?pp->argv[3]:"%s";
		break;
	case 'V': //address
		sprintf((*ps->out_curr),"#%ld#",r);
		break;
	case 'N': //NAME
		sprintf((*ps->out_curr),"%s",r->_Name);
		break;
	case 'T':
    sprintf((*ps->out_curr),"%s",estrafter(r->_Name,'.'));
    break;
	case 'L':
		sprintf((*ps->out_curr),"%d",r->_Elements->Length);
		break;
	case 'i':
    sprintf((*ps->out_curr),"%s._Index",r->_Name);
    break;
  case 'I':
		sprintf((*ps->out_curr),"%s._Iterator",r->_Name);
		break;
	case 'A':
		sprintf((*ps->out_curr),"%s._Args",r->_Name);
	case 'P':
		sprintf((*ps->out_curr),"^%s.Print^",r->_Name);
		break;
/*
	case 'P': //Parents
		break;
	case 'S': //Superiors
		break;
	case 'B': //Subordinates
		break;
*/
	default:
		return 0;
	}
	while((*ps->out_curr)[0] != '\0')
		(*ps->out_curr)++;
	return 1;
}

char ScanIdentifer(Scanner *ps){
	int len, len2;
	char *tmp, *tmp2;
	Role *rtn;
//	Role *opr;
	int see_left = 0;
	int see_dash = 0;
	char *val, *indexstr;
	char c;
	TokenParam p;
	
	p.op = ps->in_curr;
	p.argc = 0;
	tmp = ps->in_curr+1;
	p.oplen = 1;
	while(tmp[0] == '$' || tmp[0] == '@'){
		p.oplen++;
		tmp++;
	}
	
	rtn = NULL;	
	p.steplen = 0;
	if(tmp[0] == '|'){
		see_left =1;
		tmp ++;

		/*get identifiers*/
		while(1){
			/*get title*/
			len = 0;
			if(!eisletter(tmp[0])) return 0;
			tmp2=tmp;
			len ++;
			tmp++;
			while(eiss(tmp[0])){
//		printf("%c\t%d\n", tmp[0], p.len);
				len ++;
				tmp++;
			}
//////////////////////////
			if(p.steplen == 0){
				p.keys = (char**)malloc(sizeof(char*));
				p.issubs = (char*)malloc(1);
			}
			else{
				p.keys = (char**)realloc(p.keys, p.steplen+1 * sizeof(char*));
        p.issubs = (char*)realloc(p.issubs, p.steplen+1);
			}
			p.issubs[p.steplen] = 1;
			p.keys[p.steplen] = estrndup(tmp2, len);
			p.steplen++;
////////////////////////			

			if(tmp[0] == '['){
				len = 0;
				tmp++;
				tmp2=tmp;
				while(eisdigit(tmp[0])){ 
					len ++;
					tmp++;
				}
				if(tmp[0] != ']') return 0;
				tmp++; //skip ]
/////////////				
			if(p.steplen == 0){
				p.keys = (char**)malloc(sizeof(char*));
				p.issubs = (char*)malloc(1);
			}
			else{
				p.keys = (char**)realloc(p.keys, p.steplen+1 * sizeof(char*));
        p.issubs = (char*)realloc(p.issubs, p.steplen+1);
			}
			p.issubs[p.steplen] = 0;
			p.keys[p.steplen] = estrndup(tmp2, len);
			p.steplen++;
/////////////////
			}
			/*eval para*/
			if(tmp[0] == '|' || tmp[0] == '-'){	
//				printf("xxxxx%c\n",p.op[0]);

				break;
			}
			else if(tmp[0] == '.'){

				tmp ++;
			}
			else{
				return 0;
			}

		}
	}

//	fprintf(ns.Err,"---------%c:%s:%s\n",p.op[0],rtn->_Name,rtn->_Value);
//	p.index = -1;
	if(tmp[0] == '-'){
		see_dash = 1;
		p.c = tmp[1];
		tmp += 2;

		if(tmp[0] == '('){
      tmp++;
//			tmp2 = tmp;
			len2= 0;
      while(1){
				if(tmp[0] == ')'){
					p.argv[p.argc][len2]='\0';
					if(len2){
						p.argc++;
					}
					tmp++;
					break;
				}
				if(tmp[0] == ','){
					p.argv[p.argc][len2]='\0';
					len2=0;
					p.argc++;
					tmp++;
					continue;
				}
				if(tmp[0] == '\\'){
					switch(tmp[1]){
					case ',':
						tmp++;
						break;
					case 't':
						p.argv[p.argc][len2] = '\t';
						len2++;
						tmp+=2;
						continue;
						break;
					case 'n':
						p.argv[p.argc][len2] = '\n';
            len2++;
            tmp+=2;						
            continue;
            break;
					}					
				}

				p.argv[p.argc][len2] = tmp[0];
				len2++;
        tmp++;
      }
    }

	}
	else{
		p.c = 'v';
	}

	if(see_left){
		if(tmp[0] != '|') return 0;
		tmp ++ ;
	}
	if(!see_left && !see_dash) return 0;
#ifdef EVALDEBUG
	int i;
  fprintf(ns.Err, "Parameter, r: %s\n",	ps->r->_Name);
	for(i=0; i<p.steplen; i++){
		fprintf(ns.Err, "%s,%d,", p.keys[i], p.issubs[i]);
	}
  fprintf(ns.Err, "\nop ");
	for(i=0; i<p.oplen; i++){
    fprintf(ns.Err, "%c", p.op[i]);
  }
  fprintf(ns.Err, "\tchar %c\n", p.c);
	for(i=0; i<p.argc; i++){
    fprintf(ns.Err, "%s,", p.argv[i]);
  }
	fprintf(ns.Err, "\n");
#endif

	if(!EvalParam(&p, ps)) return 0;

	ps->in_curr = tmp;
	return 1;
}
void InterpretValue(Role *r, char *v, char **out_curr){
#ifdef EVALDEBUG
	fprintf(ns.Err, "\t---->Eval Content: \n========\n%s\n========\n", v);
#endif

	Scanner s;
	char c;
	s.r = r;
	s.in_curr = v;
	s.out_curr = out_curr;
	while (1){

		switch(s.in_curr[0]){
		case '\0':
			return;
		case '\\':
			c = s.in_curr[1];
			if(c == '$'  || c == '@'  || c == '%'  || c == '&' ){
				s.in_curr ++;
			}
			break;
		case '%':
      if(ScanIdentifer(&s)) continue;
      break;
		case '&':
			if(ScanIdentifer(&s)) continue;
      break;
		case '@':
      if(ScanIdentifer(&s)) continue;
      break;
    case '$':
      if(ScanIdentifer(&s)) continue;
      break;
		default:
			;
		}
		(*s.out_curr)[0] = s.in_curr[0];
		(*s.out_curr) ++;
		s.in_curr++;
	}
}




