/*
��дһ��������ȷ���ֱ���signed��unsigned�޶���char��short��int
��long���ͱ�����ȡֵ��Χ�����ô�ӡ��׼ͷ�ļ�����Ӧֵ�Լ�ֱ�Ӽ������ַ�ʽʵ��
��һ�ַ���(ֱ�Ӽ���)��ʵ�ֽ�����һЩ����Ϊȷ�����ָ������͵�ȡֵ��Χ�� 
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
