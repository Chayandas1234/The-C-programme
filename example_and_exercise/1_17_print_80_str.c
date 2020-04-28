/*
Time:20200427
author:K&R
ex1-17:д�����ӡ���ȴ���80���ַ�������������
�����߼���
���ն������ַ����ж������ַ����ȣ��Ƿ����80����
���δ�ӡ���򱣴�һ�δ�ӡһ��
ȫ����ӡ�������������ַ�����֮�����δ�ӡ 
*/ 
#include<stdio.h>
#define MINLENGTH 81

int readbuffer(char *buffer);
int copyline(char *buffer);
/**/ 
int main(void){
	char buffer[MINLENGTH];
	int status = 0;
	while(status != -1){
		status = readbuffer(buffer);
		if(status == 1){	/*��־λΪ1ʱ���������������80���ֵ��ַ�*/ 
			status = copyline(buffer);
		}
	}
	return 0;
}
/*�����߼������ն˶�ȡ�ַ��������ļ������������з���֤��buffer*/
int readbuffer(char *buffer){
	size_t i=0;
	int c;
	while(i < MINLENGTH){
		c = getchar();
		if(c == EOF) return -1;	/*statusΪ-1�������ļ���������ѭ������*/ 
		if (c == '\n') return 0; /*��־λstatus��Ϊ-1 ������ȡ*/ 
		buffer[i++] = c;	/*�������ǰ80���ַ�������buffer��*/ 
	}
	return 1;	/*��i������80����ѭ��������1*/ 
}
	/*�����߼��������ǰ80���ַ����������80֮����ַ�*/ 
int copyline(char *buffer){
	size_t i;
	int c;
	int status = 1;
	/*�������80�ַ��Ĳ����ַ�*/ 
	for(i = 0;i<MINLENGTH;i++){
		putchar(buffer[i]);}	/*��ӡ�ַ�����󳤶�С��80���ַ���*/
	while(status == 1){
		c = getchar();		/*��ȡ�ַ�*/ 
		if(c == EOF)		/*�����ļ�������*/ 
			status = -1;
		else if(c == '\n')	/*��������*/ 
			status = 0;
		else
			putchar(c);		/*�����������ַ���*/ 
	}
	putchar('\n');
	return status;
}
