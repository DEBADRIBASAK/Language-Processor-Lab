#ifndef __SUBSETH
struct symbol_table
{
	double val;
	int scope,type;
	char* name;
};

#define NHASH 9997




struct ast
{
	int nodetype;
	struct ast* l,*r;
};

struct num
{
	int nodetype;
	int type; // integer or float
	double val;	
};

struct ref
{
	int nodetype;
	struct symbol_table* s;
};

struct cmpnode
{
	int nodetype,type;
	struct ast* l,*r;
};



struct flow
{
	int nodetype,type;
	struct ast* cond,*init,*inc;
	struct ast* s,*e;
};

struct bitwise
{
	int nodetype,type;
	struct ast* l,*r;
};

struct logical
{
	int nodetype,type;
	struct ast* l,*r;
};

struct assgn
{
	int nodetype,type;
	struct symbol_table* sym;
	struct ast* s;
};

int hash(char* s);
struct symbol_table* insert_into_symbol_table(char* s);
struct symbol_table* search(char* s,int scope);
struct ast* newast(int nodetype,struct ast* l,struct ast* r);
struct ast* newnum(int nodetype,int type,double val);
struct ast* newref(int nodetype,struct symbol_table* s);
struct ast* newassgn(int nodetype,int type,struct symbol_table* s,struct ast* t);
struct ast* newcmp(int nodetype,int type,struct ast* exp,struct ast* s);
struct ast* newflow(int nodetype,int type,struct ast* cond,struct ast* s,struct ast* e,struct ast* init,struct ast *inc);
struct ast* newbit(int nodetype,int type,struct ast* l,struct ast* r);
struct ast* newlog(int nodetype,int type,struct ast* l,struct ast* r);

char* generate_code(struct ast* a);


#endif 
