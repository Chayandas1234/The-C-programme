/*1_18_delete_blanks_tabs.c
ɾ��ÿ��������ĩβ�Ŀո��Ʊ������ɾ����ȫ�ǿո����
	//�������
	//�ַ�����
	//���߼�����ȡ������ĩβ�Ŀո��Ʊ����Ȼ��ɾ��
	//�жϸ����Ƿ�ȫΪ�ո�����ɾ������ */
#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 1001

int advance(int pointer){
	if(pointer < MAXQUEUE -1)
		return pointer + 1;
	else
		return 0;
} 

int main(void){
	char blank[MAXQUEUE];
	int head,tail;
	int nospace,retval;
	int c;
//	int spaceJustPrinted;/*�����������һ����ӡ�Ŀո�*/ 
	
	retval  = nospace = head = tail = 0;
	while((c = getchar())!= EOF){
		//��stdin��ȡΪ���з� 
		if(c == '\n'){
			head = tail = 0;
//			if(spaceJustPrinted == 1)
//				retval = EXIT_FAILURE;
			if(nospace)
				putchar('\n');//������з� 
//				spaceJustPrinted = 0;
			nospace = 0;	 
		}
		//��stdin��ȡΪ�ո���Ʊ�� 
		else if(c == ' ' || c == '\t'){
			if(advance(head) == tail){	// 
				putchar(blank[tail]); //���blank�е�ֵ 
				tail = advance(tail); //����β����ֵ 
				nospace = 1;
				retval = EXIT_FAILURE;
			}
			blank[head] = c;	// ���ո��Ʊ�����浽blank[] 
			head = advance(head); //����headֵ����headû����MAXQUEUE��Χʱ��head +=1�� 
		}
		//��stdin��ȡ�ǿո� �Ʊ�������з�ʱ 
		else{
			while(head != tail){
				putchar(blank[tail]);//�������Ԫ�� �ո� 
				tail = advance(tail);
			}
			putchar(c);   //��������ַ� 
			nospace = 1;
		}
	}
	
	return retval;
} 
