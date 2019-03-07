%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char* s);
%}
%left '+' '-'
%left '*' '/'
%right '@'
%token NUM EOL

%%
calclist:
	| calclist exp EOL {printf("\n");}
exp: NUM {printf("%d ",$1);}
   | exp '+' exp {printf("+ ");}
   | exp '-' exp {printf("- ");}
   | exp '*' exp {printf("* ");}
   | exp '/' exp {printf("/ ");}
   | exp '@' exp {printf("^ ");}
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
