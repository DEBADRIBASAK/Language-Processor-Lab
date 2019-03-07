%option noyywrap

%x DECLARATION

%{
	enum yytokentype
  {
    MAIN = 258,
    DATATYPE = 259,
    ID = 260,
    INTEGER = 261,
    FLOAT = 262,
    ERR = 263,
    LOG = 264,
    ASSGN = 265,
    BIT = 266,
    CMP = 267,
    IF = 268,
    ELSE = 269,
    FOR = 270,
    WHILE = 271
  };
%}
digit [0-9]
ws [ \t\n]



%%

"main()" {return MAIN;}

"int" {return DATATYPE;}
"float" {return DATATYPE;} //datatypes

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

"{" {return '{';}
"}" {return '}';}


"=" {return ASSGN;}
"+=" {return ASSGN;}
"-=" {return ASSGN;}
"*=" {return ASSGN;}
"/=" {return ASSGN;} // assignment operators

">" {return CMP;}
"<" {return CMP;}
">=" {return CMP;}
"<=" {return CMP;}
"==" {return CMP;}
"!=" {return CMP;} // relational operTORS

"||" {return LOG;}
"&&" {return LOG;}
"!" {return LOG;} //logical operators

"|" {return BIT;}
"&" {return BIT;}
"~" {return BIT;} //bitwise operator

{digit}+ {return INTEGER;}
\+{digit}+ {return INTEGER;}
\-{digit}+ {return INTEGER;}
{digit}+\.{digit}+ {return FLOAT;} // numbers, signed or unsigned int and float (expressed as num.num)

<DECLARATION>[a-zA-Z][a-z0-9A-Z\_]* {return ID;}
[a-zA-Z][a-z0-9A-Z\_]* {return ID;}

<DECLARATION>"," // ignore commas in declaration section
<DECLARATION>{ws}+ // ignore whitespaces in declaration section

";" {BEGIN INITIAL;return yytext[0];}
{ws}* {/*ignore it*/}
%%
int main(int argc,char* argv[])
{
	yyin = fopen(argv[1],"r");
	int tok;
	while(tok=yylex())
	{
		printf("%d ",tok);
	}
	return 0;
}

