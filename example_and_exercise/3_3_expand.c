/*3_3_expand.c
line79:�ڴ�����δ��� 
��д����expand(s1,s2),���ַ���s1��������a-zһ��
���ټǷ������ַ���s2����չΪ�ȼ۵������б�abc...xyz.
�ú������Դ����Сд��ĸ�����֣������Դ���a-b-c��a-z0-9
��-a-z�����Ƶ��������Ϊǰ����β���-�ַ�ԭ����ӡ�� 

*/
#include<stdio.h>
#include<string.h>

void expand(char *s1,char *s2);

int main(void){
	char *s[] = {"a-z-","z-a-","-1-6-",
				"a-ee-a","a-R-L","1-9-1",
				"5-5",NULL};
	// char *s[]={"".""}; s�Ǻ��ģ�[]���ȼ�����*��s��[]��Ϲ�char *s[]Ϊ�ַ�ָ������,����ÿ��Ԫ��Ϊָ���ַ���ָ��
//	��Ϊÿ���ַ���Ԫ�ص��׵�ַ ��s�ɿ�����ά���ַ����飬һά���ַ�ָ�����飿 
//	����ָ��Ϊ int (*p)[]; 
	printf("%s.\n",s[1]); ///"z-a-"		
	printf("%c.\n",s[1][0]); ///z
	char result[100];
	int i = 0;
	
	while(s[i]){
		//չ������ӡ����s[]�е���һ���ַ���
		expand(result,s[i]);
		printf("Unexpanded: %s\n",s[i]);
		printf("Expand: %s\n",s[i]);
		++i;
	}	
	return 0;
}
//��s2���Ƹ�s1�� ��չ��Χ��'a-z' ��'8-3'
void expand(char *s1,char *s2){
	static char upper_alph[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char lower_alph[27] = "abcdefghijklmnopqrstuvwxyz";
	static char digits[11] = "0123456789"; //ΪʲôҪ������һ���ֽڿռ䣿
	
	char *start,*end,*p;
	int i=0;
	int j=0;
	
	while(s2[i]){
		switch(s2[i]){
		case '-':
			if(i==0 || s2[i+1] == '\0'){
				//'-'ֱ�Ӹ���
				s1[j++] = '-';
				++i;
				break; 
			}
			else{
				/*
				char *str(const char  *str,int ch);str:ָ��������Ŀ���ֹ�ֽ��ַ�����ָ�룬ch��Ҫ�������ַ� 
				Ѱ��ch����str��ָ��Ŀ���ֹ�ֽ��ַ������״γ���λ�ã� 
				��ֹ���ַ�����Ϊ���ַ�����һ���֣���������Ѱ��'\0'ʱ�ҵ� �� 
				��str �ҵ����ַ���ָ�룬��δ�ҵ����ַ���Ϊ��ָ��
				*/
				//start��end���ַ�ָ�� 
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
				//��չ��Χ
				p = start; //p��ָ���ڴ�ռ䣿 start?
//				while(p != end){
				while(p != NULL && p != end){
					//pΪ�ַ�ָ�룬s1�ַ�ָ��:�ַ������׵�ַ 
					s1[j++] = *p;//s2[j++] = *p;�ڴ�����δ��󣿣��� 
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

