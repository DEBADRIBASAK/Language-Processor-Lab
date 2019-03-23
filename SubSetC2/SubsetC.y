%{
	#include "SubSetC.h"
	#include <bits/stdc++.h>
	#include <string>
	using namespace std;
	int yyerror(char* s);
	int temp_counter = 1,label_counter = 1;
	FILE* yyout,*yyin;
	extern int yylex();
	struct Expression
	{
		string temp_name;
		string code;
		int type;// 1 for int, 2 for float
	};
%}

%union
{
	struct symbol* s;
	int d;
	float f;
	struct Expression* e;
	int cmp,log,bit,assgn;
}


%nonassoc ';'
%left <assgn> ASSGN
%left <cmp> CMP 
%left <log> LOG 
%left <bit> BIT
%left '+' '-'
%left '*' '/'
%right '@'
%left '%'

%token IF ELSE WHILE FOR
%token <s> ID 
%token <d> INTEGER
%token <f> REAL
%token INT FLOAT MAIN ERR
%nonassoc '(' ')' '{' '}'
%type <e> exp stmt idlist
%start calclist


%%

exp:  {$$ = NULL;}
   |exp '+' exp {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$1->temp_name;$$->code+="+";$$->code+=$3->temp_name;}
   |exp '*' exp {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$1->temp_name;$$->code+="*";$$->code+=$3->temp_name;}
   |exp '-' exp {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$1->temp_name;$$->code+="-";$$->code+=$3->temp_name;}
   |exp '/' exp {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$1->temp_name;$$->code+="/";$$->code+=$3->temp_name;}
   |exp '%' exp {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$1->temp_name;$$->code+="%";$$->code+=$3->temp_name;}
   |exp '@' exp {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$1->temp_name;$$->code+="*";$$->code+=$3->temp_name;}
   |INT idlist {$2->type = 1;}
   |FLOAT idlist {$2->type = 2;}
   |ID {$$ = (struct Expression*)malloc(sizeof(struct Expression));strcpy($$->temp_name,$1->name);$$->type = $1->type;}
   |ID ASSGN exp {switch($2)
   {
	$$ = (struct Expression*)malloc(sizeof(struct Expression));
	$$->code = "";
	$$->code+=$3->code;
	$$->code+="\n";
   	case 1:
   	$3->code+=$1->name;
   	$3->code+=" = ";
   	$$->code+=exp->temp_name;
   	break;
   	case 2:
   	$$->code+="t";
   	$$->code+=to_string(temp_counter);
   	$3->code+=" = ";
   	$3->code+=$1->name;
   	$3->code+="+";
   	$$->code+=exp->temp_name;
   	$$->code+=$1->name;
   	$$->code+=" = ";
   	$$->code+="t";
   	$$->code+=to_string(temp_counter++);
   	break;
   	case 3:
   	$$->code+="t";
   	$$->code+=to_string(temp_counter);
   	$3->code+=" = ";
   	$3->code+=$1->name;
   	$3->code+="-";
   	$$->code+=exp->temp_name;
   	$$->code+=$1->name;
   	$$->code+=" = ";
   	$$->code+="t";
   	$$->code+=to_string(temp_counter++);
   	break;
   	case 4:
   	$$->code+="t";
   	$$->code+=to_string(temp_counter);
   	$3->code+=" = ";
   	$3->code+=$1->name;
   	$3->code+="*";
   	$$->code+=exp->temp_name;
   	$$->code+=$1->name;
   	$$->code+=" = ";
   	$$->code+="t";
   	$$->code+=to_string(temp_counter++);
   	break;
   	case 5:
   	$$->code+="t";
   	$$->code+=to_string(temp_counter);
   	$3->code+=" = ";
   	$3->code+=$1->name;
   	$3->code+="/";
   	$$->code+=exp->temp_name;
   	$$->code+=$1->name;
   	$$->code+=" = ";
   	$$->code+="t";
   	$$->code+=to_string(temp_counter++);
   	break;
   	$$->code+="\n";
   }}
   |exp CMP exp {
   	string ch;
   	switch($2)
   	{
   		case 1:
   		ch = "==";
   		break;
   		case 2:
   		ch = ">";
   		break;
   		case 3:
   		ch = "<";
   		break;
   		case 4:
   		ch = ">=";
   		break;
   		case 5:
   		ch = "<=";
   		break;
   		case 6:
   		ch = "!=";
   		break;
   		
   	}
   	//char t[10];sprintf(t,"t%d",temp_counter++);
   	//fprintf(yyout,"%s = %s %s %s\n",t,$1->temp_name,ch,$3->temp_name);
   	$$ = (struct Expression*)malloc(sizeof(struct Expression));//strcpy($$->temp_name,t);
   	$$->code+=$1->code;
   	$$->code+=$3->code;
   	$$->temp_name = "t"+to_string(temp_counter++);
   	$$->code+=$$->temp_name;
   	$$->code+=" = ";
   	$$->code+=$1->temp_name;
   	$$->code+=ch;
   	$$->code+=$3->temp_name;
   	
   }
   |exp BIT exp {
   	string ch;
   	switch($2)
   	{
   		case 1:
   		ch = "|";
   		break;
   		case 2:
   		ch = "&";
   		break;
   		case 3:
   		ch = "~";
   		break;
   		
   	}
   	$$ = (struct Expression*)malloc(sizeof(struct Expression));//strcpy($$->temp_name,t);
   	$$->code+=$1->code;
   	$$->code+=$3->code;
   	$$->temp_name = "t"+to_string(temp_counter++);
   	$$->code+=$$->temp_name;
   	$$->code+=" = ";
   	if($1!=NULL)
   	$$->code+=$1->temp_name;
   	$$->code+=ch;
   	$$->code+=$3->temp_name;
   }
   |exp LOG exp {
   	string ch;
   	switch($2)
   	{
   		case 1:
   		ch = "&&";
   		break;
   		case 2:
   		ch = "||";
   		break;
   		case 3:
   		ch = "!";
   		break;
   		
   	}
   	$$ = (struct Expression*)malloc(sizeof(struct Expression));//strcpy($$->temp_name,t);
   	$$->code+=$1->code;
   	$$->code+=$3->code;
   	$$->temp_name = "t"+to_string(temp_counter++);
   	$$->code+=$$->temp_name;
   	$$->code+=" = ";
   	if($1!=NULL)
   	$$->code+=$1->temp_name;
   	$$->code+=ch;
   	$$->code+=$3->temp_name;
   }
   |INTEGER {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->temp_name = to_string($1);
   $$->type = 1;}
   |REAL {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->temp_name = to_string($1);
   $$->type = 1;}
   |'(' exp ')' {$$ = $2;}
   ;
   
stmt:stmt ';' stmt {$$ = (struct Expression*)malloc(sizeof(struct Expression));if($3==NULL)
    $$ = $1;else {$$->code = ""+$1->code+"\n"+$3->code;}
    }
    | IF '(' exp ')' '{' stmt '}' ELSE '{' stmt '}' {
    	string label;
    	label="l";
    	label+=to_string(lable_counter++);
    	label+=": \n";
    	$$ = (struct Expression*)malloc(sizeof(struct Expression));
    	$$->code = "";
    	$$->code+=label;
    	$$->code+="if (";
    	$$->code+=$3->temp_name;
    	$$->code+=") == 0 goto ";
    	label = "l";
    	label+=to_string(lable_counter++);
    	//label+=": \n";
    	$$->code+=label;
    	$$->code+="\n";
    	$$->code+=$6->code;
    	label+=": \n";
    	$$->code+=label;
    	$$->code+=$10->code;
    }
    | IF '(' exp ')' '{' stmt '}' 
    {
    	string label;
    	label="l";
    	label+=to_string(lable_counter++);
    	label+=": \n";
    	$$ = (struct Expression*)malloc(sizeof(struct Expression));
    	$$->code = "";
    	$$->code+=label;
    	$$->code+="if (";
    	$$->code+=$3->temp_name;
    	$$->code+=") == 0 goto ";
    	label = "l";
    	label+=to_string(lable_counter++);
    	$$->code+=label;
    	$$->code+="\n";
    	$$->code+=$6->code;
    	label+=": \n";
    	$$->code+=label;
    }
    | WHILE '(' exp ')' '{' stmt '}' 
    {
    	string label1,label2;
    	label1="l";
    	label1+=to_string(lable_counter++);
    	$$ = (struct Expression*)malloc(sizeof(struct Expression));
    	$$->code = "";
    	$$->code+=label;
    	$$->code+=": \n";
    	$$->code+="if (";
    	$$->code+=$3->temp_name;
    	$$->code+=") == 0 goto ";
    	label2 = "l";
    	label2+=to_string(lable_counter++);
    	$$->code+=label2;
    	$$->code+="\n";
    	$$->code+=$6->code;
    	$$->code+="goto "
    	$$->code+=label1;
    	$$->code+="\n";
    	label2+=": \n";
    	$$->code+=label2;
    }
    |FOR '(' exp ';' exp ';' exp ')' '{' stmt '}' 
    {
    	$$ = (struct Expression*)malloc(sizeof(struct Expression));
    	$$->code = "";
    	$$->code+=$3->code;
    	string label1,label2;
    	label1="l";
    	label1+=to_string(lable_counter++);
    	label2="l";
    	label2+=to_string(lable_counter++);
    	$$->code+=label1;
    	$$->code+=": \n";
    	$$->code+=$5->code;
    	$$->code=$$->code+"if ("+$5->temp_name+") == 0 goto "+label2+"\n"+$10->code;
    	$$->code+=$7->code;
    	$$->code = $$->code+"goto "+label1+"\n"+label2+": \n";
    }
    |exp {$$ = $1;}
    ;
idlist: ID {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->code = "";$$->code = $$->code+$1->name+" = 0";}
      | ID','idlist {$$ = (struct Expression*)malloc(sizeof(struct Expression));$$->code = "";$$->code = $$->code+$1->name+" = 0";$$->code+=$3->code;}
      ;
calclist:  
	| MAIN '{' stmt '}' {fprintf(yyout,"%s",stmt.c_str())};
	;

%%


int Hash(char* s)
{
	int n = strlen(s);
	int h = 0;
	for(int i=0;i<n;i++)
	{
		h = (h+(int)s[i]*(i+1))%NHASH;
	}
	return h;
}

struct symbol* insert(char* s)
{
	int h = Hash(s);
	int t = NHASH;
	struct symbol *q;
	while(t>0)
	{
		if(symbol_table[h].name==NULL)
		{
			strcpy(symbol_table[h].name,s);
			q = &s;
			return q;
		}
		h = (h+1)%NHASH;
		t--;
	}
	return NULL;
}

struct symbol* search(char* s)
{
	int h = Hash(s);
	int t = NHASH;
	struct symbol *q;
	while(t>0)
	{
		if(symbol_table[h].name==NULL)
		{
			return NULL;
		}
		else if(strcmp(symbol_table[h].name,s)==0)
		{
			q = &symbol_table[h];
			return q;
		}
		h = (h+1)%NHASH;
		t--;
	}
}

int main(int argc,char* argv[])
{
	yyin = fopen(argv[1],"r");
	if(yyin==NULL)
	{
		perror("Could not open");
		exit(0);
	}
	yyout = fopen("output.txt","w");
	yydebug = 1;
	yyparse();
	return 0;
}

int yyerror(char* s)
{
	printf("ERROR: %s\n",s);
	return 0;
}



   
   
   
   
   
   
   
   
   
   
   
