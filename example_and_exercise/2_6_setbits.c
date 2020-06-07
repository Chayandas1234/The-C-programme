/*2_6_setbits.c
��дһ������setbits(x,p,n,y)�����ض�xִ�����²�����Ľ��ֵ
��x�д�pλ��ʼ��n���������ƣ�λ����Ϊy�����ұ�nλ��ֵ��x����λ���ֲ���
new:��xתΪ���������� �趨p��n��ֵ����y�����ұ�nλ��ֵ�滻x��p����ʼ��nλ��
�õ��µ�n�󣬼���n��ֵ 
*/ 
#include<stdio.h>

unsigned setbits(unsigned x,int p, int n,unsigned y){
	//usigned int  32λȡֵ��Χ0-4294967295 �����ŵ�int��Χ-2147483648-2147483647 
//	printf("%d\n",sizeof(unsigned int));//4
	// pռ4���ֽڣ�ת��Ϊ��������Ϊ32λ��???
	return (x &((~0<<(p+1)) | (~(~0 <<(p+1-n))))| ((y &~(~0<<n)) << (p+1-n)));
}

int main(void){
	unsigned i;
	unsigned j;
	unsigned k;
	int p;
	int n;
	
	for(i=0;i<30000;i+=511){
		for(j=0;j<1000;j+=37){
			//i��pΪ��ʼ��n�������� 
			for(p=0;p<16;p++){
				for(n=1;n<=p+1;n++){
					k = setbits(i,p,n,j);
7					printf("setbits(%u,%d,%d,%u) = %u\n",i,p,n,j,k);
				}
			}
		}
	}
	return 0;
}

