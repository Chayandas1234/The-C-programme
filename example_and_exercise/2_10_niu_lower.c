/*2_10_lower.c
author:niuxiatong
time:20200523
重新编写将大写字母转换为小写字母的函数lower,并用条件表达式替代其中if-else结构 
*/
int lower(char ch){
	
	return ((90>= ch >=65)? (ch+32):-1);
	//涉及类型转换 
//	c += 32;
	 
//	return ch;
}

int main(void){
	
	int ch = lower('\t');
	printf("%d\n",ch);
	/*
	printf("%d\n",'A');//65 
	printf("%d\n",'a');//97  'a'-'A'=32;
	
	printf("%d\n",'Z');//90
	printf("%d\n",'z');//122*/
	return 0;
} 
