/* this is an octal calculator*/

%option noyywrap nodefault
%{
	#include "Octal.tab.h"
	int change_to_num(char* s);
%}

%%

[0-7]+ {yylval = change_to_num(yytext);return NUM;}
"+" |
"-" |
"*" |
"/" {return yytext[0];}

\n {return EOL;}

%%

int change_to_num(char *s)
{
	int rtn = 0;
	while(*s!='\0')
	{
		rtn = rtn*8+(*s-'0');s++;
	}
	return rtn;
}


