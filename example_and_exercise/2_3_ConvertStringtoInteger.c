/*2_3_ConvertStringtoInteger.c
Q:把十六进制数字组成的字符串（包含可选的前缀ox或0X）转换为与之等价的整型值，
字符串中允许包含的数组包括：0-9，a-f,A-F

*/
#include<stdio.h> 
#include<stdlib.h>

/*将十六进制中字母转为对应的十进制数*/
int hexalpha_to_int(int c){
	char hexalpha[] = "aAbBcCdDeEfF";
	int i;
	int answer = 0;//求和，初始设为0 
	
	for(i=0;answer == 0 && hexalpha[i] != '\0';i++)
	{
		if(hexalpha[i] == c){
			answer = 10 + (i/2);//将十六进制数转换为10进制数 0-9，A：10，小写a和A一样 
		}
	}
	return answer;
}

unsigned int htoi(const  char s[]){
	unsigned int answer = 0; /*使用无符号整型使得程序运行良好即使发生溢出*/ 
	int i = 0;
	int valid  = 1;
	int hexit;
	//跳出十六进制标识符0x 0X  
	if(s[i] == '0'){
		++i;
		if(s[i] == 'x' || s[i] == 'X')
		{
			++i; 
		} 
	} 
	//变量字符串中字符，分为0-9、a-f,A-F 怎么实现将 
	while(valid && s[i] != '\0'){
		answer = answer * 16; //配合（answer=answer+hexit）将十六进制数转换为十进制数 
		printf("1-answer :%d\n",answer);
		if(s[i] >= '0' && s[i] <= '9'){
			answer = answer + (s[i] -'0');
		}
		else{
			hexit = hexalpha_to_int(s[i]); //s[i]--const char  字符对应的进制数 
			if(hexit == 0){
				valid = 0;//字母为a-f的标志位，如 ghzs...不对应十六进制中的字母，不做计算 
			}
			else{
				answer = answer + hexit;//??,hexit:字符 在hexalpha[]的位置？ 十六进制转为十进制数？ 
				printf("2-answer :%d\n",answer);
			}
		}
		++i;//数组中下标小对应十六进制数的高位，怎么实现转换？ 举例：bab:{[（11*16+10）]*16+ 11} -->11*16*16+10*16+11
	}
	if(!valid){
		answer = 0;
	}
	printf("3-answer :%d\n",answer);
	return answer;
}

//程序放宽允许输入字符的规定
int main(void){
	char *endp = NULL;
	//指针数组？ 
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
		result = htoi(test[thistest]); // 将十六进制数字组成的字符转换为整型值 
		printf("1-result :%d\n",result);
		/*
		unsigned long strtoul(const char *str,char **str_end,int base)：
		*转译 str 所指的字符串中的无符号整数值成，功时为对应 str 内容的整数值
		*则发生值域错误（ errno 被设为 ERANGE ）返回 ULONG_MAX 或 ULLONG_MAX 。若无转换可进行，则返回 0 。
		* str:指向要被转译的空终止字符串的指针
		*str_end:指向字符的指针的指针
		*base：被转译整数值的底 
		*/ 
		
		check = (unsigned int)strtoul(test[thistest],&endp,16);//test[thistes]中字母是怎么转化你的？ 
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
//确定字符为十六进制，开头分为0x 0X ,转换为整型 十六进制或者十进制？ 

#include<stdio.h> 
#define MAX 100

int main(){
	int i,c;
	char s[MAX];
	
	for(i=0;i<MAX-1 && (c=getchar())!=EOF && c != '\n';++i){
		s[i] = c;
		if(s[i] == '0' && s[i++] == 'x')  //当多个条件无法使用&& ||统一到一个条件那就分开判断 
		{
			
		}
	}

}
*/ 
