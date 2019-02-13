#This is a makefile for compilation of flex and bison together 

First:
	bison -d First.y
	flex Scanner.l
	gcc -o $@ First.tab.c lex.yy.c -lfl
