/*
编写一个程序以确定分别由signed及unsigned限定的char、short、int
与long类型变量的取值范围。采用打印标准头文件的相应值以及直接计算两种方式实现
后一种方法(直接计算)的实现较困难一些，因为确定各种浮点类型的取值范围； 
*/
#include<stdio.h>
#include<limits.h>

int main(){
	printf("size of Char %d\n",CHAR_BIT); 
	printf("size of Char Max %d\n",CHAR_MAX); 
	printf("size of Char min %d\n",CHAR_MIN); 
	printf("size of int min %d\n",INT_MIN); 
	printf("size of int max %d\n",INT_MAX); 
	printf("size of long min %d\n",LONG_MIN); 
	printf("size of long max %d\n",LONG_MAX); 
	printf("size of short min %d\n",LONG_MIN); 
	printf("size of short max %d\n",LONG_MAX); 
	printf("size of unsigned char %u\n",UCHAR_MAX); 
	printf("size of unsigned long %u\n",LONG_MAX); 
	printf("size of unsigned int %u\n",INT_MAX); 
	printf("size of unsigned short %u\n",USHRT_MAX); 

	return 0;
} 
/*
size of Char 8
size of Char Max 127
size of Char min -128
size of int min -2147483648
size of int max 2147483647
size of long min -2147483648
size of long max 2147483647
size of short min -2147483648
size of short max 2147483647
size of unsigned char 255
size of unsigned long 2147483647
size of unsigned int 2147483647
size of unsigned short 65535

*/
