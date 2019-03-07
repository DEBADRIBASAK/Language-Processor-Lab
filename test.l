%{
%}
%%
[a-z]+ {printf("Word\n");}
[0-9]+ {printf("Number\n");}
. {printf("Mystery\n");}
\n {}

%%

int main()
{
	yylex();
	return 0;
}
