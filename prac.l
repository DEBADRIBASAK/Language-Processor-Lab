%option noyywrap
%{
	#include "prac.tab.h"
%}
%%

[0-9]+ {yylval.d = atoi(yytext);return NUM;}
"*" {return '*';}
. {}
\n {return EOL;}
%%
