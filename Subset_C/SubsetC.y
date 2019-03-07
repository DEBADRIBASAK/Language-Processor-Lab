%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "SubSet.h"
	extern int yylineno;
	extern int yylex();
	extern FILE *yyin,*yyout;
	int yyerror(char* s);
	
int varcounter = 1,labelcounter = 1;
struct symbol_table tab[NHASH];
char label[10] = {'L','\0'};
char temp_var[10] = {'t','\0'};
%}

%union
{
	struct ast* a;
	double d;
	struct symbol_table *s;
	int assfn,logfn,bitfn,i,errfn,fn,dt;
}

%token MAIN
%token <dt> DATATYPE
%token <s> ID
%token <i> INTEGER
%token <d> FLOAT
%token <errfn> ERR
%token <logfn> LOG
%token <assfn> ASSGN
%token <bitfn> BIT
%token <fn> CMP
%token IF ELSE FOR WHILE
%nonassoc '?' ':'
%left '+' '-'
%left '*' '/'
%left '%'
%right '@'
%nonassoc '(' ')' '{' '}'
%token ';'
%type <a> exp stmt 

%start calclist

%%
   
   
// rules are to be added  

exp: INTEGER {$$ = newnum('N',1,(double)$1);}
   | FLOAT {$$ = newnum('N',2,$1);}
   | ID {$$ = newref('R',$1);}
   | exp '+' exp {$$ = newast('+',$1,$3);}
   | exp '-' exp {$$ = newast('-',$1,$3);}
   | exp '*' exp {$$ = newast('*',$1,$3);}
   | exp '/' exp {$$ = newast('/',$1,$3);}
   | exp '@' exp {$$ = newast('@',$1,$3);}
   | exp '%' exp {$$ = newast('%',$1,$3);}
   | exp '?' stmt ':' stmt {$$ = newflow('I',2,$1,$3,$5,NULL,NULL);}
   | exp LOG exp {$$ = newlog('L',$2,$1,$3);}
   | LOG exp {$$ = newlog('L',$1,NULL,$2);}
   | exp CMP exp {$$ = newcmp('C',$2,$1,$3);}
   | exp BIT exp {$$ = newbit('B',$2,$1,$3);}
   | BIT exp {$$ = newlog('B',$1,NULL,$2);}
   | ID ASSGN exp {$$ = newassgn('A',$2,$1,$3);}
   ;


stmt: MAIN '{' stmt '}' {$$ = $3;}//the last part of generation after preparing the ast
    | DATATYPE ID ';' stmt { $$ = newast('S',newassgn('A',1,$2,newnum('N',1,0.0)),$4); }
    | exp ';' stmt { 
    			if($3==NULL)
    			$$ = $1;
    			else
    			$$ = newast('S',$1,$3);
    		   }
    | IF '(' exp ')' '{' stmt '}' { $$ = newflow('I',1,$3,$6,NULL,NULL,NULL);}
    | IF '(' exp ')' '{' stmt '}' ELSE '{' stmt '}' {$$ = newflow('I',2,$3,$6,$10,NULL,NULL);}
    | WHILE '(' exp ')' '{' stmt '}' {$$ = newflow('W',1,$3,$6,NULL,NULL,NULL);}
    | FOR '(' exp ';' exp ';' exp ')' '{' stmt '}' {$$ = newflow('F',2,$5,$10,NULL,$3,$7);}
    | ERR stmt { yyerror("One error ocurred");}
    | exp ';' {$$ = $1;}
    ;
calclist:
	| calclist stmt {generate_code($2);}
   
%%

int hash(char* s)
{
	int n = strlen(s);
	int h = 0;
	for(int i=0;i<n;i++)
	{
		h = (h+((int)s[i])*(i+1))%NHASH;
	}
	return h;
}

struct symbol_table* insert_into_symbol_table(char* s)
{
	int h = hash(s),i;
	printf("Hash: %d\n",h);
	i = h;int lookups = NHASH;
	struct symbol_table* sp;
	sp = &tab[h];
	while(lookups--)
	{
		if(sp->type==-1)
		{
			printf("Inserting at: %d\n",i);
			sp->name = (char*)malloc(sizeof(char));
			strcpy(sp->name,s);
			return sp;
		}
		i = (i+1)%NHASH;
		sp++;
		if(sp>=tab+NHASH)
		sp = tab;
	}
	return NULL;
}

struct symbol_table* search(char* s,int scope)
{
//	printf("Here\n");
	int h = hash(s);
	//printf("Here\n");
	int i =h,lookups = NHASH;
	struct symbol_table* sp;
	sp = &tab[h];
	while(lookups--)
	{
		//printf("*\n");
		if(sp->type==-1)
		{
			printf("Returning\n");
			return NULL;
		}
		else if(sp->scope==scope&&strcmp(sp->name,s)==0)
		{
			printf("Found at: %d\n",i);
			return sp;
		}
		i = (i+1)%NHASH;
		sp++;
		if(sp>=tab+NHASH)
		sp = tab;
	}
	//printf("Returning\n");
	return NULL;
}

struct ast* newast(int nodetype,struct ast* l,struct ast* r)
{
	struct ast* a = (struct ast*)malloc(sizeof(struct ast));
	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}

struct ast* newnum(int nodetype,int type,double val)
{
	struct num* a = (struct num*)malloc(sizeof(struct num));
	a->nodetype = nodetype;
	a->type = type;
	a->val = val;
	return (struct ast*)a;
}

struct ast* newref(int nodetype,struct symbol_table* s)
{
	struct ref* a = (struct ref*)malloc(sizeof(struct ref));
	a->nodetype = nodetype;
	a->s = s;
	return (struct ast*)a;
}

struct ast* newassgn(int nodetype,int type,struct symbol_table* s,struct ast* t)
{
	struct assgn* a = (struct assgn*)malloc(sizeof(struct assgn));
	a->nodetype = nodetype;
	a->type = type;
	a->sym = s;
	a->s = t;
	return (struct ast*)a;
}

struct ast* newcmp(int nodetype,int type,struct ast* exp,struct ast* s)
{
	struct cmpnode* a = (struct cmpnode*)malloc(sizeof(struct cmpnode));
	a->nodetype = nodetype;
	a->type = type;
	a->l = exp;
	a->r = s;
	return (struct ast*)a;
}

struct ast* newflow(int nodetype,int type,struct ast* cond,struct ast* s,struct ast* e,struct ast* init,struct ast *inc)
{
	struct flow* a = (struct flow*)malloc(sizeof(struct flow));
	a->nodetype = nodetype;
	a->type = type;
	a->cond = cond;
	a->s = s;
	a->e = e;
	a->init = init;
	a->inc = inc;
	return (struct ast*)a;
}

struct ast* newbit(int nodetype,int type,struct ast* l,struct ast* r)
{
	struct bitwise* a = (struct bitwise*)malloc(sizeof(struct bitwise));
	a->nodetype = nodetype;
	a->type = type;
	a->l = l;
	a->r = r;
	return (struct ast*)a;
}

struct ast* newlog(int nodetype,int type,struct ast* l,struct ast* r)
{
	struct logical* a = (struct logical*)malloc(sizeof(struct logical));
	a->nodetype = nodetype;
	a->type = type;
	a->l = l;
	a->r = r;
	return (struct ast*)a;
}


char* generate_code(struct ast* a)
{
	if(a==NULL)
	return NULL;
	int st;
	char* rtn = (char*)malloc(sizeof(char)*50);
	char* s = (char*)malloc(sizeof(char)*50);
	char* l = (char*)malloc(sizeof(char)*50);
	char* r = (char*)malloc(sizeof(char)*50);
	switch(a->nodetype)
	{
		case 'N': // just a number
		
		if(((struct num*)a)->type==1)
		sprintf(rtn," %d",(int)((struct num*)a)->val);
		else
		sprintf(rtn," %f",((struct num*)a)->val);
		break;
		
		case 'R':
		sprintf(rtn," %s",((struct ref*)a)->s->name);
		break;
		
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '@':
		
		l = strdup(generate_code(a->l));
		r = strdup(generate_code(a->r));
		sprintf(s,"%s",temp_var);
		sprintf(s+strlen(s),"%d = ",varcounter);
		sprintf(rtn,"%s",temp_var);
		sprintf(rtn+strlen(rtn),"%d",varcounter);
		varcounter++;
		sprintf(s+strlen(s),"%s ",l);
		l[0] = a->nodetype;
		l[1] = '\0';
		sprintf(s+strlen(s),"%s ",l);
		sprintf(s+strlen(s),"%s",r);
		break;
		
		case 'C':
		
		l = strdup(generate_code(((struct cmpnode*)a)->l));
		r = strdup(generate_code(((struct cmpnode*)a)->r));
		sprintf(s,"%s",temp_var);
		sprintf(s+strlen(s),"%d = ",varcounter);
		sprintf(rtn,"%s",temp_var);
		sprintf(rtn+strlen(rtn),"%d",varcounter);
		sprintf(s+strlen(s),"%s",l);
		if(((struct cmpnode*)a)->type==1)
		sprintf(s+strlen(s)," > ");
		else if(((struct cmpnode*)a)->type==2)
		sprintf(s+strlen(s)," < ");
		else if(((struct cmpnode*)a)->type==3)
		sprintf(s+strlen(s)," >= ");
		else if(((struct cmpnode*)a)->type==4)
		sprintf(s+strlen(s)," <= ");
		else if(((struct cmpnode*)a)->type==5)
		sprintf(s+strlen(s)," == ");
		else if(((struct cmpnode*)a)->type==6)
		sprintf(s+strlen(s)," != ");
		
		sprintf(s+strlen(s),"%s",r);
		break;
		
		case 'L':
		if(((struct logical*)a)->l!=NULL)
		l = strdup(generate_code(((struct logical*)a)->l));
		r = strdup(generate_code(((struct logical*)a)->r));
		sprintf(s,"%s",temp_var);
		sprintf(s+strlen(s),"%d = ",varcounter);
		sprintf(rtn,"%s",temp_var);
		sprintf(rtn+strlen(rtn),"%d = ",varcounter);
		if(((struct logical*)a)->l!=NULL)
		sprintf(s+strlen(s),"%s",l);
		if(((struct logical*)a)->type==1)
		sprintf(s+strlen(s)," || ");
		else if(((struct logical*)a)->type==2)
		sprintf(s+strlen(s)," && ");
		else if(((struct logical*)a)->type==3)
		sprintf(s+strlen(s)," ! ");
		sprintf(s+strlen(s),"%s",r);
		break;
		
		case 'B':
		if(((struct bitwise*)a)->l!=NULL)
		l = strdup(generate_code(((struct bitwise*)a)->l));
		r = strdup(generate_code(((struct bitwise*)a)->r));
		sprintf(s,"%s",temp_var);
		sprintf(s+strlen(s),"%d = ",varcounter);
		sprintf(rtn,"%s",temp_var);
		sprintf(rtn+strlen(rtn),"%d = ",varcounter);
		if(((struct bitwise*)a)->l!=NULL)
		sprintf(s+strlen(s),"%s",l);
		if(((struct bitwise*)a)->type==1)
		sprintf(s+strlen(s)," | ");
		else if(((struct bitwise*)a)->type==2)
		sprintf(s+strlen(s)," & ");
		else if(((struct bitwise*)a)->type==3)
		sprintf(s+strlen(s)," ~ ");
		sprintf(s+strlen(s),"%s",r);
		break;
		
		case 'A':
		printf("Assignment operation: %s\n",((struct assgn*)a)->sym->name);
		r = strdup(generate_code(((struct assgn*)a)->s));
		sprintf(s,"%s",((struct assgn*)a)->sym->name);
		sprintf(rtn,"%s",((struct assgn*)a)->sym->name);
		sprintf(s+strlen(s)," = ");
		// few lines are to be added
		
		if(((struct assgn*)a)->type==2)
		sprintf(s+strlen(s),"%s + ",((struct assgn*)a)->sym->name);
		else if(((struct assgn*)a)->type==3)
		sprintf(s+strlen(s),"%s - ",((struct assgn*)a)->sym->name);
		else if(((struct assgn*)a)->type==4)
		sprintf(s+strlen(s),"%s * ",((struct assgn*)a)->sym->name);
		else if(((struct assgn*)a)->type==5)
		sprintf(s+strlen(s),"%s / ",((struct assgn*)a)->sym->name);
		sprintf(s+strlen(s),"%s",r);
		
		break;
		
		case 'I': // now the tricky part!!!
		//char* sto = (char*)malloc(sizeof(char)*10);
		st = labelcounter;
		l = strdup(generate_code(((struct flow*)a)->cond));
		fprintf(yyout,"L%d: \n",labelcounter);
		fprintf(yyout,"if (%s) goto L%d\ngoto L%d\nL%d: \n",l,labelcounter+1,labelcounter+2,labelcounter+1);
		generate_code(((struct flow*)a)->s);
		fprintf(yyout,"L%d: ",labelcounter+2);
		labelcounter+=2;
		if(((struct flow*)a)->e!=NULL)
		{
			generate_code(((struct flow*)a)->e);
		}
		break;
		
		case 'W':
		st = labelcounter;
		l = strdup(generate_code(((struct flow*)a)->cond));
		fprintf(yyout,"L%d: \n",labelcounter);
		fprintf(yyout,"if (%s) goto L%d\ngoto L%d\nL%d: \n",l,labelcounter+1,labelcounter+2,labelcounter+1);
		generate_code(((struct flow*)a)->s);
		fprintf(yyout,"goto L%d\n",st);
		fprintf(yyout,"L%d: ",labelcounter+2);
		labelcounter+=2;
		break;
		
		case 'F':
		generate_code(((struct flow*)a)->init);
		st = labelcounter;
		fprintf(yyout,"L%d: \n",labelcounter);
		l = strdup(generate_code(((struct flow*)a)->cond));
		fprintf(yyout,"if (%s) goto L%d\ngoto L%d\nL%d: \n",l,labelcounter+1,labelcounter+2,labelcounter+1);
		generate_code(((struct flow*)a)->s);
		generate_code(((struct flow*)a)->inc);
		fprintf(yyout,"goto L%d\n",st);
		fprintf(yyout,"L%d: ",labelcounter+2);
		labelcounter+=2;
		break;
		
		case 'S':
		generate_code(a->l);
		generate_code(a->r);
		break;
	}
	if(a->nodetype!='N'&&a->nodetype!='R'&&a->nodetype!='I'&&a->nodetype!='F'&&a->nodetype!='W'&&a->nodetype!='S')
	{
		fprintf(yyout,"%s\n",s);
	}
	return rtn;
}


int main(int argc,char *argv[])
{
	for(int i=0;i<NHASH;i++)
	{
		tab[i].type = -1;
		tab[i].scope = -1;
		tab[i].name = NULL;
		tab[i].val = 0;
	}
	yydebug = 1;
	if(argc!=2)
	{
		printf("Number of input files not proper");
		exit(0);
	}
	yyin = fopen(argv[1],"r");
	if(yyin==NULL)
	{
		perror("Input file not opened");
		exit(0);
	}
	yyout = fopen("out.txt","w");
	if(yyout==NULL)
	{
		perror("Output file not opened");
		exit(0);
	}
	yyparse();
	return 0;
}

int yyerror(char* s)
{
	printf("ERROR: %s\n",s);
	return 0;
}
