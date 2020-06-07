/*2_4_delte_matche_string.c
*squeeze(s1,s2),将字符串s1中任何与字符串s2中字符匹配的字符否删除 
 
*/
#include<stdio.h>
#include<string.h>
#define LENGTH 100
/*删除字符串s1中s2的所有字符*/ 
int squeeze2(char s1[],char s2[]){
	int i,j,k;
	int instr2 = 0;
//	遍历数组s1[]元素是字符串 :leftstr[]
	for(i=j=0;s1[i] !='\0';i++)
	{
		instr2 = 0;
//		printf("1 instr2:%d\n",instr2); 
//		printf("s1[i]:%c\n",s1[i]); 
		for(k=0;s2[k] !='\0' && !instr2;k++){
//			printf("s2[k]:%c\n",s2[k]); //s2[]是一个字符串 
			if(s2[k] == s1[i]){
				instr2 = 1;
			}
		}
//		printf("2 instr2:%d\n",instr2); 
		if(!instr2){
		}
		s1[j] = '\0';
//		printf("s1[j]:%s\n",s1[j]); 
	 } 
} 
int main(void){
	//字符指针数组，每一元素是字符串对应的地址，类似数组首元地址 
	char *leftstr[]=
	{
		"",
	    "a",
	    "antidisestablishmentarianism",
	    "beautifications",
	    "characteristically",
	    "deterministically",
	    "electroencephalography",
	    "familiarisation",
	    "gastrointestinal",
	    "heterogeneousness",
	    "incomprehensibility",
	    "justifications",
	    "knowledgeable",
	    "lexicographically",
	    "microarchitectures",
	    "nondeterministically",
	    "organizationally",
	    "phenomenologically",
	    "quantifications",
	    "representationally",
	    "straightforwardness",
	    "telecommunications",
	    "uncontrollability",
	    "vulnerabilities",
	    "wholeheartedly",
	    "xylophonically", /* if there is such a word :-) */
	    "youthfulness",
	    "zoologically"	
	};
	printf("%d %d %d\n",leftstr[2],leftstr[1],leftstr[2]-leftstr[1]);
//	printf("%s\n",leftstr[1]);//a:输出文中第二行字符串 
//	printf("%c\n",leftstr[2][2]);//t:输出文中第二行第三个字符，类似二维数组 
	char *rightstr[]=
	{
		"",
	    "a",
	    "the",
	    "quick",
	    "brown",
	    "dog",
	    "jumps",
	    "over",
	    "lazy",
	    "fox",
	    "get",
	    "rid",
	    "of",
	    "windows",
	    "and",
	    "install",
	    "linux"
	};
	char buffer[32];
	size_t numlefts = sizeof leftstr / sizeof leftstr[0];
	size_t numrights = sizeof rightstr /sizeof rightstr[0];
	size_t left = 0;
	size_t right = 0;
	/*
	*char *strcpy( char *dest, const char *src );
	*复制str所指向的空终止字节字符串，包含终止符，到首元素为的dest所指的字符数组 
	*/ 
	for(left = 0;left < numlefts;left++){
		for(right = 0;right < numrights;right++){
			strcpy(buffer,leftstr[left]);//和内层循环没关系？ 
			squeeze2(buffer,rightstr[right]);//rightstr[right]是一个字符串 
			printf("[%s] - [%s] = [%s]\n",leftstr[left],rightstr[right],buffer);
		}
	}
	return 0;
} 

