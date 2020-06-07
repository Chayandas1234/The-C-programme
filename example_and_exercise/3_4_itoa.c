/*3_4_itoa.c在数的对二补码表示中，编写的itoa函数不能处理最大的负数，
即n等于-2^(字长-1)，解释其原因，修改该函数，使它在任何机器上运行时
都能打印出正确的值*/ 
#include<stdio.h>
#include<string.h>
#include<limits.h>

void itoa(int n,char s[]);
void reverse(char s[]);

int main(void){
	char buffer[20];
	
	printf("INT_MIN:%d\n",INT_MIN);
	itoa(INT_MIN,buffer);
	printf("%s.\n",buffer);
	return 0;
}

void itoa(int n,char s[]){
	int i,sign;
	sign = n;
	
	i = 0;
	do{
		s[i++] = abs(n % 10) + '0'; 
	} while(n /= 10);
	
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int c,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;		
	}
}
