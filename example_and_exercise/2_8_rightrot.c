/*2_8_rightrot.c
���� rightrot��x,n��,����xѭ������
���������Ҷ��Ƴ���λ������������룩n�������ƣ������õ��ĵ�ֵ�� 
����:a<<5 ����5λ����λ��0��
���ƣ����߼����Ƽ���������
�߼����ƣ���λ���λ��0
�������ƣ�������λ1���������Ϊ1��������λΪ0��������λ��Ϊ0�� 
*/ 
unsigned rightrot(unsigned x,unsigned n){
	while(n>0){
		if((x & 1) == 1)  // x!=0 ������ 
			x = (x>>1) | ~(~0U >> 1);
		else
			x = (x>>1);
		n--;
	}
	return x;
} 
#include<stdio.h>
int main(void){
	unsigned x;
	int n;
	
	for(x = 0;x<700;x+=49)
		for(n=1;n<8;n++)
			printf("%u,%d:%u\n",x,n,rightrot(x,n)); 
	return 0;
}

