/*1_18_delete_blanks_tabs.c
删除每个输入行末尾的空格及制表符，并删除完全是空格的行
	//定义变量
	//字符输入
	//主逻辑：提取输入行末尾的空格、制表符、然后删除
	//判断该行是否全为空格，若是删除该行 */
#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 1001

int advance(int pointer){
	if(pointer < MAXQUEUE -1)
		return pointer + 1;
	else
		return 0;
} 

int main(void){
	char blank[MAXQUEUE];
	int head,tail;
	int nospace,retval;
	int c;
//	int spaceJustPrinted;/*布尔：是最后一个打印的空格*/ 
	
	retval  = nospace = head = tail = 0;
	while((c = getchar())!= EOF){
		//从stdin读取为换行符 
		if(c == '\n'){
			head = tail = 0;
//			if(spaceJustPrinted == 1)
//				retval = EXIT_FAILURE;
			if(nospace)
				putchar('\n');//输出换行符 
//				spaceJustPrinted = 0;
			nospace = 0;	 
		}
		//从stdin读取为空格或制表符 
		else if(c == ' ' || c == '\t'){
			if(advance(head) == tail){	// 
				putchar(blank[tail]); //输出blank中的值 
				tail = advance(tail); //更新尾部的值 
				nospace = 1;
				retval = EXIT_FAILURE;
			}
			blank[head] = c;	// 将空格及制表符保存到blank[] 
			head = advance(head); //更新head值，若head没超出MAXQUEUE范围时，head +=1； 
		}
		//从stdin读取非空格 制表符及换行符时 
		else{
			while(head != tail){
				putchar(blank[tail]);//输出数组元素 空格 
				tail = advance(tail);
			}
			putchar(c);   //输出读入字符 
			nospace = 1;
		}
	}
	
	return retval;
} 
