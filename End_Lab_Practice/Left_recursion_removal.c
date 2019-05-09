#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Rules
{
	char var;
	char der[10];
};

int main(int argc, char const *argv[])
{
	int n;
	printf("How many productions?\n");
	scanf("%d",&n);
	while(getchar()!='\n');
	struct Rules a[n];int pos = 1;
	int positions[26] = {0};
	for(int i=0;i<n;i++)
	{
		printf("Enter the variable");
		scanf("%c",&a[i].var);
		while(getchar()!='\n');
		if(!positions[a[i].var-'A'])
		{
			positions[a[i]-'A'] = pos;
			pos++;
		}
		printf("Enter the derivation\n");
		scanf("%s",a[i].der);
		while(getchar()!='\n');
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(position[a[j].var-'A']<position[a[i].var-'A'])
			{
				
			}
		}	
	}
	return 0;
}