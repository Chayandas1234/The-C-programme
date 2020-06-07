/*2_5_any.c
any(s1,s2),���ַ���s2����һ�ַ����ַ���s1�е�һ�γ��ֵ�λ�÷��أ�
���������򷵻�-1��
�⺯��strpbrk����һ�����������ص���ָ���λ�õ�ָ�� 
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
	*�ַ�����char s[]="asdfasdf";leftstr[]ָĳ��Ԫ�أ�
	*�ַ�ָ������ char *leftstr[]={"asdfa","asdf",...}; 
	*ָ������Ԫ�ش���Ƕ�Ӧ�ַ����׵�ַ��*(left+�±�)�������±��Ӧ�ַ�����ֵ
	*char *str = "asdfasdf";  str��ʾ�ַ����ĵ�ַ��*(str+i)��ʾ�ַ����е�i-1��Ԫ��ֵ�� 
	*ָ������ʹ��ָ�������������±� 
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
				//ptr:����ָ���λ�õ�ָ�룬 
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
