/*1-1��1-2��printf_escape_sequences.c:ת���ַ����*/
#include <stdio.h>
main()
{
	printf("hello,world\c\n");//hello,worldc
 //[����]δ֪ת�����У�'\c'
 /*
    \n (newline) 
	\t (tab) 
	\b (backspace) 
	\" (double quote) 
	\\ (backslash)
 */ 
/*ע���ָ����ת�����е���δ�������Ϊ����ʾ����ʮ�����ƺͰ˽���ת������*/
	printf("Audible or alert. \a\n");//\a: δ����� 
	printf("Form feed. \f\f\n");//\f:�������ͷ 
	printf("This escape, \r,moves the \ractive position to the initial position of the current line.\n");//\r:�����\r֮ǰ���� 
	printf("Vertical tab \v is tricky, as \vits behaviour is unspecified under ceratain conditiions.\n");//\v:���һ��С�� 
	/*
	hello,worldc
	Audible or alert.
	Form feed. 
	active position to the initial position of the current line.
	Vertical tab  is tricky, as its behaviour is unspecified under ceratain conditiions.
	*/
	
	return 0; 
}
