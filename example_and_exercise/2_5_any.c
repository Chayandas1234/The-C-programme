/*2_5_any.c
any(s1,s2),将字符串s2中任一字符在字符串s1中第一次出现的位置返回；
若不存在则返回-1；
库函数strpbrk功能一样，但它返回的是指向该位置的指针 
*/
#include<stdio.h>
#include<string.h>

int any(char s1[],char s2[]){
	int i,j,pos;
	
	pos = -1;
	
	for(i=0;pos==-1 && s1[i] != '\0';i++){
		for(j=0;pos==-1 && s2[i] !='\0';j++){
			if(s2[j]==s1[i]){
				pos = i;
			}
		}
	}
	return pos;
}

int main(void){
	char *leftstr[] =
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
	    "xylophonically",
	    "youthfulness",
	    "zoologically"
 	};
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
	/*
	*字符数组char s[]="asdfasdf";leftstr[]指某个元素；
	*字符指针数组 char *leftstr[]={"asdfa","asdf",...}; 
	*指针数组元素存放是对应字符的首地址，*(left+下标)：数组下标对应字符串的值
	*char *str = "asdfasdf";  str表示字符串的地址，*(str+i)表示字符串中第i-1个元素值； 
	*指针数组使用指针来操作数组下标 
	*/
	printf("%s \n%s\n %c\n %d\n",*leftstr,*(leftstr+4),*(*(leftstr+4)+2),leftstr[1]-leftstr[0]);
	
	size_t numlefts = sizeof leftstr / sizeof leftstr[0];
	size_t numrights = sizeof rightstr / sizeof rightstr[0];
	size_t left = 0;
	size_t right = 0;
	
	int passed = 0;
	int failed = 0;
	
	int pos = -1;
	char *ptr = NULL;
	
	for(left = 0;left<numlefts;left++){
		for(right = 0;right<numrights;right){
			pos = any(leftstr[left],rightstr[right]);
			ptr = strpbrk(leftstr[left],rightstr[right]);
			
			if(-1==pos){
				if(ptr != NULL){
					printf("Test %d/%d failed.\n",left,right);
					++failed;
				}
				else{
					printf("Test %d/%d passed.\n",left,right);
					++passed;					
				}
			}
			else{
				//ptr:返回指向该位置的指针， 
				if(ptr - leftstr[left] == pos){
					printf("Test %d/%d passed.\n",left,right);
					++passed;					
				}
				else{
					printf("Test %d/%d failed.\n",left,right);
					++failed;					
				}
			}
		}
	}
	printf("\n\nTotal passed %d,fails %d,total tests %d\n",
			passed,
			failed,
			passed+failed);
	
	return 0;
}
