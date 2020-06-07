/*1_6:test_getchar.c 验证表达式getchar != EOF 的值是0还是1*/
#include<stdio.h>
#include<string.h>

#define M 100
main(){
//	char str[M];
	int c; 
	/*不等于运算符的优先级高于赋值运算，所以先指向！= 后在执行=*/
	if(c = getchar() !=EOF){  //c = getchar() !=EOF等价于c = (getchar() !=EOF)
		printf("1\n");
		putchar(c); //写字符c到stdout，在内部，字符在写入前辈转换到unsigned char等价于putc(c,stdout); 
//		printf("%c",c);
	}else{
		printf("0\n");
	}
	printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);
	printf("EOF:%d\n",EOF);
	return 0;
}
/*
aasdfasdf
1
EOF:-1
*/
 
