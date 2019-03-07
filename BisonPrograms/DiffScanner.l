%{
	#include <string.h>
	#include "Differentiate.tab.h"
%}

%%

[0-9]+ {yylval.term.s1 = strdup(yytext);yylval.term.s2 = strdup("0");return NUM;}
"x" {yylval.term.s1 = strdup(yytext);yylval.term.s2 = strdup("1");return X;}
"+" |
"*" |
"(" |
")" {return yytext[0];}
'\n' {return EOL;}

%%


