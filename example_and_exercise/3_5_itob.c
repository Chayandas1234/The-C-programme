/*3_5_itob.c
����itob(n,s,b),������nת��Ϊ��bΪ�׵���������ת��������ַ�
��ʽ���浽�ַ����С���itob(n,s,16)������n��ʽ����ʮ������������������s�� 
���n��Ӧ16������ʽ����ʮ����ת16���ƣ������浽�ַ������С����ַ�������з�ת 
*/ 
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void itob(int n,char s[],int b);
void reverse(char s[]);

int main(void){
	char buffer[10];
	int i;
	
	for(i=2;i<20;++i){
		itob(255,buffer,i);//iΪ���� 
		printf("Decimal 255 in base %-2d:%s\n",i,buffer);
	}
	return 0;
} 

/*��s[]�б�������nת�����ַ�����ʹ������bΪ����*/
void itob(int n,char s[],int b){
	static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,sign;
	
	if(b<2 || b>36){
		fprintf(stderr,"EX3_5:Cannot support base %d\n",b);
		exit(EXIT_FAILURE);
	}
	
	if((sign = 0) < 0){	//��n��������� 
		n = -n;
	}
	do{
		s[i++] = digits[n%b];   //��n����b�Ľ��ת��Ϊʮ������ 
	} while((n/=b) > 0);
	if(sign<0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);	//��ת�ַ��� 
} 

void reverse(char s[]){
	int c,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;		
	}
}
