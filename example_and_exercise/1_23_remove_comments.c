/*1_23_remove_comments.c
Q:ɾ��C���Գ��������е�ע����� 
*/
#include<stdio.h>
#define MAXLINE 1000

char line[MAXLINE]; 
int getline(void);

int main(){
	int in_comment,len;
	int in_quote;//���ű�־λ 
	int t;
	
	in_comment = in_quote = t =0;
	while((len = getline())>0){
		t = 0;
		while(t < len){
			if(line[t] == '"')
				in_quote = 1;//���ű�־λ��ʲô��˼�� 
			if (! in_quote)
			{
				if(line[t] == '/' && line[t+1] == '*')
				{
					t = t+2;//? ����/*�����ַ� 
					in_comment = 1;//ע�ͱ�־λ 
				}
				if(line[t] == '*' && line[t+1] == '/')
				{
					t += 2;
					in_comment = 0; //�ҳ���ע��λ�ú�ע�ͱ�־λ��λ 
				} 
				if(in_comment == 1)
				{
					t++;//�ҳ�ע�ͺ������� 
				}
				else{
					printf("%c",line[t]);
					t++;
				}
			}
			else{
				printf("%c",line[t]);
				t++;
			}
		}
	}
	
	return 0;
} 


int getline(void){
	int i,c;
	extern char line[];
	
	for(i =0;i<MAXLINE-1 && (c = getchar())!=EOF && c != '\n';++i){
		line[i] = c;
	}
	if(c == '\n'){
		line[i] = c;
		++i;//����ΪʲôҪ++i,��Ӧ��ʹ��'\0'�滻��'\n'�� 
	}
	line[i] = '\0';
	
	return i;//���ض�ȡ�ַ����� 
} 
