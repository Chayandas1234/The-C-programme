/*1_23_remove_comments.c
Q:删除C语言程序中所有的注释语句 
*/
#include<stdio.h>
#define MAXLINE 1000

char line[MAXLINE]; 
int getline(void);

int main(){
	int in_comment,len;
	int in_quote;//引号标志位 
	int t;
	
	in_comment = in_quote = t =0;
	while((len = getline())>0){
		t = 0;
		while(t < len){
			if(line[t] == '"')
				in_quote = 1;//引号标志位是什么意思？ 
			if (! in_quote)
			{
				if(line[t] == '/' && line[t+1] == '*')
				{
					t = t+2;//? 跳过/*两个字符 
					in_comment = 1;//注释标志位 
				}
				if(line[t] == '*' && line[t+1] == '/')
				{
					t += 2;
					in_comment = 0; //找出了注释位置后注释标志位复位 
				} 
				if(in_comment == 1)
				{
					t++;//找出注释后后面语句 
				}
				else{
					printf("%c",line[t]);
					t++;
				}
			}
			else{
				printf("%c",line[t]);
				t++;
			}
		}
	}
	
	return 0;
} 


int getline(void){
	int i,c;
	extern char line[];
	
	for(i =0;i<MAXLINE-1 && (c = getchar())!=EOF && c != '\n';++i){
		line[i] = c;
	}
	if(c == '\n'){
		line[i] = c;
		++i;//这里为什么要++i,不应该使用'\0'替换掉'\n'吗 
	}
	line[i] = '\0';
	
	return i;//返回读取字符长度 
} 
