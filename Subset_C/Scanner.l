%option noyywrap

%x DECLARATION


%{
	#include "SubSet.h"
	#include "SubsetC.tab.h"
	int scope = 1,curr_scope = 0,store_scope = 0,type = 0; //type is integer by default
%}
digit [0-9]
ws [ \t\n]



%%

"main()" {return MAIN;}

"int" {BEGIN DECLARATION;type = 0;yylval.dt = 1;return DATATYPE;}
"float" {BEGIN DECLARATION;type = 1;yylval.dt = 2;return DATATYPE;} //datatypes

"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" { return WHILE; } //control flow

"+" |
"-" |
"*" |
"/" |
"@" |
"(" |
")" |
"?" |
":" |
"%" {return yytext[0];} //arthmatic operators

"{" {/*store_scope = scope;scope = ++curr_scope;*/return '{';}
"}" {/*scope = store_scope;*/return '}';}


"=" {yylval.assfn = 1;return ASSGN;}
"+=" {yylval.assfn = 2;return ASSGN;}
"-=" {yylval.assfn = 3;return ASSGN;}
"*=" {yylval.assfn = 4;return ASSGN;}
"/=" {yylval.assfn = 5;return ASSGN;} // assignment operators

">" {yylval.fn = 1;return CMP;}
"<" {yylval.fn = 2;return CMP;}
">=" {yylval.fn = 3;return CMP;}
"<=" {yylval.fn = 4;return CMP;}
"==" {yylval.fn = 5;return CMP;}
"!=" {yylval.fn = 6;return CMP;} // relational operTORS

"||" {yylval.logfn = 1;return LOG;}
"&&" {yylval.logfn = 2;return LOG;}
"!" {yylval.logfn = 3;return LOG;} //logical operators

"|" {yylval.bitfn = 1;return BIT;}
"&" {yylval.bitfn = 2;return BIT;}
"~" {yylval.bitfn = 3;return BIT;} //bitwise operator

{digit}+ {yylval.i = atoi(yytext);return INTEGER;}
\+{digit}+ {yylval.i = atoi(yytext+1);return INTEGER;}
\-{digit}+ {yylval.i = (-1)*atoi(yytext+1);return INTEGER;}
{digit}+\.{digit}+ {yylval.d = atof(yytext);return FLOAT;} // numbers, signed or unsigned int and float (expressed as num.num)

<DECLARATION>[a-zA-Z][a-z0-9A-Z\_]* {yylval.s = search(yytext,scope); if(yylval.s==NULL)
						{
						printf("Not declared previously\n");
						yylval.s = insert_into_symbol_table(yytext);
						yylval.s->type = type;
						yylval.s->scope = scope;return ID;}
						else
						{printf("Case kore6e--1!\n"); yylval.errfn = 1;return ERR;}}
[a-zA-Z][a-z0-9A-Z\_]* {yylval.s = search(yytext,scope); if(yylval.s!=NULL){return ID;}else{printf("Case kore6e!\n");yylval.errfn = 2;return ERR;}}

<DECLARATION>"," // ignore commas in declaration section
<DECLARATION>{ws}+ // ignore whitespaces in declaration section
<DECLARATION>";" {BEGIN INITIAL; return ';';}

";" { type = 0;return yytext[0];}
{ws}* {/*ignore it*/}
%%


