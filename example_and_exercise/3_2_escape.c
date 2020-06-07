/*3_2_escape.c
编写函数escape(s,t),将字符串t复制到字符s中，并在复制过程中将换行符、
制表符等不可见字符，分别转换为\n \t等相应的可见的转移字符序列。要求使用switch语句。
再编写一个具有相反功能的函数，在复制过程中将转移字符序列转换为实际字符
*/ 

#include<stdio.h>
void escape(char *s,char *t);
void unescape(char *s,char *t);

int main(void){
	char text1[50] = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
	char text2[51];
	
	printf("Original string:\n%s\n",text1);
	
	escape(text2,text1);
	printf("Escape string:\n%s\n",text2);
	
	unescape(text1,text2);
	printf("Unescape string:\n%s\n",text1);
	
	return 0;
}

void escape(char * s ,char * t){
	int i,j;
	i = j = 0;
	
	while(t[i]){   //t[i] != '\0';
		/*如果有特殊字符，则将其转换*/
		switch(t[i]){
		case '\n':
			s[j++] = '\\';
			s[j] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j] = 't';
			break;
			
		case '\a':
			s[j++] = '\\';
			s[j] = 'a';
			break;
			
		case '\b':
			s[j++] = '\\';
			s[j] = 'b';
			break;
			
		case '\f':
			s[j++] = '\\';
			s[j] = 'f';
			break;
			
		case '\r':
			s[j++] = '\\';
			s[j] = 'r';
			break;
			
		case '\v':
			s[j++] = '\\';
			s[j] = 'v';
			break;
			
		case '\\':
			s[j++] = '\\';
			s[j] = '\\';
			break;
			
		case '\"':
			s[j++] = '\\';
			s[j] = '\"';
			break;
			
		default:
		/*不是特殊的字符，直接复制*/
			s[j] = t[i];//s[j] = t[j];//没有扩展数组，导致其他元素被覆盖 				
		} 
		++i;
		++j;
	}
	s[j] = t[i];
}

void unescape(char * s,char * t){
	int i,j;
	i = j = 0;
	
	while(t[i]){
		switch(t[i]){
			case '\\':
			 //找到了一个逃逸序列，则将其转换
				switch(t[++i]){
					case 'n':
						s[j] = '\n';
						break;
						
					case 't':
					 	s[j] = '\t';
					 	break;
					 	
					case 'a':
						s[j] = '\a';
						break;
						
					case 'b':
						s[j] = '\b';
						break;
						
					case 'f':
						s[j] = '\f';
						break;
						
					case 'r':
						s[j] = '\r';
						break;
																						
					case 'v':
						s[j] = '\v';
						break;
												
					case '\\':
						s[j] = '\\';
						break;
						
					case '\"':
						s[j] = '\"';
						break;	
					default:
					//不转换这个序列，直接复制
						s[j++] = '\\';
						s[j] = t[i];																				
				}
				break;
			default:
				//
				s[j] = t[i];
		}
		++i;
		++j;
	}
	s[j] = t[i];
}
/*
Original string:
Hello,
        World! Mistake was "Extra 'e'"!

Escape string:
\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n
Unescape string:
Hello,
        World! Mistake was "Extra 'e'"!
*/

/*
//autor:niuxiaotong
//time:20200527
//runing ok 

#include<stdio.h>
#define LINE 100

void escape(char s[],char t[]);
void escape1(char *s,char *t);

int main(){
	int i;
	//字符数组 
	char s[LINE-1] ="\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";// "asdfasdfasdf";
	char t[LINE-1];
	
//	scanf("%c",s);
	escape1(s,t);
	
//	for(i=0;t[i] != '\0';i++)	
	for(i=0;i<sizeof(t) && t[i] != '\0';i++)
	{
		printf("%c",t[i]);
	}
	return 0;
} 

void escape(char *s,char *t)
//void escape(char s[],char t[])
{
	int i;
	
	for(i = 0;i<LINE-1 && s[i] !='\0';i++){
		
		if(s[i] == '\n'){
			t[i] = '\\';
			t[i+1] = 'n';
		}else if(s[i] == '\t'){
			t[i] = '\\';
			t[i+1] = 't';
		}
		else
			t[i] = s[i]; 
	}
	i +=1;
	t[i] = '\0';
}

void escape1(char *s,char *t){
	int i;
	
	for(i = 0;i<LINE-1 && *(s+i) !='\0';i++){
		
		if(*(s+i) == '\n'){
			*(t+i) = '\\';
			*(t+i) = 'n';
		}else if(*(s+i) == '\t'){
			*(t+i) = '\\';
			*(t+i) = 't';
		}
		else
			*(t+i) = *(s+i); 
	}
	i +=1;
	*(t+i) = '\0';	
}*/ 

