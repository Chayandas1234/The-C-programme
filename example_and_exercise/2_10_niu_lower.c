/*2_10_lower.c
author:niuxiatong
time:20200523
���±�д����д��ĸת��ΪСд��ĸ�ĺ���lower,�����������ʽ�������if-else�ṹ 
*/
int lower(char ch){
	
	return ((90>= ch >=65)? (ch+32):-1);
	//�漰����ת�� 
//	c += 32;
	 
//	return ch;
}

int main(void){
	
	int ch = lower('\t');
	printf("%d\n",ch);
	/*
	printf("%d\n",'A');//65 
	printf("%d\n",'a');//97  'a'-'A'=32;
	
	printf("%d\n",'Z');//90
	printf("%d\n",'z');//122*/
	return 0;
} 
