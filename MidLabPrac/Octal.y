%{
	#include "Octal.tab.h"
	#include <stdio.h>
	int yyerror(char* s);extern int yylex();
	int to_octal(int d);
%}


%token NUM EOL
%left '+' '-'
%left '*' '/'

%%

calclist: 
	| calclist exp EOL {printf(" = %d\n",to_octal($2));}
	;
exp: NUM {$$ = $1;}
   | exp '+' exp {$$ = $1+$3;}
   | exp '-' exp {$$ = $1-$3;}
   | exp '*' exp {$$ = $1*$3;}
   | exp '/' exp {$$ = $1/$3;}
   ;
%%
int yyerror(char* s)
{
	printf("ERROR: %s\n",s);
}
int to_octal(int d)
{
	int rtn = 0;
	while(d>0)
	{
		rtn = rtn*10+(d%8);
		d/=8;
	}
	int r = 0;
	while(rtn>0)
	{
		r = r*10+(rtn%10);
		rtn/=10;
	}
	return r;
}
int main()
{
	yyparse();
}
