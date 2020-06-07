/*2_6_setbits.c
编写一个函数setbits(x,p,n,y)，返回对x执行如下操作后的结果值
将x中从p位开始的n个（二进制）位设置为y中最右边n位的值，x其余位保持不变
new:将x转为二进制数？ 设定p、n的值，将y中最右边n位的值替换x中p开开始的n位，
得到新的n后，计算n的值 
*/ 
#include<stdio.h>

unsigned setbits(unsigned x,int p, int n,unsigned y){
	//usigned int  32位取值范围0-4294967295 带符号的int范围-2147483648-2147483647 
//	printf("%d\n",sizeof(unsigned int));//4
	// p占4个字节，转化为二进制则为32位，???
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
			//i中p为开始的n个二进制 
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

