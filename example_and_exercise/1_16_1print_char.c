/* Time:20200426 
1-16 ��ϰ���޸Ĵ�ӡ��ı��е�������main��
ʹ֮�ɴ�ӡ���ⳤ�ȵ��г��ȣ����������ܶ�ش�ӡ�ı�
�����߼������ն��ж�ȡ�ַ��� �ж��ı����Ƿ���ֻ��У�
���ַ�����len���һ��Ԫ�ز��ǻ��з����������ַ����Ƶ��ַ�����temp������Ŀ���ı��е�����ַ���������
���ı��б�־����1��
��Ϊ���з��� ������ 

*/
/*
��һ�γ�����ϰ,���й����ǲ���ȷ�ģ��淶˵�����޸������̡���
���������е���������ֻ��ͨ���޸�*getline��ȷ�� ���⽫��������Ҫ���ģ� 
getline���ڽ����ظ��е�ʵ�ʳ��ȣ������Ǵ��ݸ����������ж�ȡ���ַ�����
*/
/*keys:�ֿ��������ͨ�����ñ�־λʵ��
	��������߼���ʲô�� 
	��ȡ�ַ��� 
*/ 
#include<stdio.h>
#define MAXLINE 20

int getline(char s[],int lim);
void copy(char to[],char from[]);

int main(void){
	char line[MAXLINE];
	char longest[MAXLINE];
	char temp[MAXLINE];
	int len,max,prevmax,getmore;
	
	max = prevmax = getmore = 0;
	while((len = getline(line,MAXLINE)) > 0){  /*���ض�ȡ�ַ��ĳ���*/
		if(line[len-1] != '\n'){		/*�ַ�������len-1λ������Ϊ���з���˵��һ���ַ�û��ȫ�������ַ�����*/ 
			if(getmore == 0)		/*һ���ַ�δ���꣬���Ѷ�����line��ֵ��temp*/ 
				copy(temp,line);	/*���Ѷ��ַ�������temp*/	 
			prevmax += len;		/*���¶�������prevmax��ֵ*/
			if(max < prevmax)
				max = prevmax;		/*����һ���ַ���󳤶�*/ 
			getmore = 1;		/*�����ı��б�־��*/ 
		}
		else{								/*�����ַ���βΪ���з�*/ 
			if(getmore == 1){
				if(max < prevmax + len){
					max = prevmax + len;	/*�����ı����ַ�����󳤶�*/ 
					copy(longest,temp);		/*��tempԪ�ظ�ֵ��longest*/ 
					longest[MAXLINE - 2]= '\n';
				}
				getmore = 0;
			}
			else if(max < len){	/*��ǰ�����ַ����ȴ�����ǰ�����ַ���󳤶ȣ���������ֵ������*/
				max = len;
				copy(longest,line);
			}
			prevmax = 0;
		}
	}
	/*�ȴ��ַ�ȫ�������꣬�ٴ�ӡ��ı��У�*/ 
	if(max >0){
		printf("%s",longest);
		printf("len = %d\n",max);
	}
	return 0;
} 

int getline(char s[],int lim){
	int c,i;
	
	for(i = 0;i<lim-1 && ((c = getchar()) != EOF && c != '\n');
	++i) 
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}else if(c == EOF && i>0){
		/*gotta do something about no newline preceding EOF*/
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[],char from[]){
	int i;
	
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}

/*
asdfasdfasd
asdfasdf
asdfasdf
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
^Z
aaaaaaaaaaaaaaaaaa
len = 62

--------------------------------
Process exited after 12.63 seconds with return value 0
�밴���������. . .


*/ 
