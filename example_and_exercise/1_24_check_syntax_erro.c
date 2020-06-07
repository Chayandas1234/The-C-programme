/*1_24_check_syntax_erro.c
Q������C���Գ����еĻ����﷨������Բ���š������š������Ų���Ե�
��ȷ�������ţ������ź�˫���ţ���ת���ַ�������ע�� 
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
				brace++; //��¼���������� 
			 } 
			 if(line[t] == ']'){
			 	brace--;//��¼����������  
			 }
			 if(line[t] == '(')
			 {
			 	parenthesis++;//��¼��Բ������ 
			 }
			 if(line[t] == ')')
			 {
			 	parenthesis--;
			 }
			 if(line[t] == '\'') 
			 {
			 	s_quote *= -1;//��¼'\''�Ƿ�Ϊ˫�� 
			 }
			 if(line[t] == '"'){
			 	d_quote *= -1;//��¼'*'�Ƿ�Ϊ˫�� 
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
���Ÿ����Ƕ�Ӧ�ģ�����ʽ�϶�Ӧ���� 
*/


