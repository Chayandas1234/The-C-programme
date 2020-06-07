/*2_10_lower.c 
���±�д����д��ĸת��ΪСд��ĸ�ĺ���lower,�����������ʽ�������if-else�ṹ 
*/
#include<stdio.h>
#include<string.h>

#define TEST  
#define ORIGINAL 0
#define  SOLUTION 1
#define PORTABLE_SOULTION 0

#if ORIGINAL
/*lower:convert c to lower case,ASCII only*/
int lower(int c){
	if(c >='A' && c <= 'Z')
		return c+'a'-'A';
	else
		return c;
} 
#endif

#if SOLUTION
/*lower:convert c to lower case,ASCII only*/
int lower(int c){
	return c>='A' && c<='Z'? c+'a'-'A' : c; 
}
#endif

#if  PORTABLE_SOULTION
/*lower:convert c to lower case,ASCII only*/
int lower(int c){
	char *Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *Lowercase = "abcdefghijklmnoprstuvwxyz";
	char *p = NULL;
	
	return NULL==(p=strchr(Uppercase,c)? c:*(Lowercase+(p-Uppercase))); 
}
#endif

#ifdef TEST
int main(void){
	char *Tests = "AaBbcCD3EdFGHgIJKLhM2NOjPQRkSTlUVWfXYf0Z1";
	char *p = Tests; //�޸�p��why?Tests�����ַ����ı䣿 
	int Result = 0;
	
	while('\0' != *p)
	{
		Result = lower(*p);
		printf("[%c] gives [%c]\n",*p,Result);
		++p;
	}
	/*and the obligatory boundary test*/
	Result = lower(0);
	printf("'\\0' gives %d\n",Result);
	
	return 0;
} 
#endif
