/*2_5_any.c
author:xiaotongNiu
time:20200519 
any(s1,s2),���ַ���s2����һ�ַ����ַ���s1�е�һ�γ��ֵ�λ�÷��أ�
���������򷵻�-1��
�⺯��strpbrk����һ�����������ص���ָ���λ�õ�ָ�� 
*/
#include<stdio.h>
#include<string.h>
#define STRLEN 100
//��������ֵ��ָ�룬�ַ��������飿 
int any(char *s1,char *s2,int *position){
	int i,j,flag;
	flag = 0;
//	printf("%s\n",s1);
	for(i=0;i<strlen(s1);i++){
		for(j=0;j<strlen(s2);j++){
			if(s1[i] == s2[j]){
				position[i] = j;
				flag = 1;
				printf("%d\n",j);
			}
//			else
//				printf("-1\n");	
		}
	}
	
	if(flag){
		return 0;
	}
	else
		return -1;
}

int main(){
	int i,j,flag;
	
	char s1[STRLEN] = "asdfhjklasdf";
	char s2[STRLEN] = "qwerupoiasdb";
	int position[STRLEN];
//	int strlen = STRLEN;

	flag = any(s1,s2,position);
//	if(flag == -1){
//		printf("-1") 
//	} 
	
	return 0;
} 
