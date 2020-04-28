/*
写一个程序将输入复制到输出的程序，将制表符替换为\t,回退符替换为\b,将反斜杠替换为\\,
将制表符和回退符显示出来； 
*/ 

#include<stdio.h>

int main(void){
	
	int c;
	while((c = getchar()) != EOF){
		if(c == '\t'){
			putchar('\\');
			putchar('t');
		}else if(c == '\b') 
		{
			putchar('\\');
			putchar('b');
		}else if(c == '\\'){
			putchar('\\');
			putchar('\\');
		}else{
			putchar(c);
		}	
	}
} 
/*
sdfq    sdf     sef\sdf \       \sd \
sdfq\tsdf\tsef\\sdf \\\t\\sd \\
^Z

*/
/*
//Erro
	int c;
	while((c = getchar()) != EOF){
		if(c == '\t'){
			putchar('\t');
		}else if(c == '\b') 
		{
			putchar('\b');
		}else if(c == '\\'){
			putchar('\\');
		}else{
			putchar(c);
		}	
	}
*/
