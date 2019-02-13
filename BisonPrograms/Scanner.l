/* helper flex program */
%option noyywrap
%{
#include "First.tab.h"
%}

%%

"+" { return ADD; }
"*" {return MUL;}
"(" {return OPBR; }
")" {return CLBR;}
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
\n {return EOL; }
[ \t] /* ignore */
. { printf("Mystery character\n"); }
%%
