#include <stdio.h>
/*
int main(void)
{
  int c;
  int inspace;
 
  inspace = 0;
  while((c = getchar()) != EOF)
  {
    if(c == ' ')
    {
      if(inspace == 0)
      {
        inspace = 1;
        putchar(c);
      }
    }
 
    //* We haven't met 'else' yet, so we have to be a little clumsy 
    if(c != ' ')
    {
      inspace = 0;
      putchar(c);
    }
  }
 
  return 0;
}*/
 /*
 a d a d  a a
a d a d a a
asd     asd
asd asd


sdf
sdf
^Z
 */
/*写将输入复制到输出的程序，将其中连续空格用一个空格代替
输入复制到输出？替换连续空格
复制：一个字符一个字符复制？连续？大于等于2的空格都要替换
strcopy?
参考：这里提议不是改变输入的原始内容，是改变输出字符
将输出分为两种，一种输出空格， 一种输出其他字符 
*/
//延时：怎么用一个空格替换原输入中的多个连续的空格？？ 
int main(void){
	
	int blanks,c;
	blanks = 0;
	while((c = getchar())!= EOF){
		if(c == ' '){
			if(blanks == 0){ //通过blanks值来判断是否符合输出条件 
				blanks = 1;	//将blanks值赋值为1，当遇到连续空格只输出一次 
				putchar(c);
			} 
		}else if(c != ' '){
			blanks = 0;
			putchar(c);
		} 
		
	} 

} 
/*
a d d  ad
a d d ad
asd  asd    asd         d
asd asd asd     d
sd
^Z
*/
