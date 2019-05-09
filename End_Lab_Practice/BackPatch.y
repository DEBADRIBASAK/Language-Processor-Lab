%{
	#include "BackPatch.tab.h"
	#include <bits/stcd++.h>
	#include <fstream>
	struct lnode
	{
		int lineno;
		struct lnode* next;
	};
	struct Expr
	{
		string place;
		struct lnode* true_list,false_list,next_list;
	};
	struct Sentinel
	{
		int q;
	};
	extern int yylex();
	int yyerror(char* s);
	extern FILE* yyin;
	ofstream fout;
	int lineno,temp_counter;
	void backpatch(struct lnode* l,int lno);
	struct lnode* makelist();
	struct lnode* merge(struct lnode* l1,struct lnode* l2);
	string new_temp();
%}

%union
{
	char* idname;
	int cmp,log,assgn;
	struct Expr* e;
	struct Sentinel* M;
	int d;
}

%left '+' '-'
%left '*' '/' '%'
%token ',' ';' IF ELSE WHILE MAIN
%token <assgn> ASSGN
%token <log> LOG
%token <cmp> CMP
%token <d> INTEGER
%type <e> expr n_sent stmt idlist
%type <M> sent
%start calclist


%%

exp: { $$ = NULL; }
   | exp '+' exp {$$ = new Expr; $$->truelist = NULL;$$->falselist = NULL;$$->nextlist = NULL;
   $$->place = new_temp(); fout<<lineno<<" : "<<$$->place<<" = "<<$1->place<<" + "<<$3->place<<endl;lineno++;}
   | exp '-' exp { $$ = new Expr; $$->truelist = NULL;$$->falselist = NULL;$$->nextlist = NULL;
   $$->place = new_temp(); fout<<lineno<<" : "<<$$->place<<" = "<<$1->place<<" - "<<$3->place<<endl;lineno++;}
   | exp '*' exp { $$ = new Expr; $$->truelist = NULL;$$->falselist = NULL;$$->nextlist = NULL;
   $$->place = new_temp(); fout<<lineno<<" : "<<$$->place<<" = "<<$1->place<<" * "<<$3->place<<endl;lineno++;}
   | exp '/' exp { $$ = new Expr; $$->truelist = NULL;$$->falselist = NULL;$$->nextlist = NULL;
   $$->place = new_temp(); fout<<lineno<<" : "<<$$->place<<" = "<<$1->place<<" / "<<$3->place<<endl;lineno++;}
   | exp '%' exp { $$ = new Expr; $$->truelist = NULL;$$->falselist = NULL;$$->nextlist = NULL;
   $$->place = new_temp(); fout<<lineno<<" : "<<$$->place<<" = "<<$1->place<<" % "<<$3->place<<endl;lineno++;}
   | exp CMP exp {
   	string ch;
   	switch($2)
   	{
   		case 1:
   		ch = "==";break;
   		case 2:
   		ch = ">";break;
   		case 3:
   		ch = ">=";break;
   		case 4:
   		ch = "<";break;
   		case 5:
   		ch = "<=";break;
   		case 6:
   		ch = "!=";break;
   	}
   	$$ = new Expr;
   	fout<<lineno<<" : "<<"if"<<$1->place<<" "<<ch<<" "<<$3->place<<" goto";
   	$$->truelist = makelist();
   	fout<<"    \n";lineo++;
   	fout<<lineno<<" : "<<"goto";
   	$$->falselist = makelist();
   	fout<<"    \n";lineno++;	
   }
   | exp LOG sent exp {
   	$$ = new Expr;
   	switch($2)
   	{
   		case 1:
   		backpatch($1->truelist,$3->q);
   		$$->truelist = $4->truelist;
   		$$->falselist = merge($1->falselist,$4->falselist);
   		break;
   		case 2:
   		backpatch($1->falselist,$3->q);
   		$$->falselist = $4->falselist;
   		$$->truelist = merge($1->truelist,$4->truelist);
   		break;
   		case 3:
   		
   	}
   }

%%
