#include "Eval.h"
extern char path[];
extern Sociaty ns;
extern char* evalstr;
extern char *namestr;
extern char *valuestr;
extern char *superstr;

char* Eval(Index i){
//	printf();
	Role *r;
	char *title, *value, *eval;
	char result_buf[100000];
  char *result = &result_buf[0];

	r = Sociaty_GetRole(i);

	title = GetTitleName(r);
	if(!strcmp(title, evalstr)){
//		printf("%s\t%s\n",title,evalstr);
		eerror("Eval is not allowed to use");
		exit(1);
	}
	if(estrisnull(r->_Value)){		
		r->_Value = GetTitleValueFromSuperiors(r, title, strlen(title));
	}
	eval = GetEvalValue(r);
//	printf("%s\n", eval);
	InterpretValue(r, eval, &result);
	result[0] = '\n';
	result =  &result_buf[0];
//	printf("%s\n", result);
	return result;
//	fprintf(out, "%c\n", );	
/*	
	if(r->_Value != NULL){

		switch(r->_Lang){
		case awk:
			return;
		case bash:
			return;
		case c:
			return;
		case m4:
			return;
		case matlab:
			return;
		case perl:
			return;
		case python:
			return;
		case r:
			return;
		default:
			Sociaty_Output(r->_Value);
			return;
		}

		return;
	}
	pr = Sociaty_GetRole(pi);
*/
//warning r will lost if add new role 
// because of realloc
//	printf("Eval %d\t%d\n", i, pi);
}
/*
Lang GetLang(char *str){
	char *lstr = estrlower(str);
	if(!strcmp(lstr,"awk"))
		return awk;
	else if(!strcmp(lstr,"bash"))
    return bash;
	else if(!strcmp(lstr,"c"))
    return c;
  else if(!strcmp(lstr,"m4"))
    return m4;
  else if(!strcmp(lstr,"matlab"))
    return matlab;
  else if(!strcmp(lstr,"perl"))
    return perl;
  else if(!strcmp(lstr,"python"))
    return python;
  else if(!strcmp(lstr,"r"))
    return r;
  else 
		return stdout;
	free(lstr);
}
*/
char GetFlag(char *str){
	return 0;
}
char* GetPath(char *id){
	char *token;

	token = strtok(path ,":");
	char *fname;
	FILE *tfp;
	fname = (char*)malloc(MAX_FILE_NAME);
	while ( token = strtok(NULL, ":") ){
		strcpy(fname, token);
		strcat(fname, id);
		//	printf("%s\n", fname);
		tfp = fopen(fname, "r");
		if(tfp != NULL){
			fclose(tfp);
			return fname;
		}

		strcpy(fname, token);
		strcat(fname, id);
		strcat(fname, ".e");	
    tfp = fopen(fname, "r");
    if(tfp != NULL){
      fclose(tfp);
      return fname;
    }
	}	
	return NULL;
}
char* GetTitleName(Role *r){
	return estrafter(r->_Name, '.');
}
char* GetTitleValueFromSuperiors(Role *r, char *title, int len){
	Role *sr;
	char *rpr;
	int i;
	for(i=0; i<r->Superiors.Length; i++){
		sr = Sociaty_GetRole(r->Superiors.Values[i]);
		
    rpr = GetTitleValueLevel1(sr, title, len);
    if(!estrisnull(rpr)) return rpr;
	}
	return "";
}
char* GetTitleValue(Role *r, char *title, int len){
	int i,j;
	Role *pr,* psr;
	char *rpr;
	char *ttitle;
	//_Value, _Name, _Super exception
	
	if(!strncmp(title, valuestr, strlen(valuestr))){
		return r->_Value;
	}
	if(!strncmp(title, namestr, strlen(namestr))){
		return r->_Name;
	}
	if(strncmp(title, superstr, strlen(superstr))){
		rpr = GetTitleValueLevel1(r, title, len);
		if(!estrisnull(rpr)) return rpr;
	}

	for(i=0; i<r->Parents.Length; i++){
		pr = Sociaty_GetRole(r->Parents.Values[i]);
		
		rpr = GetTitleValueLevel1(pr, title, len);
		if(!estrisnull(rpr)) return rpr;
	}
	return "";
}
char *GetTitleValueLevel1(Role *pr, char *title, int len){
	Role *psr;
	char *ttitle;
	int j;
	for(j=0; j<pr->Subordinates.Length; j++){
		psr = Sociaty_GetRole(pr->Subordinates.Values[j]);
		ttitle = GetTitleName(psr);
		if(strlen(ttitle) >= len
			 && !strncmp(title, ttitle, len)
			 && !estrisnull(psr->_Value)){
			return psr->_Value;
		}
	}
	return NULL;
}
char* GetEvalValue(Role *r){
	return GetTitleValue(r, evalstr, strlen(evalstr));
}
void InterpretValue(Role *r, char *v, char **out_curr){
	char *in_curr, *trans;
	char *in_tmp;
	int len;
	int end = 0;
	in_curr = v;
	while (!end){
//		printf("%s\n", in_curr);
		switch(in_curr[0]){
		case '\0':
//			printf("END\n");
			end=1;
			return;
		case '\\':
			in_curr ++;
			(*out_curr)[0] = in_curr[0];
			(*out_curr) ++;
			in_curr++;
			continue;
	  case '$':
			in_tmp = in_curr +1;
			len = 0;
			if(eisletter(in_tmp[0])){
				len ++;
				in_tmp++;
				while(eiss(in_tmp[0])){
					len ++;
					in_tmp++;
				}			
				trans = GetTitleValue(r, in_curr + 1, len);
//				printf("get %s\n", trans);
				InterpretValue(r, trans, out_curr);
				in_curr = in_tmp;
			}
			else{
				(*out_curr)[0] = in_curr[0];
				(*out_curr) ++;
				in_curr++;
			}
			continue;
		default:
			(*out_curr)[0] = in_curr[0];
			(*out_curr) ++;
			in_curr++;
		}
	}
}




