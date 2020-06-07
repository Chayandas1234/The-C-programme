/*1_21_entab.c:将空格串替换为最少数量的制表符和空格，但保持单词之间的间隔不变*/
#include<stdio.h>

#define MAXLINE 1000 /*输入行最大尺度*/
#define TAB2SPACE 4 /*4 spaces to a tab*/

char line[MAXLINE]; /*输出行字符串*/
int getline(void);	/*taken from the KnR book*/

int main(void){
	int i,t;
	int spacecount,len;
	
	while((len = getline()) >0)
	{
		spacecount = 0;
		for(i = 0;i<len;i++){
			if(line[i] == ' ')
				spacecount++; /*统计空格数*/
			if(line[i] != ' ')
				spacecount = 0; /*值复位*/
			if(spacecount == TAB2SPACE) /*有足够的空格替换制表符*/
			{
				/*移除4个空格，使用它们替换1个制表符，使用空格替换制表符？*/
				i -= 3;
				len -= 3;
				line[i] = '\t';
				/*使用一个制表符替换4个空格， 数组范围需进一步缩小*/
				for(t = i+1;t<len;t++)
					line[t] = line[t+3];
				spacecount = 0; //空格只复位 
				line[len] = '\0'; 
			
			} 
			/*奇怪当空格数小于4怎么处理，如空格串中空格数为3时
			空格数小于4不做替换，即使用最少数量的制表符和空格替换空格串 
			*/ 
		}
		printf("%s",line);
	}
	return 0;
}
/*从stdin读取一个字符*/ 
int getline(void){
	int c,i;
	extern char line[];/*表示外部全局变量*/ 
	
	for(i = 0;i<MAXLINE-1 && (c=getchar())!= EOF && c !='\n';++i)
		line[i] = c;
	if(c == '\n'){
		line[i] =c;
		++i;
	}
	line[i] = '\0';
	return i;
}
