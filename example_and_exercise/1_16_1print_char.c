/* Time:20200426 
1-16 练习：修改打印最长文本行的主程序main。
使之可打印任意长度的行长度，并并尽可能多地打印文本
代码逻辑：从终端中读取字符， 判断文本行是否出现换行；
若字符数组len最后一个元素不是换行符，将输入字符复制到字符数组temp，更新目标文本行的最大字符数，并将
长文本行标志符置1；
若为换行符， ？？？ 

*/
/*
第一次程序练习,其中规则是不明确的，规范说，“修改主例程”，
但是输入行的真正长度只能通过修改*getline来确定 ，这将是我们需要做的， 
getline现在将返回该行的实际长度，而不是传递给它的数组中读取的字符数。
*/
/*keys:分块输出，可通过设置标志位实现
	主程序的逻辑是什么？ 
	读取字符， 
*/ 
#include<stdio.h>
#define MAXLINE 20

int getline(char s[],int lim);
void copy(char to[],char from[]);

int main(void){
	char line[MAXLINE];
	char longest[MAXLINE];
	char temp[MAXLINE];
	int len,max,prevmax,getmore;
	
	max = prevmax = getmore = 0;
	while((len = getline(line,MAXLINE)) > 0){  /*返回读取字符的长度*/
		if(line[len-1] != '\n'){		/*字符数组中len-1位置若不为换行符，说明一行字符没有全部读入字符数组*/ 
			if(getmore == 0)		/*一行字符未读完，将已读数组line赋值给temp*/ 
				copy(temp,line);	/*将已读字符保存至temp*/	 
			prevmax += len;		/*更新读入数组prevmax的值*/
			if(max < prevmax)
				max = prevmax;		/*更新一行字符最大长度*/ 
			getmore = 1;		/*更长文本行标志符*/ 
		}
		else{								/*输入字符结尾为换行符*/ 
			if(getmore == 1){
				if(max < prevmax + len){
					max = prevmax + len;	/*更新文本行字符的最大长度*/ 
					copy(longest,temp);		/*将temp元素赋值到longest*/ 
					longest[MAXLINE - 2]= '\n';
				}
				getmore = 0;
			}
			else if(max < len){	/*当前输入字符长度大于以前输入字符最大长度，则更新最大值及数组*/
				max = len;
				copy(longest,line);
			}
			prevmax = 0;
		}
	}
	/*等待字符全部输入完，再打印最长文本行？*/ 
	if(max >0){
		printf("%s",longest);
		printf("len = %d\n",max);
	}
	return 0;
} 

int getline(char s[],int lim){
	int c,i;
	
	for(i = 0;i<lim-1 && ((c = getchar()) != EOF && c != '\n');
	++i) 
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}else if(c == EOF && i>0){
		/*gotta do something about no newline preceding EOF*/
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[],char from[]){
	int i;
	
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}

/*
asdfasdfasd
asdfasdf
asdfasdf
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
^Z
aaaaaaaaaaaaaaaaaa
len = 62

--------------------------------
Process exited after 12.63 seconds with return value 0
请按任意键继续. . .


*/ 
