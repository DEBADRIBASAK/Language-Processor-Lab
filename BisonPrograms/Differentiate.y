%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "Differentiate.tab.h"
	struct Pair
	{
		char s1[50],s2[50];
	};
%}

%union{
	struct Pair term;
}
%token EOL
%token '+' '*' '(' ')'
%token <term> NUM X
%type <term> expr

%%

calclist:
	| calclist expr EOL {printf("Differentiated: %s\n",$2.s2);}
	;

expr:NUM {strcpy($$.s1,"( ");strcpy($$.s2,"( ");}
    | '(' expr ')' {strcpy($$.s1,"( ");strcat($$.s1,$2.s1);strcat($$.s1," )");strcpy($$.s2,"( ");strcat($$.s2,$2.s2);strcat($$.s2," )");}
    | expr '+' expr {strcpy($$.s1,"( ");strcat($$.s1,$1.s1);strcat($$.s1," + ");strcat($$.s1,$3.s1);strcat($$.s1," )");
    			strcpy($$.s1,"( ");strcat($$.s2,$1.s2);strcat($$.s2," + ");strcat($$.s2,$3.s2);strcat($$.s2," )");
    			}
    | expr '*' expr  {strcpy($$.s1,"( ");strcat($$.s1,$1.s1);strcat($$.s1," * ");strcat($$.s1,$3.s1);strcat($$.s1," )");
    			strcpy($$.s1,"( ");strcat($$.s2,$1.s2);strcat($$.s2," * ");strcat($$.s2,$3.s1);strcat($$.s2," + ");strcat($$.s2,$1.s1);strcat($$.s2," * ");strcat($$.s2,$3.s2);strcat($$.s2," )");
    			}
    ;
