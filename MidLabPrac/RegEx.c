#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rules
{
	char Var;
	char* der;
	struct rules* next;
};

struct rules* head = NULL,*tail = NULL;
char next_var = 'A';

void add_end(char var,char* der)
{
	if(head==NULL)
	{
		head = (struct rules*)malloc(sizeof(struct rules));
		head->Var = var;
		head->der = strdup(der);
		head->next = NULL;
		tail = head;
	}
	else
	{
		tail->next = (struct rules*)malloc(sizeof(struct rules));
		tail->next->Var = var;
		tail->next->der = strdup(der);
		tail->next->next = NULL;
		tail = tail->next;
	}
}



char decode(char* helper,int size,char lookahead)
{
	char a[100];int j = 0;
	for(int i=0;i<size;i++)
	{
		a[j++] = helper[i];
		if(i<size-1&&helper[i+1]=='-')
		{
			for(char c=helper[i]+1;c<=helper[i+2];c++)
			{
				a[j++] = c;
			}
			i+=2;
		}
	}
	for(int i=0;i<j;i++)
	{
		char der[3];
		der[0] = a[i];
		if(lookahead=='+'||lookahead=='*')
		{
			der[1] = next_var;
			der[2] = '\0';
		}
		else
			der[1] = '\0';
		add_end(next_var,der);
		if(lookahead=='+')
		{
			der[0] = a[i];
			der[1] = '\0';
			add_end(next_var,der);
		}
	}
	if(lookahead=='?'||lookahead=='*')
	{
		char der[2];
		der[0] = '@';
		der[1] = '\0';
		add_end(next_var,der);
	}
	return next_var++;
}

void add(struct rules* d,char v)
{
	char d1[2];
	d1[0] = v;
	d1[1] = '\0';
	strcat(d->der,d1);
}

void print(struct rules* d)
{
	struct rules* q = d;
	while(q!=NULL)
	{
		printf("%c :: %s\n",q->Var,q->der);
		q = q->next;
	}
}

struct rules* change(char* regex,int n,char st)
{
	printf("Helper = %s\n",regex);
	struct rules *start,*r;
	start = (struct rules*)malloc(sizeof(struct rules));
	start->Var = st;
	start->der = (char*)malloc(sizeof(char));int i = 0;
	while(i<n)
	{
		char helper[50],sym,lookahead;int j = 0;
		if(regex[i]=='[')
		{
			i++;
			while(regex[i]!=']')
			{
				helper[j++] = regex[i++];
			}
			i++;
			if(i==n)
			{
				lookahead = '#';i--;
			}
			else if(regex[i]!='?'&&regex[i]!='*'&&regex[i]!='+')
			{
				lookahead = '#';i--;
			}
			else
				lookahead = regex[i]; // * or + or ?
			sym = decode(helper,j,lookahead);
			add(start,sym);
		}
		else if(regex[i]=='|')
		{
			add(start,'|');
		}
		else if(regex[i]=='(')
		{
			struct rules* dummy;
			
			i++;
			while(i<n&&regex[i]!=')')
			{
				helper[j++] = regex[i++];
			}
			helper[j] = '\0';
			r = change(helper,j,next_var++);
			if(tail==NULL)
			{
				head = tail = r;
			}
			else
			{
				tail->next = r;
				tail = tail->next;
			}
			if(i<n-1&&(regex[i+1]=='*'||regex[i+1]=='+'||regex[i+1]=='?'))
			{
				
				dummy = (struct rules*)malloc(sizeof(struct rules));
				dummy->Var = next_var++;
				dummy->der = (char*)malloc(sizeof(char)*3);

				if(regex[i+1]=='*')
				{
					dummy->der[0] = r->Var;
					dummy->der[1] = dummy->Var;
					dummy->der[2] = '\0';
					tail->next = dummy;
					tail = tail->next;
					dummy = (struct rules*)malloc(sizeof(struct rules));
					dummy->Var = tail->Var;
					dummy->der = (char*)malloc(sizeof(char)*3);
					dummy->der[0] = '@';
					dummy->der[1] = '\0';
					tail->next = dummy;
					tail = tail->next;
				}
				else if(regex[i+1]=='+')
				{
					dummy->der[0] = r->Var;
					dummy->der[1] = dummy->Var;
					dummy->der[2] = '\0';
					tail->next = dummy;
					tail = tail->next;
					dummy = (struct rules*)malloc(sizeof(struct rules));
					dummy->Var = tail->Var;
					dummy->der = (char*)malloc(sizeof(char)*3);
					dummy->der[0] = r->Var;
					dummy->der[1] = '\0';
					tail->next = dummy;
					tail = tail->next;
				}
				else
				{
					dummy->der[0] = r->Var;
				//	dummy->der[1] = dummy->Var;
					dummy->der[1] = '\0';
					tail->next = dummy;
					tail = tail->next;
					dummy = (struct rules*)malloc(sizeof(struct rules));
					dummy->Var = tail->Var;
					dummy->der = (char*)malloc(sizeof(char)*3);
					dummy->der[0] = '@';
					dummy->der[1] = '\0';
					tail->next = dummy;
					tail = tail->next;
				}
				add(start,dummy->Var);i++;
			}
			else
				add(start,r->Var);
		}
		else
		{
			helper[j++] = regex[i];
			i++;
			if(i==n)
			{
				lookahead = '#';i--;
			}
			else if(regex[i]!='?'&&regex[i]!='+'&&regex[i]!='*')
			{
				lookahead = '#';i--;
			}
			else
				lookahead = regex[i];
			
			sym = decode(helper,1,lookahead);
			add(start,sym);
		}
		i++;
	}
	return start;
}


int main(int argc, char const *argv[])
{
	char regex[50];
	printf("Enter one regex\n");
	scanf("%s",regex);
	int n = strlen(regex),i = 0;
	struct rules* st;
	st = change(regex,n,'S');
	printf("Here..\n");
	st->next = head;
	print(st);
	return 0;
}