/*1_6:test_getchar.c ��֤���ʽgetchar != EOF ��ֵ��0����1*/
#include<stdio.h>
#include<string.h>

#define M 100
main(){
//	char str[M];
	int c; 
	/*����������������ȼ����ڸ�ֵ���㣬������ָ��= ����ִ��=*/
	if(c = getchar() !=EOF){  //c = getchar() !=EOF�ȼ���c = (getchar() !=EOF)
		printf("1\n");
		putchar(c); //д�ַ�c��stdout�����ڲ����ַ���д��ǰ��ת����unsigned char�ȼ���putc(c,stdout); 
//		printf("%c",c);
	}else{
		printf("0\n");
	}
	printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);
	printf("EOF:%d\n",EOF);
	return 0;
}
/*
aasdfasdf
1
EOF:-1
*/
 
