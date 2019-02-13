/* HEX to DEC */

%{

int toInt(char* str);

%}

%%

[0-9A-F]+ {printf("%d\n",toInt(yytext));}
. 
\n
%%

int toInt(char* str)
{
	char* p;
	p = str;
	int i = 0;
	while(*p!='\0'&&*p=='0')
	p++;
	while(*p!='\0')
	{
		i = (i*16)+(((*p>='0')&&(*p<='9'))?(*p-'0'):(*p-'A'+10));
		p++;
	}	
	return i;
}

int main()
{
	yylex();
	return 0;
}
