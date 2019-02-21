%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	int yyerror(char* s);
	extern int yylex();
%}

%token NUM EOL
%left '+' '-'
%left '*' '/'
%right '@'

%%

calclist: 
	| calclist exp EOL {printf("The value is: %d\n",$2);}
	;
exp: NUM
   | exp '*' exp { $$ = $1*$3;}
   | exp '/' exp { $$ = $1/$3;}
   | exp '+' exp { $$ = $1+$3;}
   | exp '-' exp { $$ = $1-$3;}
   | exp '@' exp {$$ = (int)pow($1,$3);}
   ;
%%

int main()
{
 	yyparse();
	return 0;
}
int yyerror(char* s)
{
	printf("ERROR: %s\n",s);
	return 0;
}
