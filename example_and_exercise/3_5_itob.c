/*3_5_itob.c
函数itob(n,s,b),将整数n转换为以b为底的数，并将转换结果以字符
形式保存到字符串中。如itob(n,s,16)把整数n格式化成十六进制数整数保存在s中 
求出n对应16进制形式（将十进制转16进制）、保存到字符数组中、对字符数组进行翻转 
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
		itob(255,buffer,i);//i为底数 
		printf("Decimal 255 in base %-2d:%s\n",i,buffer);
	}
	return 0;
} 

/*在s[]中保存整数n转换的字符串，使用数字b为底数*/
void itob(int n,char s[],int b){
	static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,sign;
	
	if(b<2 || b>36){
		fprintf(stderr,"EX3_5:Cannot support base %d\n",b);
		exit(EXIT_FAILURE);
	}
	
	if((sign = 0) < 0){	//将n变成正整数 
		n = -n;
	}
	do{
		s[i++] = digits[n%b];   //将n求余b的结果转换为十六进制 
	} while((n/=b) > 0);
	if(sign<0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);	//翻转字符串 
} 

void reverse(char s[]){
	int c,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;		
	}
}
