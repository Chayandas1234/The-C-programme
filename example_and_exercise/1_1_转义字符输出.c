/*1-1、1-2：printf_escape_sequences.c:转义字符输出*/
#include <stdio.h>
main()
{
	printf("hello,world\c\n");//hello,worldc
 //[警告]未知转义序列：'\c'
 /*
    \n (newline) 
	\t (tab) 
	\b (backspace) 
	\" (double quote) 
	\\ (backslash)
 */ 
/*注意非指定的转义序列调用未定义的行为，演示除了十六进制和八进制转义序列*/
	printf("Audible or alert. \a\n");//\a: 未输出？ 
	printf("Form feed. \f\f\n");//\f:输出个箭头 
	printf("This escape, \r,moves the \ractive position to the initial position of the current line.\n");//\r:不输出\r之前内容 
	printf("Vertical tab \v is tricky, as \vits behaviour is unspecified under ceratain conditiions.\n");//\v:输出一个小窗 
	/*
	hello,worldc
	Audible or alert.
	Form feed. 
	active position to the initial position of the current line.
	Vertical tab  is tricky, as its behaviour is unspecified under ceratain conditiions.
	*/
	
	return 0; 
}
