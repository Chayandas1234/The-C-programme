/*1_22_folf_input.c
�ѽϳ��������С��ۡ��ɶ�һЩ�����л���У�
���е�λ���������еĵ�n��֮ǰ�����һ���ǿո�֮��
��֤�������ܵڴ��������кܳ��Լ���ָ������ǰû�пո���Ʊ��ʱ������� 
*/ 
#include<stdio.h>
#define MAXLINE 1000

char line[MAXLINE];
int getline(void);

int main(){
	int t,len;
	int location,spaceholder;
	const int FOLDLENGTH = 70;/*һ����󳤶�*/
	
	while((len = getline()) > 0)
	{
		if(len < FOLDLENGTH){  //���ַ���С�� FOLDLENGTH����ͬ���У���һ�� 
		}
		else{
			/*����һ���ܳ���һ���ַ���ͨ���滻�ո񸽽����ַ������۳��µ�һ��*/
			t = 0;
			location = 0;
			while(t < len){
				if(line[t] == ' ')  
					spaceholder = t;//��¼�ո��ַ���λ�� 
				if(location == FOLDLENGTH){
					line[spaceholder] = '\n';//�������ַ����ȴ��ڵ���FOLDLENGTH��ʹ�û����滻�ո�ʵ�ֻ��� 
					location = 0;//���¿�ʼ��ͳ����һ�� 
				}
				location++;//
				t++;//�����ַ�λ�� 
				printf("%d,%d ",location,t);
			}
		}
		printf("%s",line);
	}
	return 0;
}



/*��stdinһ��һ���ַ���ȡ*/ 
int getline(void)
{
	int c,i;
	extern char line[];
//	i=0;
//	while((c = getchar()) != EOF){} 
	for(i = 0;i<MAXLINE-1 && (c = getchar())!= EOF && c != '\n';++i){
		line[i] = c;
	}
	if(c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
} 

/*
const int FOLDLENGTH = 20;
asasaasasasasasasasas  asasasasasasasasas a asasasasasasasasasasasas  asas
sasaasasasasasasasas
asasasasasasasasas a
asasasasasasasasasasasas  asas
*/

