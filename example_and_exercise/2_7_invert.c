/*2_7_invert.c����д����invert(x,p,n)��
����ֵ����x�дӵ�pλ��ʼ��n���������ƣ�λ�󷴣�x�����λ���ֲ���*/
#include<stdio.h>
#define X 700
int invert(unsigned x,int p,int n){
	//????
	return x^(~(~0U<<n) <<p); //^:��� 
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
