/*1_21_entab.c:���ո��滻Ϊ�����������Ʊ���Ϳո񣬵����ֵ���֮��ļ������*/
#include<stdio.h>

#define MAXLINE 1000 /*���������߶�*/
#define TAB2SPACE 4 /*4 spaces to a tab*/

char line[MAXLINE]; /*������ַ���*/
int getline(void);	/*taken from the KnR book*/

int main(void){
	int i,t;
	int spacecount,len;
	
	while((len = getline()) >0)
	{
		spacecount = 0;
		for(i = 0;i<len;i++){
			if(line[i] == ' ')
				spacecount++; /*ͳ�ƿո���*/
			if(line[i] != ' ')
				spacecount = 0; /*ֵ��λ*/
			if(spacecount == TAB2SPACE) /*���㹻�Ŀո��滻�Ʊ��*/
			{
				/*�Ƴ�4���ո�ʹ�������滻1���Ʊ����ʹ�ÿո��滻�Ʊ����*/
				i -= 3;
				len -= 3;
				line[i] = '\t';
				/*ʹ��һ���Ʊ���滻4���ո� ���鷶Χ���һ����С*/
				for(t = i+1;t<len;t++)
					line[t] = line[t+3];
				spacecount = 0; //�ո�ֻ��λ 
				line[len] = '\0'; 
			
			} 
			/*��ֵ��ո���С��4��ô������ո��пո���Ϊ3ʱ
			�ո���С��4�����滻����ʹ�������������Ʊ���Ϳո��滻�ո� 
			*/ 
		}
		printf("%s",line);
	}
	return 0;
}
/*��stdin��ȡһ���ַ�*/ 
int getline(void){
	int c,i;
	extern char line[];/*��ʾ�ⲿȫ�ֱ���*/ 
	
	for(i = 0;i<MAXLINE-1 && (c=getchar())!= EOF && c !='\n';++i)
		line[i] = c;
	if(c == '\n'){
		line[i] =c;
		++i;
	}
	line[i] = '\0';
	return i;
}
