/*Time:20200426 
1.9 字符数组例程:打印最长文本行*/
/*代码逻辑：读入字符，保存到字符数组中并输出 
  本程序只是将输入字符打印出来，未实现打印最长文本行； 
*/ 
#include<stdio.h>
#define MAXLINE 1000	/*最大输出行的长度*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*打印最长输入行*/

int main(){
	int len;	/*输入行长度*/
	int max;	/*最大长度*/
	char line[MAXLINE];		/*输入行*/
	char longest[MAXLINE];	/*保存最长的句子*/
	
//	max = 0;
	while((len = getline(line,MAXLINE)) > 0){
		printf("len=%d\n",len); 
		if(len > MAXLINE){
			//erro
			printf("数组溢出"); 
		}

	if(len > 0)	/*打印输入行*/
		printf("%s",line);	/*按%s格式打印出句子*/ 
	} 
	return 0; 
} 

/*getline:读出一行字符输出到字符串，并返回其长度*/
int getline(char s[],int lim){	/*主函数传递的形参是字符数组名，通过操作数组下标可更改数组元素*/
	/*计算字符长度、*/
	int c,i;
	
	/*当单次输入字符大于MAXLINE时，会自动放入下一次写入*/ 
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c != '\n';++i)
		s[i] = c;
	if(c == '\n'){	/*判断句子是否换行，若出现换行符说明一行结束*/ 
		s[i] = c;
		++i;
	} 
	s[i] = '\0';	/*字符串常量将以字符数组形式存储，并以'\0'标志字符串的结束*/

	return i;
}


/*
asdfasdf
len=9
asdfasdf
asd
len=4
asd
asdfasdfasdf
len=13
asdfasdfasdf
assssssssssssssssssssss
len=24
assssssssssssssssssssss
asdfa
len=6
asdfa
asdfasdfasdf
len=13
asdfasdfasdf
^Z
*/
