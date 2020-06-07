/*1_19_reverse_input_line.c：将输入字符串s中的字符顺序颠倒过来*/
/*
@new：将输入字符串保存至数组中，然后做倒序
将输入字符串存在到链表中，然后再倒序 
*/
#include<stdio.h>
#define MAX_LINE 1024
//替换字符数组中换行符 
void discardnewline(char s[]){
	int i;
	for(i = 0;s[i] != '\0';i++)
	{
		if(s[i] == '\n')
			s[i] = '\0';
	}
}
//字符数组逆序 
int reverse(char s[])
{
	char ch;
	int i,j;
	
	for(j=0;s[j] != '\0';j++){
	}
	--j;//数组边界 
	//将数组前后元素进行交换 
	for(i=0;i<j;i++){
		ch = s[i];
		s[i] = s[j];
		s[j] = ch;
		--j;
	}
	return 0;
}
//输入字符 
int getline(char s[],int lim){
	int c,i;
	//输入字符长度小于数组范围，读取字符条件，换行符按每行处理， 
	for(i=0;i<lim-1 && (c = getchar())!= EOF && c != '\n';++i)
	{
		s[i] = c;//将从stdin读取的字符赋值给数组 
	}
	if(c == '\n') //处理读取的换行符，使用文件字符串结尾符替换换行符 
		s[i++] = c;
	s[i] = '\0';
	return i; //返回存储字符数组的长度 
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
