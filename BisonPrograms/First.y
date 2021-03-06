/* first attempt of writing a Bison Code */
%{
#include <stdio.h>
%}

/* declare tokens */

%left ADD 
%left MUL 
%token NUMBER
%token OPBR CLBR
%token EOL


%%

calclist:			/* nothing */
	| calclist exp EOL { printf(" = %d\n",$2); }
	;
exp: factor
   | exp ADD factor { $$ = $1+$3; }
  // | exp SUB factor { $$ = $1-$3;}
   ;

factor: term
      | factor MUL term { $$ = $1* $3;}
     // | factor DIV term { $$ = $1/$3;}
      ;
term: NUMBER
    | OPBR exp CLBR { $$ = $2; }
    ;

%%

int main(int argc,char* argv[])
{
	yydebug = 1;
	yyparse();
	return 0;
}

yyerror(char* s)
{
	fprintf(stderr,"error: %s\n",s);
}
