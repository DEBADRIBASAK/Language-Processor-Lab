/* Scanner for the calculator */
%option noyywrap nodefault yylineno
%{
 #include "DeskCalc.tab.h"
#include "DeskCalc.h"
%}

expo ([Ee][-+]?[0-9]+)

%%


">" { yylval.fn = 1; return CMP;}
"<" { yylval.fn = 2; return CMP;}
"<>" { yylval.fn = 3; return CMP;}
"==" { yylval.fn = 4; return CMP;}
">=" { yylval.fn = 5; return CMP;}
"<=" { yylval.fn = 6; return CMP;}

"if" { return IF;}
"then" { return THEN; }
"else" { return ELSE; }
"while" {return WHILE; }
"do" {return DO; }
"let" {return LET;}
"display" {return DISPLAY;}

"sqrt" {yylval.fn = B_sqrt; return FUNC;}
"exp" {yylval.fn = B_exp; return FUNC;}
"log" {yylval.fn = B_log; return FUNC;}
"print" {yylval.fn = B_print; return FUNC;}

"um" { return UM; }
[a-zA-Z][a-zA-Z0-9]* {yylval.s = lookup(yytext); return NAME;}


[0-9]+"."[0-9]*{expo}? |
"."?[0-9]+{expo}? { yylval.d = atof(yytext); return NUM;}


"//".*
[ \t]+ /* ignore comments and whitespaces */

\\\n { printf("c> "); }

"+" { return ADD;}
"-" { return SUB;}
"*" { return MUL; }
"/" { return DIV; }
"@" { return EXP; }
"|" {return ABS; }
"(" {return OPBR; }
")" {return CLBR; }
"=" {return EQU; }
";" |
"," {return yytext[0]; }

. { yyerror("Mystery character");}
\n { return EOL; }

%%
