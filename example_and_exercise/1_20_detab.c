/*1_20_detab.c:�������е��Ʊ���滻���ʵ���Ŀ�Ŀո�
ʹ�ո��������һ���Ʊ����ֹλ�ĵط�
���趨�Ʊ����ֹλ��λ�ù̶�����ÿ��n�оͻ����һ���Ʊ����ֹλ��nӦΪ�������ǳ����� 
�ڻش����nӦ���ǿɱ�Ļ��ǹ̶�����Ӧ���ǿɱ�ģ�
�Ա�����������ʱ�޸�ֵ������ͨ�������в����޸ģ�������Ҫ���±���*/
/*�Ʊ������ʾռ��һ���Ŀո����������ǽ�ÿ�а�������ļ�����зֲ�
�硰�Ʊ������˸��ո񡱣�����˵����˸��ո񣿣������ǽ�����ƶ�����ӽ�8������λ��
ʹ�ú��������Ӵ˴���ʼ �������������ݶ��������Ʊ�����������������ֻ���ڵ�9�У���17�С���25��...��ʼ
//�Ʊ��ԭ�� 
#include <stdio.h>
int main(){
	printf("1234567\t0\n");
	printf("12345678\t0\n");
	printf("123456789\t0\n");
	printf("12345678\t0\t9\n");
 
 return 0;
} 
1234567 0
12345678        0
123456789       0
12345678        0       9
���Ѿ����˵�8λ��Ӧ���ǵ�����17�� 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFFER 1024
#define SPACE '*'
#define TAB '\t'
// 
int CalculateNumberOfSpaces(int Offset, int TabSize)
{
	return TabSize - (Offset % TabSize);//С��5��������5������������� 
}
/*K&R^s getline() function from p29*/
int getline(char s[],int lim){
	int c,i;
	//��ȡһ���ַ���������������±ꡢgetchar��stdin��ȡ�ַ����ַ���Ϊ���з� 
	for(i = 0;i<lim-1 && (c = getchar()) != EOF && c != '\n';++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
} 
int main(void){
	char Buffer[MAX_BUFFER];
	int TabSize = 5; 
	int i,j,k,l;
	//��ȡ�ַ����ж��Ʊ��λ�ã��������滻Ϊ�ո� 
	while(getline(Buffer,MAX_BUFFER) > 0)
	{
		for(i = 0,l = 0;Buffer[i] != '\0';i++)
		{
			if(Buffer[i] == TAB)
			{
				//j��Ϊ��ӡ�ո�����Ϊʲô����˱���l����ո��� 
				j = CalculateNumberOfSpaces(l,TabSize);//(1,4)
				for(k = 0;k<j;k++)
				{
					//���j-1���ո� 
					putchar(SPACE);
					l++;//ͳ���ַ��Ϳո������������ʲô�ã� 
				}
			}
			else
			{
				putchar(Buffer[i]);
				l++;//���벻ΪTAB���ַ���l�Լ�1 
			}
		  }  
	}
	
	return 0;
} 
/*
asdfasdf        asdfa   asdf    asdf
asdfasdf *asdfa*****asdf*asdf
*/
/*
@New:��������ַ����뵽���飬���������ҳ��Ʊ������sizeof('\t')�滻Ϊ�ո�
'\t'ռ��4���ֽڣ�ÿ��tab��Ҫ���ĸ��ո��滻������������չ���� array_blank[len+mun*4-1]
#include<stdio.h>
#define MAX 1024
int getline(char s[],int len){
	int c,i;
	
	for(i=0; i<len-1 && (c = getchar())!= EOF;i++) //c != '\n'
	{
		s[i] = c;
	}
	if(c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int main(void){
	//printf("%d\n",sizeof('\t'));
	char array[MAX];
	char array_blank[MAX];
	char a[5];
	a[0] = '\t';
	int i,j,n;
	i = j =0;
	printf("t:%c\n",a[0]);
	while(getline(array,sizeof(array)) > 0){
		if(array[i] != '\t' && i < MAX && j< MAX){
			array_blank[j] = array[i];
			j++,i++;
		}
		else{
//			if(j < MAX)
			for(n=0;n<4;n++){
				if(j < MAX)
					array_blank[j++] =' ';
				else
					break; 
			}
			
		}
	}	
//	array_blank[j++] = '\0';
	printf("%s",array_blank);
	return 0;
}*/
