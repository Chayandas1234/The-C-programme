/*2_3_ConvertStringtoInteger.c
Q:��ʮ������������ɵ��ַ�����������ѡ��ǰ׺ox��0X��ת��Ϊ��֮�ȼ۵�����ֵ��
�ַ�����������������������0-9��a-f,A-F

*/
#include<stdio.h> 
#include<stdlib.h>

/*��ʮ����������ĸתΪ��Ӧ��ʮ������*/
int hexalpha_to_int(int c){
	char hexalpha[] = "aAbBcCdDeEfF";
	int i;
	int answer = 0;//��ͣ���ʼ��Ϊ0 
	
	for(i=0;answer == 0 && hexalpha[i] != '\0';i++)
	{
		if(hexalpha[i] == c){
			answer = 10 + (i/2);//��ʮ��������ת��Ϊ10������ 0-9��A��10��Сдa��Aһ�� 
		}
	}
	return answer;
}

unsigned int htoi(const  char s[]){
	unsigned int answer = 0; /*ʹ���޷�������ʹ�ó����������ü�ʹ�������*/ 
	int i = 0;
	int valid  = 1;
	int hexit;
	//����ʮ�����Ʊ�ʶ��0x 0X  
	if(s[i] == '0'){
		++i;
		if(s[i] == 'x' || s[i] == 'X')
		{
			++i; 
		} 
	} 
	//�����ַ������ַ�����Ϊ0-9��a-f,A-F ��ôʵ�ֽ� 
	while(valid && s[i] != '\0'){
		answer = answer * 16; //��ϣ�answer=answer+hexit����ʮ��������ת��Ϊʮ������ 
		printf("1-answer :%d\n",answer);
		if(s[i] >= '0' && s[i] <= '9'){
			answer = answer + (s[i] -'0');
		}
		else{
			hexit = hexalpha_to_int(s[i]); //s[i]--const char  �ַ���Ӧ�Ľ����� 
			if(hexit == 0){
				valid = 0;//��ĸΪa-f�ı�־λ���� ghzs...����Ӧʮ�������е���ĸ���������� 
			}
			else{
				answer = answer + hexit;//??,hexit:�ַ� ��hexalpha[]��λ�ã� ʮ������תΪʮ�������� 
				printf("2-answer :%d\n",answer);
			}
		}
		++i;//�������±�С��Ӧʮ���������ĸ�λ����ôʵ��ת���� ������bab:{[��11*16+10��]*16+ 11} -->11*16*16+10*16+11
	}
	if(!valid){
		answer = 0;
	}
	printf("3-answer :%d\n",answer);
	return answer;
}

//����ſ����������ַ��Ĺ涨
int main(void){
	char *endp = NULL;
	//ָ�����飿 
	char *test[] = 
	{
		"F00",
		"bar",
		"0100",
		"0x1",
		"0XA",
		"0X0C0BE",
		"abcdef",
		"123456",
		"0x123456",
		"deadbeef",
		"zog_c"
	};
	
	unsigned int result,check;
	size_t numtests = sizeof test / sizeof(test[0]);
	
	size_t thistest; // size_t:unsigned long long  
	
	for(thistest = 0;thistest < numtests;thistest++){
		result = htoi(test[thistest]); // ��ʮ������������ɵ��ַ�ת��Ϊ����ֵ 
		printf("1-result :%d\n",result);
		/*
		unsigned long strtoul(const char *str,char **str_end,int base)��
		*ת�� str ��ָ���ַ����е��޷�������ֵ�ɣ���ʱΪ��Ӧ str ���ݵ�����ֵ
		*����ֵ����� errno ����Ϊ ERANGE ������ ULONG_MAX �� ULLONG_MAX ������ת���ɽ��У��򷵻� 0 ��
		* str:ָ��Ҫ��ת��Ŀ���ֹ�ַ�����ָ��
		*str_end:ָ���ַ���ָ���ָ��
		*base����ת������ֵ�ĵ� 
		*/ 
		
		check = (unsigned int)strtoul(test[thistest],&endp,16);//test[thistes]����ĸ����ôת����ģ� 
		if((*endp != '\0' && result == 0) || result == check)
		{
			printf("Testing %s. Correct.%u\n",test[thistest],result);
		}
		else{
			printf("Testing %s. Incorrect.%u\n",test[thistest],result);
		}
	} 
	return 0;
} 


/*
//ȷ���ַ�Ϊʮ�����ƣ���ͷ��Ϊ0x 0X ,ת��Ϊ���� ʮ�����ƻ���ʮ���ƣ� 

#include<stdio.h> 
#define MAX 100

int main(){
	int i,c;
	char s[MAX];
	
	for(i=0;i<MAX-1 && (c=getchar())!=EOF && c != '\n';++i){
		s[i] = c;
		if(s[i] == '0' && s[i++] == 'x')  //����������޷�ʹ��&& ||ͳһ��һ�������Ǿͷֿ��ж� 
		{
			
		}
	}

}
*/ 
