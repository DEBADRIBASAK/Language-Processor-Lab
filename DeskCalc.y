/* an initial implementation of desk calculator */

%{
	#include <stdio.h>
	#include <stdlib.h>	
	#include <math.h>
	#include <string.h>
	#include <stdarg.h>
	#include "DeskCalc.h"
	int yylex();
%}
%union{
	struct ast* a;
	double d;
	struct symbol *s;
	struct symlist *s1;
	int fn;
}


%token <d> NUM 
%token <s> NAME
%token <fn> FUNC
%token IF THEN ELSE WHILE DO LET
%nonassoc <fn> CMP
%right EQU
%left ADD SUB
%left MUL DIV
%right EXP
%nonassoc ABS UM
%token EOL
%token OPBR
%token CLBR
%token DISPLAY
%type <a> exp stmt list explist
%type <s1> symlist

%start calclist



%%
exp: exp CMP exp { $$  = newcmp($2,$1,$3);}
   | exp ADD exp { $$ = newast(ADD,(struct ast*)$1,(struct ast*)$3);}
   | exp SUB exp { $$ = newast(SUB,(struct ast*)$1,(struct ast*)$3);}
   | exp MUL exp { $$ = newast(MUL,(struct ast*)$1,(struct ast*)$3);}
   | exp DIV exp { $$ = newast(DIV,(struct ast*)$1,(struct ast*)$3);}
   | exp EXP exp {$$ = newast(EXP,(struct ast*)$1,(struct ast*)$3);}
   | ABS exp { $$ = newast(ABS,(struct ast*)$2,NULL);}
   | UM exp { $$ = newast(UM,(struct ast*)$2,NULL);}
   | OPBR exp CLBR { $$ = $2;}
   | NAME { 
		$$ = newref($1); 
	  }
   | NUM { $$ = newnum(NUM,$1);}
   | NAME EQU exp {$$ = newasgn($1,$3);}
   | FUNC OPBR explist CLBR {$$ = newfunc($1,$3);}
   | NAME OPBR explist CLBR {$$ = newcall($1,$3);}
   ;
   
explist: exp
       | exp ',' explist { $$ = newast('L',$1,$3); };
       ;
symlist: NAME 	{$$ = newsymlist($1,NULL); }
       | NAME ',' symlist { $$ = newsymlist($1,$3); }
       ;
   
   
stmt: IF exp THEN list { $$ = newflow('I',$2,$4,NULL);};
    | IF exp THEN list ELSE list { $$ = newflow('I',$2,$4,$6);}
    | WHILE exp DO list { $$ = newflow('W',$2,$4,NULL); }
    | exp
    ;

list: /* non */ { $$ = NULL ;}
    | stmt ';' list { if($3==NULL)
    			$$ = $1;
    		      else
    		        $$ = newast('L',$1,$3);
    		    }
    ;

calclist: /* do nothing */
	| calclist EOL {printf(">");}
	| calclist stmt EOL { if($2->nodetype!='=')printf("Use \"let\" to declare a variable or function and \"display\" to display the value of variable or expression");printf("\n>");eval((struct ast*)$2);}
	| calclist DISPLAY stmt EOL {
				if($3->nodetype!='=')
				printf("= %.4f\n> ",eval((struct ast*)$3));
				else
				{
					eval((struct ast*)$3);printf(">");
				}
				treefree($3);}
	| calclist LET NAME OPBR symlist CLBR EQU list EOL { dodef($3,$5,$8);
								printf("Defined: %s\n> ",$3->name);}
	| calclist LET NAME EQU exp EOL { define_variables($3,$5);printf("Defined a variable: %s\n>",$3->name);}
	;

%%


void define_variables(struct symbol* name,struct ast* st)
{
	if(name->syms) symlistfree(name->syms);
	if(name->func) treefree(name->func);
	name->value = eval(st);
	name->not_yet_defined = 0;
}

static unsigned symhash(char *sym)
{
	unsigned int hash = 0;
	unsigned c;
	while(c = *sym++) hash = hash*9 ^ c;
	return hash;
}


struct symbol* lookup(char* sym)
{
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;
	while(--scount >= 0) {
		if(sp->name&&!sp->not_yet_defined && !strcmp(sp->name, sym)) { return sp; }
		if(!sp->name||sp->not_yet_defined) {
			sp->name = strdup(sym);
			sp->value = 0;
			sp->not_yet_defined = 1;
			sp->func = NULL;
			sp->syms = NULL;
			return sp;
		}
		if(++sp >= symtab+NHASH) sp = symtab; 

		yyerror("symbol table overflow\n");
		abort(); 
	}
}





struct ast* newast(int nodetype,struct ast* l,struct ast* r)
{
	struct ast* rtn;
	rtn = NULL;
	rtn = (struct ast*)malloc(sizeof(struct ast));
	rtn->nodetype = nodetype;
	rtn->l = l;
	rtn->r = r;
	return rtn;
}
struct ast* newnum(int nodetype,double f)
{
	struct num* rtn;
	rtn = NULL;
	rtn = (struct num*)malloc(sizeof(struct num));
	rtn->nodetype = nodetype;
	rtn->val = f;
	return (struct ast*)rtn;
}


struct ast* newcmp(int cmptype,struct ast* l,struct ast* r)
{
	struct ast* a = malloc(sizeof(struct ast));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = '0'+cmptype;
	a->l = l;
	a->r = r;
	return a;
}

struct ast* newfunc(int functype,struct ast* l)
{
	struct fncall *a = malloc(sizeof(struct fncall));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = 'F';
	a->l = l;
	a->functype = functype;
	return (struct ast*)a;
}

struct ast* newcall(struct symbol *s,struct ast* l)
{
	struct ufncall *a = malloc(sizeof(struct ufncall));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = 'C';
	a->l = l;
	a->s = s;
	return (struct ast*)a;
}

struct ast* newref(struct symbol *s)
{
	struct symref* a = malloc(sizeof(struct symref));
	if(!a)
	{
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = 'N';
	a->s = s;
	return (struct ast*)a;
}


struct ast *newasgn(struct symbol *s, struct ast *v)
{
	struct symasgn *a = malloc(sizeof(struct symasgn));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = '=';
	a->s = s;
	a->v = v;
	return (struct ast *)a;
}


struct ast *newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *el)
{
	struct flow *a = malloc(sizeof(struct flow));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = nodetype;
	a->cond = cond;
	a->tl = tl;
	a->el = el;
	return (struct ast *)a;
}

void treefree(struct ast *a)
{
	switch(a->nodetype) {
		case ADD:
		case SUB:
		case MUL:
		case DIV:
		case EXP:
		case '1': case '2':
		case 'L':
		treefree(a->r);
		case '3':
		case '4': 
		case '5': 
		case '6':
		case '|':
		case 'M': 
		case 'C': 
		case 'F':
		case ABS:
		case UM:
		treefree(a->l);
		case NUM: 
		case 'N':
		break;
		case '=':
		free( ((struct symasgn *)a)->v);
		break;
		case 'I': case 'W':
		free( ((struct flow *)a)->cond);
		if( ((struct flow *)a)->tl) treefree( ((struct flow *)a)->tl);
		if( ((struct flow *)a)->el) treefree( ((struct flow *)a)->el);
		break;
		default: 
		printf("internal error: free bad node %c\n", a->nodetype);
		break;
	}
	free(a); 
}


struct symlist *newsymlist(struct symbol *sym, struct symlist *next)
{
	struct symlist *sl = malloc(sizeof(struct symlist));
	if(!sl) {
		yyerror("out of space");
		exit(0);
	}
	sl->sym = sym;
	sl->next = next;
	return sl;
}

void symlistfree(struct symlist *sl)
{
	struct symlist *nsl;
	while(sl) {
		nsl = sl->next;
		free(sl);
		sl = nsl;
	}
}


double eval(struct ast* a)
{
	double v;
	if(!a) {
		yyerror("internal error, null eval");
		return 0.0;
	}
	switch(a->nodetype)
	{
		case NUM:
		return ((struct num*)a)->val;
		break;
		
		case 'N': 
		v = ((struct symref *)a)->s->value; 
		break;
		
		case '=': 
		v = ((struct symasgn *)a)->s->value = eval(((struct symasgn *)a)->v);
	        break;
		
		case ADD:
		return eval(a->l)+eval(a->r);
		break;
		
		case SUB:
		return eval(a->l)-eval(a->r);
		break;
		
		case MUL:
		return eval(a->l)*eval(a->r);
		break;
		
		case DIV:
		return eval(a->l)/eval(a->r);
		break;
		
		case EXP:
		return pow(eval(a->l),eval(a->r));
		break;
		
		case ABS:
		v = eval(a->l);
		return (v>0)?v:-v;
		break;
		
		case UM:
		v = eval(a->l);
		return -v;
		break;
		
		
		case '1':
		v = (eval(a->l)>eval(a->r))?1:0;break;
		
		case '2':
		v = (eval(a->l)<eval(a->r))?1:0;break;
		
		case '3':
		v = (eval(a->l)!=eval(a->r))?1:0;break;
		
		case '4':
		v = (eval(a->l)==eval(a->r))?1:0;break;
		
		case '5':
		v = (eval(a->l)>=eval(a->r))?1:0;break;
		
		case '6':
		v = (eval(a->l)<=eval(a->r))?1:0;break;
		
		
		case 'I':
		if(eval(((struct flow*)a)->cond)!=0)
		{	
			if(((struct flow*)a)->tl)
			{
				v = eval(((struct flow*)a)->tl);
			}
			else
			{
				v = 0.0;
			}
		}
		else
		{
			if(((struct flow*)a)->el)
			{
				v = eval(((struct flow*)a)->el);
			}
			else
			{
				v = 0.0;
			}
		}
		break;
		
		case 'W':
		v = 0.0;
		if(((struct flow*)a)->tl)
		{
			while(eval(((struct flow*)a)->cond)!=0)
			{
				v = eval(((struct flow*)a)->tl);
			}
		}
		break;
		
		case 'L':
		eval(a->l); 
		v = eval(a->r);
		break;
		
		case 'F':
		v = callbuiltin((struct fncall*)a);
		break;
		
		case 'C':
		v = calluser((struct ufncall*)a);
		break;
			
		default:
		printf("Bad operator\n");
		break;
	}
	return v;
}

static double
callbuiltin(struct fncall *f)
{
	enum bifs functype = f->functype;
	double v = eval(f->l);
	switch(functype) {
		case B_sqrt:
		return sqrt(v);
		case B_exp:
		return exp(v);
		case B_log:
		return log(v);
		case B_print:
		printf("= %4.4g\n", v);
		return v;
		default:
		yyerror("Unknown built-in function");
		return 0.0;
	}
}

void dodef(struct symbol *name, struct symlist *syms, struct ast *func)
{
		if(name->syms) symlistfree(name->syms);
		if(name->func) treefree(name->func);
		name->syms = syms;
		name->func = func;
		name->not_yet_defined = 0;
}




static double calluser(struct ufncall *f)
{
	struct symbol *fn = f->s;
	struct symlist *sl;
	struct ast *args = f->l;
	double *oldval, *newval;
	double v;
	int nargs;
	int i;
	if(!fn->func) {
		yyerror("call to undefined function");
		return 0;
	}
	sl = fn->syms;
	for(nargs = 0; sl; sl = sl->next)
	nargs++;
	oldval = (double *)malloc(nargs * sizeof(double));
	newval = (double *)malloc(nargs * sizeof(double));
	if(!oldval || !newval) {
		yyerror("Out of space in"); return 0.0;
	}
	for(i = 0; i < nargs; i++) {
		if(!args) {
			yyerror("too few args in call to %s");
			free(oldval); free(newval);
			return 0.0;
		}
		if(args->nodetype == 'L') { 
			newval[i] = eval(args->l);
			args = args->r;
		}
	 	else {
			newval[i] = eval(args);
			args = NULL;
		}
	}
	sl = fn->syms;
	for(i = 0; i < nargs; i++) {
		struct symbol *s = sl->sym;
		oldval[i] = s->value;
		s->value = newval[i];
		sl = sl->next;
	}
	free(newval);
	v = eval(fn->func);
	sl = fn->syms;
	for(i = 0; i < nargs; i++) 
	{
		struct symbol *s = sl->sym;
		s->value = oldval[i];
		sl = sl->next;
	}
	free(oldval);
	return v;
}



int main()
{
	yydebug = 1;
	yyparse();
	return 0;
}

int yyerror(char *s)
{
	fprintf(stderr,"ERROR: %s\n",s);
	return 0;
}
