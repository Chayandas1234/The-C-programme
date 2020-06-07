/*2_9_bitcount.c
求对二的补码时，表达式x &=(x-1)可删除x中最右边值为1的一个二进制。
用该方法重写bitcount函数，以加快其执行速度。 
*/
unsigned bitcount(unsigned x){
	int b;
	
	for(b=0;x !=0;x>>1)
		if(x & 01)
			b++;
	return b;
//	return x &=(x-1);
} 

/*
若x为奇数，（x-1） 与x位表现形式相同 ，除了（x-1）最右边位0，而x为1 ,在这种情况下， （x &（x-1））==(x-1) 
若x为偶数，（x-1）最右边位为1，而x为0， 
两位清除了x中最右边的1位和(x-1)中所有最右边的1位。
新版本代码如下 
*/ 
int bitcount(unsigned x){
	int b;
	
	for(b=0;x!=0;x &=(x-1))
		b++;
	return b;
} 
