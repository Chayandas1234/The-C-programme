/*Time:20200426 
1.9 �ַ���������:��ӡ��ı���*/
/*�����߼��������ַ������浽�ַ������в���� 
  ������ֻ�ǽ������ַ���ӡ������δʵ�ִ�ӡ��ı��У� 
*/ 
#include<stdio.h>
#define MAXLINE 1000	/*�������еĳ���*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*��ӡ�������*/

int main(){
	int len;	/*�����г���*/
	int max;	/*��󳤶�*/
	char line[MAXLINE];		/*������*/
	char longest[MAXLINE];	/*������ľ���*/
	
//	max = 0;
	while((len = getline(line,MAXLINE)) > 0){
		printf("len=%d\n",len); 
		if(len > MAXLINE){
			//erro
			printf("�������"); 
		}

	if(len > 0)	/*��ӡ������*/
		printf("%s",line);	/*��%s��ʽ��ӡ������*/ 
	} 
	return 0; 
} 

/*getline:����һ���ַ�������ַ������������䳤��*/
int getline(char s[],int lim){	/*���������ݵ��β����ַ���������ͨ�����������±�ɸ�������Ԫ��*/
	/*�����ַ����ȡ�*/
	int c,i;
	
	/*�����������ַ�����MAXLINEʱ�����Զ�������һ��д��*/ 
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c != '\n';++i)
		s[i] = c;
	if(c == '\n'){	/*�жϾ����Ƿ��У������ֻ��з�˵��һ�н���*/ 
		s[i] = c;
		++i;
	} 
	s[i] = '\0';	/*�ַ������������ַ�������ʽ�洢������'\0'��־�ַ����Ľ���*/

	return i;
}


/*
asdfasdf
len=9
asdfasdf
asd
len=4
asd
asdfasdfasdf
len=13
asdfasdfasdf
assssssssssssssssssssss
len=24
assssssssssssssssssssss
asdfa
len=6
asdfa
asdfasdfasdf
len=13
asdfasdfasdf
^Z
*/
