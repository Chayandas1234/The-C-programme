/*
дһ���������븴�Ƶ�����ĳ��򣬽��Ʊ���滻Ϊ\t,���˷��滻Ϊ\b,����б���滻Ϊ\\,
���Ʊ���ͻ��˷���ʾ������ 
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
