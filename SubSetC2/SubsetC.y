%{
	#include "SubSetC.h"
	#include <bits/stdc++.h>
	#include <string>
	using namespace std;
	int yyerror(string s);
	int temp_counter = 1,lable_counter = 1;
	extern FILE* yyout,*yyin;
	extern int yylex();
	struct Expression
	{
		string temp_name;
		string code;
		int type;// 1 for int, 2 for float
	};
	struct symbol Symbol_table[NHASH];
%}

%union
{
	struct symbol* s;
	int d;
	float f;
	struct Expression* e;
	int cmp,log,bit,assgn;
}


%left ';'
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

exp: {$$ = NULL;}
   |exp '+' exp {$$ = new Expression;$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$$->temp_name;$$->code+=" = ";$$->code+=$1->temp_name;$$->code+="+";$$->code+=$3->temp_name;}
   |exp '*' exp {$$ = new Expression;$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$$->temp_name;$$->code+=" = ";$$->code+=$1->temp_name;$$->code+="*";$$->code+=$3->temp_name;}
   |exp '-' exp {$$ = new Expression;$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$$->temp_name;$$->code+=" = ";$$->code+=$1->temp_name;$$->code+="-";$$->code+=$3->temp_name;}
   |exp '/' exp {$$ = new Expression;$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$$->temp_name;$$->code+=" = ";$$->code+=$1->temp_name;$$->code+="/";$$->code+=$3->temp_name;}
   |exp '%' exp {$$ = new Expression;$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$$->temp_name;$$->code+=" = ";$$->code+=$1->temp_name;$$->code+="%";$$->code+=$3->temp_name;}
   |exp '@' exp {$$ = new Expression;$$->temp_name = "t";$$->temp_name+=to_string(temp_counter++);$$->code = "";$$->code+=$1->code;$$->code+="\n";$$->code+=$3->code;$$->code+="\n";$$->code+=$$->temp_name;$$->code+=" = ";$$->code+=$1->temp_name;$$->code+="^";$$->code+=$3->temp_name;}
   |INT idlist {$2->type = 1;$$ = $2;}
   |FLOAT idlist {$2->type = 2;$$ = $2;}
   |ID {$$ = new Expression;$$->temp_name=$1->name;$$->type = $1->type;$$->code = "";}
   |ID ASSGN exp {$$ = new Expression;
	$$->code = "";
	$$->code+=$3->code;
	$$->code+="\n";switch($2)
   {
	
   	case 1:
   	$$->code+=$1->name;
   	$$->code+=" = ";
   	$$->code+=$3->temp_name;
   	break;
   	case 2:
   	$$->code+="t";
   	$$->code+=to_string(temp_counter);
   	$$->code+=" = ";
   	$$->code+=$1->name;
   	$$->code+="+";
   	$$->code+=$3->temp_name;
   	$$->code+=$1->name;
   	$$->code+=" = ";
   	$$->code+="t";
   	$$->code+=to_string(temp_counter++);
   	break;
   	case 3:
   	$$->code+="t";
   	$$->code+=to_string(temp_counter);
   	$$->code+=" = ";
   	$$->code+=$1->name;
   	$$->code+="-";
   	$$->code+=$3->temp_name;
   	$$->code+=$1->name;
   	$$->code+=" = ";
   	$$->code+="t";
   	$$->code+=to_string(temp_counter++);
   	break;
   	case 4:
   	$$->code+="t";
   	$$->code+=to_string(temp_counter);
   	$$->code+=" = ";
   	$$->code+=$1->name;
   	$$->code+="*";
   	$$->code+=$3->temp_name;
   	$$->code+=$1->name;
   	$$->code+=" = ";
   	$$->code+="t";
   	$$->code+=to_string(temp_counter++);
   	break;
   	case 5:
   	$$->code+="t";
   	$$->code+=to_string(temp_counter);
   	$$->code+=" = ";
   	$$->code+=$1->name;
   	$$->code+="/";
   	$$->code+=$3->temp_name;
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
   	$$ = new Expression;//strcpy($$->temp_name,t);
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
   	$$ = new Expression;//strcpy($$->temp_name,t);
   	if($1!=NULL)
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
   	$$ = new Expression;//strcpy($$->temp_name,t);
   	if($1!=NULL)
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
   |INTEGER {$$ = new Expression;$$->temp_name = to_string($1);
   $$->type = 1;cout<<"Number is ==***************"<<$1<<endl;}
   |REAL {$$ = new Expression;$$->temp_name = to_string($1);
   $$->type = 1;}
   |'(' exp ')' {$$ = $2;}
   ;
   
stmt: stmt ';' stmt {$$ = new Expression;if($3==NULL)
    $$ = $1;else {cout<<"Code1 = "<<$1->code<<"Code2 = "<<$3->code<<endl;$$->code = "";$$->code = $$->code+$1->code+"\n"+$3->code;}
    }
    | IF '(' exp ')' '{' stmt '}' ELSE '{' stmt '}' {
    	string label;
    	label="l";
    	label+=to_string(lable_counter++);
    	label+=": \n";
    	$$ = new Expression;
    	$$->code = "";
    	$$->code+=label;
    	$$->code=$$->code+$3->code+"\n";
    	$$->code+="if (";
    	$$->code+=$3->temp_name;
    	$$->code+=") == 0 goto ";
    	label = "l";
    	label+=to_string(lable_counter++);
    	//label+=": \n";
    	$$->code+=label;
    	$$->code+="\n";
    	$$->code=$$->code+$6->code+"\n";
    	$$->code = $$->code+"goto l"+to_string(lable_counter)+"\n";
    	label+=": \n";
    	$$->code+=label;
    	$$->code+=$10->code;
    	$$->code = $$->code+"\nl"+to_string(lable_counter++)+": \n";
    }
    | IF '(' exp ')' '{' stmt '}' 
    {
    	string label;
    	label="l";
    	label+=to_string(lable_counter++);
    	label+=": \n";
    	$$ = new Expression;
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
    	$$ = new Expression;
    	$$->code = "";
    	$$->code+=label1;
    	$$->code+=": \n";
    	$$->code=$$->code+$3->code+"\n";
    	$$->code+="if (";
    	$$->code+=$3->temp_name;
    	$$->code+=") == 0 goto ";
    	label2 = "l";
    	label2+=to_string(lable_counter++);
    	$$->code+=label2;
    	$$->code+="\n";
    	$$->code=$$->code+$6->code+"\n";
    	$$->code+="goto ";
    	$$->code+=label1;
    	$$->code+="\n";
    	label2+=": \n";
    	$$->code+=label2;
    }
    |FOR '(' exp ';' exp ';' exp ')' '{' stmt '}' 
    {
    	$$ = new Expression;
    	$$->code = "";
    	$$->code+=$3->code;
    	string label1,label2;
    	label1="l";
    	label1+=to_string(lable_counter++);
    	label2="l";
    	label2+=to_string(lable_counter++);
    	$$->code+=label1;
    	$$->code+=": \n";
    	$$->code=$$->code+$5->code+"\n";
    	$$->code=$$->code+"if ("+$5->temp_name+") == 0 goto "+label2+"\n"+$10->code+"\n"+$7->code+"\n";

    	$$->code = $$->code+"goto "+label1+"\n"+label2+": \n";
    }
    |exp {$$ = $1;}
    ;
idlist: ID {printf("Here\n");if($1!=NULL){cout<<"yes\n";}cout<<"Name = "<<$1->name<<endl;$$ = new Expression;$$->code = "";cout<<"Upto\n";$$->code = $$->code+string($1->name)+" = 0";cout<<"Code = "<<$$->code<<endl;}
      | ID','idlist {$$ = new Expression;$$->code = "";$$->code = $$->code+$1->name+" = 0\n";$$->code+=$3->code;}
      ;
calclist:  
	| MAIN '{' stmt '}' {fprintf(yyout,"%s",$3->code.c_str());};
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
		if(Symbol_table[h].name==NULL)
		{
			printf("Found at: %d",h);
			Symbol_table[h].name = (char*)malloc(sizeof(char)*20);
			strcpy(Symbol_table[h].name,s);
			q = &Symbol_table[h];
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
		if(Symbol_table[h].name==NULL)
		{
			return NULL;
		}
		else if(strcmp(Symbol_table[h].name,s)==0)
		{
			printf("Found at: %d",h);
			q = &Symbol_table[h];
			return q;
		}
		h = (h+1)%NHASH;
		t--;
	}
}

int main(int argc,char* argv[])
{
	for(int i=0;i<NHASH;i++)
	{
		Symbol_table[i].name = NULL;	
	}
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

int yyerror(string s)
{
	cout<<s;
	return 0;
}



   
   
   
   
   
   
   
   
   
   
   
