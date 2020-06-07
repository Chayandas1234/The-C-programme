/*2_1_variablity_range.c
ȷ����signed��unsigned�޶���char��short��int��long���ͱ�����ȡֵ��Χ��
���ô�ӡ��׼ͷ�ļ��е���Ӧֵ��ֱ�Ӽ������ַ�ʽʵ�� ��
������ȷ����������ȡֵ��Χ���Ƚ����ѡ� 
*/
#include<stdio.h>
#include<limits.h>

int main(){
	//��׼ͷ�ļ��к궨�� 
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
	//ֱ�Ӽ���
	printf("Size of char %d\n",-(char)((unsigned char)~0 >>1)); 
	printf("Size of int %d\n",-((unsigned int)~0>>1)); 
	/*
	https://www.cnblogs.com/roma823/archive/2011/04/27/2101251.html
	      1,  <limits.h>�����˶���char int short long����ȡֵ�����ֵ����Сֵ�ó�����ʾ������SCHAR_MIN = -128��

            ����ֱ�Ӵ�ӡ���ɡ�

      2,  ���Ҫ�Լ�����Ļ�������Ҫ�õ���λ�����~��>>������-(char)((unsigned char)~0 >> 1)���ͣ�

           a�� (unsigned char)~0�ö����Ʊ�ʾΪ��11111111

           b�� (unsigned char)~0 >> 1����(unsigned char)~0�߼�����1λ�����Ϊ��01111111

           c�� (char)((unsigned char)~0 >> 1)����((unsigned char)~0 >> 1)���޷�������ǿ��ת��Ϊ�з�������

           d�� -(char)((unsigned char)~0 >> 1)���õ��Ķ����ƽ��Ϊ11111111�����λΪ����Ϊ����Ӧ��ʮ����

                  ��Ϊ��-127

      3,  Q��ΪʲôSCHAR_MIN = -128�����Լ�ͨ������õ���char�ͱ�������СֵΪ-127�أ�

           A�����󲿷ֻ������ò��뷽ʽ��ʾ�з���������

                [-1]���� = 11111111 ��

                -1 ȡ����ֵ 1

                  1 ԭ�� 00000001

                  1 ���� 11111110

                  ����+1 11111111

                  ����λ��Ϊ1 11111111 <-- -1�Ĳ���

               �������ƣ�[-2]���� = 11111110 [-3]���� = 11111101 ... [-128]���� = 10000000��

               ��char����СֵΪ-128��

               ���Լ�ͨ������õ���-127�����ǽ�127ȡ����Ϊ��Сֵ����ʵ�ڻ�������Ӧ���ǵ����ڶ�Сֵ
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
