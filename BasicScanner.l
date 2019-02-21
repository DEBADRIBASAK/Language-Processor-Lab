%option noyywrap
%{
   #include "BisonPractice.tab.h"
%}

%%

[0-9]+ { yylval = atoi(yytext); return NUM;}
"+" |
"-" |
"*" |
"@" |
"/" { return yytext[0]; }

\n {return EOL;}

%%
