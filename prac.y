%{
	#include "prac.tab.h"
	#include <stdio.h>
	struct str
	{
		int syn,inh;
	};
	extern int yylex();
	extern FILE* yyin;
	int yyerror(char* s);
%}
%union
{
	struct str* e;
	int d;
}
%token <d> NUM
%token EOL
%left '*'
%type <e> T T1
%type <d> F
%%

calclist: 
	| calclist T EOL {printf("Result is = %d\n",$2->syn);}
	;
T: F T1 {$$ = (struct str*)malloc(sizeof(struct str));$2->inh = $1;$$->syn = $2->syn;}
  ;
  
T1 : '*' F T1 {$$ = (struct str*)malloc(sizeof(struct str));$3->inh = $$->inh*$2;$$->syn = $3->syn;}
   |  {$$ = (struct str*)malloc(sizeof(struct str));$$->syn = $$->inh;}
   ;
F: NUM {$$ = $1;}
  ;
%% 
int main()
{
	yydebug = 1;
	yyparse();
	return 0;
}

int yyerror(char* s)
{
	return 0;
}

