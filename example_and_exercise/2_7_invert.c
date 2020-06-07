/*2_7_invert.c：编写函数invert(x,p,n)，
返回值：将x中从第p位开始的n个（二进制）位求反，x求余各位保持不变*/
#include<stdio.h>
#define X 700
int invert(unsigned x,int p,int n){
	//????
	return x^(~(~0U<<n) <<p); //^:异或 
}
int main(void){
	unsigned x;
	int p,n,k;
	
	for(x=0;x<X;x +=49)
		for(n=1;n<8;n++)
			for(p=1;p<8;p++)
		{
			k = invert(x,p,n);
			printf("%u,%d,%d:%u\n",x,n,p,k);
		}
	
	return 0;
}
