/*2_8_rightrot.c
函数 rightrot（x,n）,返回x循环右移
（即从最右端移出的位将从最左端移入）n（二进制）后所得到的的值； 
左移:a<<5 左移5位，低位补0、
右移：分逻辑右移及算术右移
逻辑右移：移位后高位补0
算术右移：若符号位1，则移入均为1，若符号位为0，则移入位均为0； 
*/ 
unsigned rightrot(unsigned x,unsigned n){
	while(n>0){
		if((x & 1) == 1)  // x!=0 ？？？ 
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

