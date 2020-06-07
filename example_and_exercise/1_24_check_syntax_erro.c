/*1_24_check_syntax_erro.c
Q：查找C语言程序中的基本语法错误，如圆括号、方括号、花括号不配对等
正确处理引号（单引号和双引号）、转义字符序列与注释 
( [ { 
*/
#include<stdio.h>

#define MAXLINE 1000
char line[MAXLINE];

int getline(void);

int main(){
	int len = 0;
	int t = 0;
	int brace =0,bracket=0,parenthesis=0;
	int s_quote=1,d_quote=1;
	
	while((len = getline())>0)
	{
		t = 0;
		while(t < len)
		{
			if(line[t] == '[')
			{
				brace++; //记录左中括号数 
			 } 
			 if(line[t] == ']'){
			 	brace--;//记录右中括号数  
			 }
			 if(line[t] == '(')
			 {
			 	parenthesis++;//记录左圆括号数 
			 }
			 if(line[t] == ')')
			 {
			 	parenthesis--;
			 }
			 if(line[t] == '\'') 
			 {
			 	s_quote *= -1;//记录'\''是否为双数 
			 }
			 if(line[t] == '"'){
			 	d_quote *= -1;//记录'*'是否为双数 
			 }
			 t++;
		}
	}
	if(d_quote != 1)
		printf("Mismatching double quote mark\n");
	if(s_quote != 1)
		printf("Mismatching single quote mark\n");
	if(parenthesis != 0)
		printf("Mismatching parenthesis\n");
	if(bracket != 0)
		printf("Mismatching bracket mark\n");
	if(brace != 0)
		printf("Mismatching brace mark\n");
	if(bracket==0 && brace==0 && parenthesis==0 && s_quote == 1 && d_quote ==1)
		printf("Syntax appears to be correct.\n");
	return 0;
}

int getline(void){
	int c,i;
	extern char line[];
	for(i = 0;i<MAXLINE-1 && (c = getchar())!=EOF && c != '\n';++i)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

/*
{asdfa[asdfasdf]asdfasd(asdfasdf}asdf)
^Z
Syntax appears to be correct.
括号个数是对应的，但格式上对应错误 
*/


