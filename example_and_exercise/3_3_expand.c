/*3_3_expand.c
line79:内存错误或段错误 
编写函数expand(s1,s2),将字符串s1中类似于a-z一类
的速记符号在字符串s2中扩展为等价的完整列表abc...xyz.
该函数可以处理大小写字母和数字，并可以处理a-b-c、a-z0-9
与-a-z等类似的情况，作为前导和尾随的-字符原样排印。 

*/
#include<stdio.h>
#include<string.h>

void expand(char *s1,char *s2);

int main(void){
	char *s[] = {"a-z-","z-a-","-1-6-",
				"a-ee-a","a-R-L","1-9-1",
				"5-5",NULL};
	// char *s[]={"".""}; s是核心，[]优先级高于*，s与[]结合故char *s[]为字符指针数组,其中每个元素为指向字符串指针
//	即为每个字符串元素的首地址 ，s可看出二维的字符数组，一维的字符指针数组？ 
//	数组指针为 int (*p)[]; 
	printf("%s.\n",s[1]); ///"z-a-"		
	printf("%c.\n",s[1][0]); ///z
	char result[100];
	int i = 0;
	
	while(s[i]){
		//展开并打印数组s[]中的下一个字符串
		expand(result,s[i]);
		printf("Unexpanded: %s\n",s[i]);
		printf("Expand: %s\n",s[i]);
		++i;
	}	
	return 0;
}
//将s2复制给s1， 扩展范围：'a-z' 和'8-3'
void expand(char *s1,char *s2){
	static char upper_alph[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char lower_alph[27] = "abcdefghijklmnopqrstuvwxyz";
	static char digits[11] = "0123456789"; //为什么要多申请一个字节空间？
	
	char *start,*end,*p;
	int i=0;
	int j=0;
	
	while(s2[i]){
		switch(s2[i]){
		case '-':
			if(i==0 || s2[i+1] == '\0'){
				//'-'直接复制
				s1[j++] = '-';
				++i;
				break; 
			}
			else{
				/*
				char *str(const char  *str,int ch);str:指向待分析的空终止字节字符串的指针，ch：要搜索的字符 
				寻找ch，在str所指向的空终止字节字符串中首次出现位置， 
				终止空字符被认为是字符串的一部分，并且能在寻找'\0'时找到 ； 
				若str 找到的字符的指针，若未找到该字符则为空指针
				*/
				//start、end：字符指针 
				if((start = strchr(upper_alph,s2[i-1])) && (end = strchr(upper_alph,s2[i+1])))
					;
				else if(start = strchr(lower_alph,s2[i-1]) && (end = strchr(lower_alph,s2[i+1])))
					;
				else if(start = strchr(digits,s2[i-1]) && (end = strchr(digits,s2[i+1])))
					;
				else{
					//
					fprintf(stderr,"EX3_3:Mismatched operands '%c-%c'\n",s2[i-1],s2[i+1]);
					s1[j++] = s2[i-1];
					s1[j++] = s2[i+1];
					break;
				}
				//扩展范围
				p = start; //p所指向内存空间？ start?
//				while(p != end){
				while(p != NULL && p != end){
					//p为字符指针，s1字符指针:字符数组首地址 
					s1[j++] = *p;//s2[j++] = *p;内存错误或段错误？？？ 
					if(end > start)
						++p;
					else
						--p;
				} 
				s1[j++] = *p;
			}
			break;
		default:
			if(s2[i+1] == '-' && s2[i+2] != '\0'){
				//
				++i;
			} 
			else{
				//
				s1[j++] = s2[i++];
			}
			break;
		}
	} 
	s1[j++] = s2[i++];
} 

