	struct ast
	{
		int nodetype;
		struct ast* l,*r;
	};
	struct num
	{
		int nodetype;
		double val;
	};
	
	struct symbol
	{
		char *name;
		double value;
		struct ast* func;
		struct symlist* syms;
		int not_yet_defined;
		int func_para;
	};
	
	#define NHASH 997
	static unsigned symhash(char* sym);
	
	struct symbol symtab[NHASH];
	
	struct symbol* lookup(char*);
	
	struct symlist{
		struct symbol* sym;
		struct symlist *next;
	};
	
	struct symlist* newsymlist(struct symbol* sym,struct symlist* next);
	void symlistfree(struct symlist *s1);
	
	enum bifs /* built-in functions */
	{
		B_sqrt = 1,
		B_exp,
		B_log,
		B_print
	};
	
	struct fncall
	{
		int nodetype;
		struct ast *l;
		enum bifs functype;
	};
	
	struct ufncall
	{
		int nodetype;
		struct ast *l;
		struct symbol *s;
	};
	
	struct flow
	{
		int nodetype;
		struct ast* cond;
		struct ast* tl;
		struct ast* el;
	};
	
	struct symref
	{
		int nodetype;
		struct symbol* s;
	};
	
	struct symasgn
	{
		int nodetype;
		struct symbol *s;
		struct ast *v;
	};
	
	struct ast* newast(int nodetype,struct ast* l,struct ast* r);
	struct ast* newcmp(int cmptype,struct ast* l,struct ast* r);
	struct ast* newfunc(int functype,struct ast *l);
	struct ast* newcall(struct symbol* s,struct ast* l);
	struct ast* newref(struct symbol *s);
	struct ast* newasgn(struct symbol* s,struct ast* v);
	struct ast* newflow(int nodetype,struct ast* cond,struct ast* tl,struct ast* tr);
	struct ast* newnum(int nodetype,double f);
	double eval(struct ast* t);
	void dodef(struct symbol* name,struct symlist *syms,struct ast* stmts);
	void treefree(struct ast*);
	extern int yylineno;
	int yyerror(char* s);
	static double callbuiltin(struct fncall *);
	static double calluser(struct ufncall *);
	void define_variables(struct symbol* name,struct ast* st);
