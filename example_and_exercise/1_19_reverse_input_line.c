/*1_19_reverse_input_line.c���������ַ���s�е��ַ�˳��ߵ�����*/
/*
@new���������ַ��������������У�Ȼ��������
�������ַ������ڵ������У�Ȼ���ٵ��� 
*/
#include<stdio.h>
#define MAX_LINE 1024
//�滻�ַ������л��з� 
void discardnewline(char s[]){
	int i;
	for(i = 0;s[i] != '\0';i++)
	{
		if(s[i] == '\n')
			s[i] = '\0';
	}
}
//�ַ��������� 
int reverse(char s[])
{
	char ch;
	int i,j;
	
	for(j=0;s[j] != '\0';j++){
	}
	--j;//����߽� 
	//������ǰ��Ԫ�ؽ��н��� 
	for(i=0;i<j;i++){
		ch = s[i];
		s[i] = s[j];
		s[j] = ch;
		--j;
	}
	return 0;
}
//�����ַ� 
int getline(char s[],int lim){
	int c,i;
	//�����ַ�����С�����鷶Χ����ȡ�ַ����������з���ÿ�д��� 
	for(i=0;i<lim-1 && (c = getchar())!= EOF && c != '\n';++i)
	{
		s[i] = c;//����stdin��ȡ���ַ���ֵ������ 
	}
	if(c == '\n') //�����ȡ�Ļ��з���ʹ���ļ��ַ�����β���滻���з� 
		s[i++] = c;
	s[i] = '\0';
	return i; //���ش洢�ַ�����ĳ��� 
}
int main(void){
	char line[MAX_LINE];
	
	while(getline(line,sizeof(line)) > 0){
		discardnewline(line);
		reverse(line);
		printf("%s\n",line);
	}
	
	return 0;
} 
