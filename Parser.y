%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */


//#include "Expression.h"
#include "Sociaty.h"
#include "Role.h"
#include "Eval.h"
#include "Parser.h"
#include "Lexer.h"

/*
int yyparse(Expression **expression, yyscan_t scanner);
int yyerror(Expression **expression, yyscan_t scanner, const char *msg) {
	// Add error handling routine as needed
}
*/
	extern void p(int);
	extern FILE *out;
	int yyparse(yyscan_t scanner);
	int yyerror(yyscan_t scanner, const char *msg){
//		printf("yyerror, %s: '%s' in line %d\n", msg, yytext, yylineno);
		printf("yyerror, %s\n",msg);
	}

 
%}
 
%code requires {
#include "Common.h"  
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
	typedef void* yyscan_t;
#endif
void ParseExpressionFromFile(char *fpath);
void ParseExpressionFromFp(FILE *fp);
void ParseExpressionFromString(char *str);
yyscan_t current_scanner;
 }
 
%output  "Parser.c"
%defines "Parser.h"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
 
%union {
	int numval;
	IndexArray iaval;
//	IntTuple2 num2val;
	char *strval;
}
  

%token <strval> IDENTIFIER 
%token <strval> CONSTANT 
%token <strval> BLOCK

%token FOR IF IFELSE USE ADD
%token SETFLAG SETOUT SETARGS
%token <charval> TOKEN_PRINT
%token END_OF_STATEMENT 
%token STATEMENT

%type <iaval> argument_list
%type <numval> eval

%type <numval> role
%type <numval> member
%type <numval> argument


%start translation_unit

%%
translation_unit
: statement { p(1000);}
| translation_unit statement { p(1002);}
;
statement
: END_OF_STATEMENT {p(101);}
| expression END_OF_STATEMENT  {p(102);}
| STATEMENT {p(103);}
;
controls
: FOR role role BLOCK
{
	int i;
	for(i=0; i< Sociaty_GetRole($3)->Elements.Length; i++){
		Sociaty_GetRole($2)->_Value = 
			Sociaty_GetRole(Sociaty_GetRole($3)->Elements.Values[i])->_Value;
		estraddeol(&$4);
		ParseExpressionFromString($4);
	}
}
| IF role BLOCK
{

	if(!estrisnull(Sociaty_GetRole($2)->_Value)){
		estraddeol(&$3);
		ParseExpressionFromString($3);
	}

}
| IFELSE role BLOCK BLOCK
{
  if(!estrisnull(Sociaty_GetRole($2)->_Value)){
		estraddeol(&$3);
    ParseExpressionFromString($3);
  }
	else{
		estraddeol(&$4);
		ParseExpressionFromString($4);
	}
}
 
;
expression
: controls
| SETFLAG role role
{
  p(201);
	Sociaty_GetRole($2)->_Flag = Sociaty_GetRole($3)->_Flag;
}
| SETFLAG role CONSTANT
{
  p(202);
	Sociaty_GetRole($2)->_Flag = GetFlag($3);
}
| SETARGS role argument_list
{
	//TODO Argument Parsing
}
| SETOUT role 
{
  p(203);
	Sociaty_SetOut(Sociaty_GetRole($2)->_Value);
}
| SETOUT CONSTANT
{
  p(204);
	Sociaty_SetOut($2);
}
| ADD role CONSTANT
{
	IndexArray_Add(&Sociaty_GetRole($2)->Elements,
								 Sociaty_AddConstRole($3));
}
| ADD role role
{
	IndexArray_Add(&Sociaty_GetRole($2)->Elements,
								 $3);
}
| USE role
{
  p(205);
	char *fpath = estrdup(GetPath(Sociaty_GetRole($2)->_Value));
	if(Sociaty_SearchUsedFile(fpath) == -1){
		Sociaty_AddUsedFile(fpath);
		ParseExpressionFromFile(fpath);
	}
	free(fpath);
}
| USE CONSTANT
{
  p(206);
//	printf("$2%s\n", $2);
	char *fpath = estrdup(GetPath($2));
	if(Sociaty_SearchUsedFile(fpath) == -1){
//		printf("%s\n", fpath);
		Sociaty_AddUsedFile(fpath);
		ParseExpressionFromFile(fpath);
	}
	free(fpath);
}
| role '=' '[' argument_list ']'
{
	p(206);
	IndexArray_PassByValue(&Sociaty_GetRole($1)->Elements, &$4);
//	free($4.Values);
	// array TODO
}
| role '=' CONSTANT 
{ 
  p(207);
	if(Sociaty_GetRole($1)->_Value != NULL) free(Sociaty_GetRole($1)->_Value);
	Sociaty_GetRole($1)->_Value = estrdup($3);
}
| role '=' role
{
  p(208);
	if(Sociaty_GetRole($1)->_Value != NULL) free(Sociaty_GetRole($1)->_Value);
  Sociaty_GetRole($1)->_Value =
    estrdup(Sociaty_GetRole($3)->_Value);
}
| role '+' '=' CONSTANT
{
  p(207);
  estradd(&Sociaty_GetRole($1)->_Value, $4);
}
| role '+' '=' role
{
	p(207);
	estradd(&Sociaty_GetRole($1)->_Value, Sociaty_GetRole($4)->_Value);
}
| role '=' '&' role
{
	if(Sociaty_GetRole($1)->_Value != NULL) free(Sociaty_GetRole($1)->_Value);

	Sociaty_GetRole($1)->_Value =
		Sociaty_GetRole($4)->_Value;
}

| role ':' role
{
  p(209);
  if(Sociaty_SearchPCRelation($1, $3) != 0){
    eerror("cannot inherent");
    exit(1);
  }
  Sociaty_AddPCRelation($3, $1);
}
| eval
{
  p(210);
	char *rtn;
	rtn = Eval($1);
#ifdef EDEBUG
	printf("%s\n", rtn);
#endif

	ParseExpressionFromString(rtn);
//	Eval(Sociaty_GetValue());
//	$$ = Expression_Create($1, NULL, Eval); 
}
;

eval
: role         {   p(301);$$ = $1; }
| role '(' ')' {  p(302); $$ = $1; }
| role argument_list
{
//TODO
	p(303); $$ = $1;
	IndexArray_PassBySymbol(&Sociaty_GetRole($1)->Args, &$2);
}
| role '(' argument_list ')'
{
//TODO
	p(304); $$ = $1;
  IndexArray_PassBySymbol(&Sociaty_GetRole($1)->Args, &$3);

}
;

role
: member
{
  p(401);
  $$ = $1;
}
| IDENTIFIER
{
  p(402);
	$$ = Sociaty_AddNewRole($1);	
}
/*
| role '[' CONSTANT ']'
{
	$$ = Sociaty_GetRole($1)->Elements.Values[atoi($3)];	
}
*/
;

member
: IDENTIFIER '.' IDENTIFIER
{
  p(501);
	int pi, ci;
	char *m;
  pi = Sociaty_AddNewRole($1);
	m = (char *)malloc(strlen($1) + strlen($3) + 3);
	sprintf(m, "%s.%s", $1, $3);
	ci = Sociaty_AddNewRole(m);
	Sociaty_AddSSRelation(pi, ci);
	$$ = ci;
}
| member '.' IDENTIFIER
{
  p(502);
	int pi, ci;
	char *m;
	char *n;
	n = Sociaty_GetRole($1)->_Name;
	m = (char *)malloc(strlen(n) + strlen($3) + 3);
	sprintf(m, "%s.%s", n, $3);
	ci = Sociaty_AddNewRole(m);
	Sociaty_AddSSRelation($1, ci);
	$$ = ci;
}
;
/*
idunit
: IDENTIFIER
| IDENTIFIER '[' CONSTANT ']'
;
*/
argument
: role { $$ = $1; }
| CONSTANT 
{
	$$ = Sociaty_AddConstRole($1);
}
| '*' {$$ = 0; }
;
argument_list
: argument 
{ 
	IndexArray_Create(&$$); 
	IndexArray_Add(&$$, $1); 
}
| argument_list ',' argument { $$ = $1; IndexArray_Add(&$$, $3); }
;

%%

	//void ParseExpressionFromString(Expression *expr, char *str){
void ParseExpressionFromFp(FILE *fp){
	char *content;
	content = ereadfile(fp);
	estraddeol(&content);
	ParseExpressionFromString(content);
//	free(fpath);
}
void ParseExpressionFromFile(char *fpath){
  char *content;
  FILE *ifp;
  if(fpath[0]){
    ifp=fopen(fpath,"r");
		ParseExpressionFromFp(ifp);
  }
  else{
    eerror("file not exist");
    exit(1);
  }
//  free(fpath);
}

void ParseExpressionFromString(char *str){
//	printf("\nParseExpressionFromString\n=====\n%s\n=====\n\n", str);
  yyscan_t scanner;
	current_scanner = scanner;
  YY_BUFFER_STATE state;
	if (yylex_init(&scanner)) {
    // couldn't initialize
		eerror("yylex_init failed");
    return;
  }
	state = yy_scan_string(str, scanner);
//	if (yyparse(&expr, scanner)) {
	if (yyparse(scanner)){
    // error parsing
		eerror("yyparse failed");
    exit(1);
  }
	yy_delete_buffer(state, scanner);
	yylex_destroy(scanner);
//	free(str);

}
