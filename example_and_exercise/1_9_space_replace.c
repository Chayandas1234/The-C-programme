#include <stdio.h>
/*
int main(void)
{
  int c;
  int inspace;
 
  inspace = 0;
  while((c = getchar()) != EOF)
  {
    if(c == ' ')
    {
      if(inspace == 0)
      {
        inspace = 1;
        putchar(c);
      }
    }
 
    //* We haven't met 'else' yet, so we have to be a little clumsy 
    if(c != ' ')
    {
      inspace = 0;
      putchar(c);
    }
  }
 
  return 0;
}*/
 /*
 a d a d  a a
a d a d a a
asd     asd
asd asd


sdf
sdf
^Z
 */
/*д�����븴�Ƶ�����ĳ��򣬽����������ո���һ���ո����
���븴�Ƶ�������滻�����ո�
���ƣ�һ���ַ�һ���ַ����ƣ����������ڵ���2�Ŀո�Ҫ�滻
strcopy?
�ο����������鲻�Ǹı������ԭʼ���ݣ��Ǹı�����ַ�
�������Ϊ���֣�һ������ո� һ����������ַ� 
*/
//��ʱ����ô��һ���ո��滻ԭ�����еĶ�������Ŀո񣿣� 
int main(void){
	
	int blanks,c;
	blanks = 0;
	while((c = getchar())!= EOF){
		if(c == ' '){
			if(blanks == 0){ //ͨ��blanksֵ���ж��Ƿ����������� 
				blanks = 1;	//��blanksֵ��ֵΪ1�������������ո�ֻ���һ�� 
				putchar(c);
			} 
		}else if(c != ' '){
			blanks = 0;
			putchar(c);
		} 
		
	} 

} 
/*
a d d  ad
a d d ad
asd  asd    asd         d
asd asd asd     d
sd
^Z
*/
