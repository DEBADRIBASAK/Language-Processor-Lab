%option noyywrap
%{
	#include "BackPatch.tab.h"
%}

ws [ \t\n]
digit [0-9]
letter [a-zA-Z]

%%

"if" { return IF; }
"else" {return ELSE; }
"while" {return WHILE; }
"main()" {return MAIN;}
{digits}+ { yylval.d = atoi(yytext);return INTEGER; }
{letter}+ {yylval.idname = strcup(yytext);return ID;}

"==" {yylval.cmp = 1; return CMP;}
">" {yylval.cmp = 2; return CMP;}
">=" {yylval.cmp = 3; return CMP;}
"<" {yylval.cmp = 4; return CMP;}
"<=" {yylval.cmp = 5; return CMP;}
"!=" {yylval.cmp = 6; return CMP;}

"&&" {yylval.log = 1;return LOG;}
"||" {yylval.log = 2;return LOG; }
"!" {yylval.log = 3;return LOG;}

"=" {yylval.assgn = 1;return ASSGN;}
"+=" {yylval.assgn = 2;return ASSGN;}
"-=" {yylval.assgn = 3;return ASSGN;}
"*=" {yylval.assgn = 4;return ASSGN;}
"/=" {yylval.assgn = 5;return ASSGN;}

"+" |
"-" |
"*" |
"/" |
"%" |
";" |
"(" |
")" |
"{" |
"}" |
"," {return yytext[0];}



{ws}+ {}
