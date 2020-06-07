/*1_24_check_syntax_erro_2.c*/ 
#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK 1024

enum
{
	CODE,	/* ���¾���*/
	COMMENT,	/*������һ��ע��*/ 
	QUOTE1,	/*������*/
	QUOTE2	/*˫����*/ 
};

int main(void){
	int ch;
	int state = CODE;
	char stack[MAX_STACK];
	size_t top = 0; /*ָ��ջ��*/
	size_t line = 1;
	int error = 0;	/**/ 
	
	while((ch = getchar()) != EOF)
	{
		if(ch == '\n'){
			line++;
		}
		switch(state)
		{
		case CODE:
			if(ch == '\''){
				state = QUOTE1;
			}
			else if(ch == '/')
			{
				int second = getchar();
				
				if(second == '*'){
					state = COMMENT;
				}
				else{
					ungetc(second,stdin);
				}
			}
			else if(ch == '(' || ch == '[' || ch == '{'){
				if(top < MAX_STACK){
					stack[top++] = ch;
				}
				else{
					printf("Stack too small!\n");
					return EXIT_FAILURE;  /*�˳�*/
				}
			}
			else if(ch == ')' || ch == ']' || ch == '}'){
				if(top == 0)	/*�ҵ��رմ����ţ�����ջΪ��*/
				{
					printf("Line %lu: Closing '%c' found without counterpart.\n",(unsigned long)line,ch);
					error = 1;
				}
				else{
					char open = stack[--top];
					
					if((ch == ')' && open != '(') ||
						(ch == ']' && open != '[') ||
						(ch == '}' && open != '{'))
					{
						printf("Line %lu:Closing '%c' does not match opening '%c'.\n",(unsigned long)line,ch,open);
						error = 1; 
					} 
				}
			} 
			break;
		case COMMENT:
			if(ch == '*'){
				int second = getchar();
				if(second == '/'){
					state = CODE;
				}
				else{
					ungetc(second,stdin);
				}
			} 
			break;
		case QUOTE1:
			if(ch == '\\'){
				(void)getchar(); /**/ 
			} 
			else if(ch == '\''){
				state = CODE;
			}
			break;
		case QUOTE2:
			if(ch == '\\'){
				(void)getchar();
			}
			else if(ch == '"'){
				state = CODE;
			}
			break;
		}
	}
	if(state == COMMENT){
		printf("Code ends inside comment!\n");
	}
	else if(state == QUOTE1){
		printf("Code ends inside single quotes!\n"); 
	}
	else if(state == QUOTE2){
		printf("Code ends insdie double quotes!\n");
	}
	else if(top == 0 && error == 0){
		printf("Code seems to be ok.\n");
	}
	if(top > 0)	/*still something in the stack*/
	{
		size_t i;
		for(i = 0;i<top;i++)
			printf("Opening '%c' found without counterpart.\n",stack[i]);
	}
	return 0;
}