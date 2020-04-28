/*
Time:20200427
author:K&R
ex1-17:写程序打印长度大于80个字符的所有输入行
代码逻辑：
从终端输入字符，判断输入字符长度（是否大于80），
单次打印，则保存一次打印一次
全部打印，等所有输入字符结束之后，依次打印 
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
		if(status == 1){	/*标志位为1时，程序处理输入大于80部分的字符*/ 
			status = copyline(buffer);
		}
	}
	return 0;
}
/*代码逻辑：从终端读取字符，将非文件结束符、换行符保证至buffer*/
int readbuffer(char *buffer){
	size_t i=0;
	int c;
	while(i < MINLENGTH){
		c = getchar();
		if(c == EOF) return -1;	/*status为-1，遇到文件结束符，循环结束*/ 
		if (c == '\n') return 0; /*标志位status不为-1 继续读取*/ 
		buffer[i++] = c;	/*将输入的前80个字符保存至buffer中*/ 
	}
	return 1;	/*当i递增至80跳出循环，返回1*/ 
}
	/*代码逻辑：保存出前80个字符，输出大于80之后的字符*/ 
int copyline(char *buffer){
	size_t i;
	int c;
	int status = 1;
	/*输出大于80字符的部分字符*/ 
	for(i = 0;i<MINLENGTH;i++){
		putchar(buffer[i]);}	/*打印字符串最大长度小于80的字符串*/
	while(status == 1){
		c = getchar();		/*读取字符*/ 
		if(c == EOF)		/*遇到文件结束符*/ 
			status = -1;
		else if(c == '\n')	/*遇到换行*/ 
			status = 0;
		else
			putchar(c);		/*其他情况输出字符串*/ 
	}
	putchar('\n');
	return status;
}
