/*2_1_variablity_range.c
确定由signed及unsigned限定的char、short、int与long类型变量的取值范围‘
采用打印标准头文件中的相应值及直接计算两种方式实现 ，
后者中确定浮点数的取值范围，比较困难。 
*/
#include<stdio.h>
#include<limits.h>

int main(){
	//标准头文件中宏定义 
	printf("Size of Char %d \n",CHAR_BIT);
	printf("Size of Char Max %d \n",CHAR_MAX);
	printf("Size of Char Min %d \n",CHAR_MIN);
	printf("Size of Int Min %d \n",INT_MIN);
	printf("Size ofInt Max  %d\n",INT_MAX);
	printf("Size of Long Min %d \n",LONG_MIN);
	printf("Size of Long Max %d \n ",LONG_MAX);
	printf("Size of Short Min %d \n",SHRT_MIN);
	printf("Size of Short Max %d \n",SHRT_MAX);
	
	printf("Size of unsigned char %u \n",UCHAR_MAX);
	printf("Size of unsigned long %u \n",ULONG_MAX);
	printf("Size of unsigned int %u \n",UINT_MAX);
	printf("Size of unsigned short %u \n",USHRT_MAX);
	//直接计算
	printf("Size of char %d\n",-(char)((unsigned char)~0 >>1)); 
	printf("Size of int %d\n",-((unsigned int)~0>>1)); 
	/*
	https://www.cnblogs.com/roma823/archive/2011/04/27/2101251.html
	      1,  <limits.h>包含了定义char int short long类型取值的最大值和最小值用常量表示（例如SCHAR_MIN = -128）

            所以直接打印即可。

      2,  如果要自己计算的话，则需要用到按位运算符~，>>，对于-(char)((unsigned char)~0 >> 1)解释：

           a： (unsigned char)~0用二进制表示为：11111111

           b： (unsigned char)~0 >> 1，将(unsigned char)~0逻辑右移1位，结果为：01111111

           c： (char)((unsigned char)~0 >> 1)，将((unsigned char)~0 >> 1)由无符号类型强制转换为有符号类型

           d： -(char)((unsigned char)~0 >> 1)，得到的二进制结果为11111111，最高位为符号为，对应的十进制

                  数为：-127

      3,  Q：为什么SCHAR_MIN = -128，而自己通过计算得到的char型变量的最小值为-127呢？

           A：绝大部分机器采用补码方式表示有符号整数，

                [-1]补码 = 11111111 ？

                -1 取绝对值 1

                  1 原码 00000001

                  1 反码 11111110

                  反码+1 11111111

                  符号位置为1 11111111 <-- -1的补码

               依次类推，[-2]补码 = 11111110 [-3]补码 = 11111101 ... [-128]补码 = 10000000，

               故char型最小值为-128。

               而自己通过计算得到的-127仅仅是将127取负作为最小值，其实在机器中它应该是倒数第二小值
	*/
	return 0;
} 
/*
Size of Char 8
Size of Char Max 127
Size of Char Min -128
Size of Int Min -2147483648
Size ofInt Max  2147483647
Size of Long Min -2147483648
Size of Long Max 2147483647
 Size of Short Min -32768
Size of Short Max 32767
Size of unsigned char 255
Size of unsigned long 4294967295
Size of unsigned int 4294967295
Size of unsigned short 65535
*/
