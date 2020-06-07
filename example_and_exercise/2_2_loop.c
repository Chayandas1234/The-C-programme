/*2_2_loop.c
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
s[i] = c;
Q:在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句 
*/ 
#include<stdio.h>

#define MAX_STRLNG_LENGTH 100

int main(void){
	int i =0,
			lim = MAX_STRLNG_LENGTH,
			c;
	char s[MAX_STRLNG_LENGTH];
	
	while(i <(lim -1))
	{
		c = getchar();
		if(c == EOF)
			break;
		else if(c == '\n')
			break;
		s[i++] = c;
	}
	s[i] = '\0';	/*字符串结束符*/
	printf("%s\n",s);
	
	return 0;
} 
/*
//s a Category 1 solution from Craig Schroeder
#include<stdio.h>
#define lim 80

int main(){
	int i,c;
	char s[lim];
	
	//在？:的第一个操作数之后有一个序列点：
	for(i=0;i<lim-1 ? (c=getchar()) !='\n'? c != EOF:0:0;++i)
		s[i] = c;
		
	return s[i] ^=s[i]; //空终止并返回
}
*/

/*
//author:xiaotongNiu
//Time:20200517 
#include<stdio.h>
//#include<string.h>
#define MAX 100

int main(){
	int c,i;
	char s[MAX];

	for(i = 0;(c = getchar())!='\n';++i){
		if(i< MAX -1){
			if(c != EOF){
				s[i] = c;
			}
			else{
				break;	
			}
		}
		else{
			break;
		}
	}	
	s[i] = '\0';
	printf("%s\n",s);
	return 0;
}
//asdfasd asdf asdf
//asdfasd asdf asdf*/
