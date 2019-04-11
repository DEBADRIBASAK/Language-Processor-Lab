%option noyywrap
%{
	
%}

num [0-9]
letter [a-z]

%%

({num}+{letter}+)+ { printf("TRUE\n");}
.* {printf("Mystery character\n");}
\n {}

%%

int main()
{
	yylex();
}
