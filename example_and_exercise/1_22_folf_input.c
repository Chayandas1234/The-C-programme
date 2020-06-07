/*1_22_folf_input.c
把较长的输入行“折”成短一些的两行或多行，
折行的位置在输入行的第n列之前的最后一个非空格之后；
保证程序智能第处理输入行很长以及在指定的列前没有空格或制表符时的情况； 
*/ 
#include<stdio.h>
#define MAXLINE 1000

char line[MAXLINE];
int getline(void);

int main(){
	int t,len;
	int location,spaceholder;
	const int FOLDLENGTH = 70;/*一行最大长度*/
	
	while((len = getline()) > 0)
	{
		if(len < FOLDLENGTH){  //行字符长小于 FOLDLENGTH，不同折行，就一行 
		}
		else{
			/*对于一个很长的一行字符，通过替换空格附近的字符，来折出新的一行*/
			t = 0;
			location = 0;
			while(t < len){
				if(line[t] == ' ')  
					spaceholder = t;//记录空格字符的位置 
				if(location == FOLDLENGTH){
					line[spaceholder] = '\n';//当输入字符长度大于等于FOLDLENGTH，使用换行替换空格，实现换行 
					location = 0;//重新开始他统计下一行 
				}
				location++;//
				t++;//更新字符位置 
				printf("%d,%d ",location,t);
			}
		}
		printf("%s",line);
	}
	return 0;
}



/*从stdin一个一个字符读取*/ 
int getline(void)
{
	int c,i;
	extern char line[];
//	i=0;
//	while((c = getchar()) != EOF){} 
	for(i = 0;i<MAXLINE-1 && (c = getchar())!= EOF && c != '\n';++i){
		line[i] = c;
	}
	if(c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
} 

/*
const int FOLDLENGTH = 20;
asasaasasasasasasasas  asasasasasasasasas a asasasasasasasasasasasas  asas
sasaasasasasasasasas
asasasasasasasasas a
asasasasasasasasasasasas  asas
*/

