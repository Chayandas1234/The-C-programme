/*1_20_detab.c:将输入中的制表符替换成适当数目的空格，
使空格充满到下一个制表符终止位的地方
若设定制表符终止位的位置固定，如每隔n列就会出现一个制表符终止位，n应为变量还是常量？ 
在回答关于n应该是可变的还是固定，它应该是可变的，
以便允许在运行时修改值，例如通过命令行参数修改，而不需要重新编译*/
/*制表符：表示占据一定的空格数，作用是将每行按整数别的间隔进行分布
如“制表符代表八个空格”，不是说代替八个空格？，作用是将光标移动到最接近8倍数的位置
使得后面的输出从此处开始 ，即若所有数据都紧跟在制表符后边输出，则该数据只能在第9列，第17列、第25列...开始
//制表符原理 
#include <stdio.h>
int main(){
	printf("1234567\t0\n");
	printf("12345678\t0\n");
	printf("123456789\t0\n");
	printf("12345678\t0\t9\n");
 
 return 0;
} 
1234567 0
12345678        0
123456789       0
12345678        0       9
若已经到了第8位，应该是调到第17列 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFFER 1024
#define SPACE '*'
#define TAB '\t'
// 
int CalculateNumberOfSpaces(int Offset, int TabSize)
{
	return TabSize - (Offset % TabSize);//小于5的数，对5求余等于它自身 
}
/*K&R^s getline() function from p29*/
int getline(char s[],int lim){
	int c,i;
	//读取一行字符条件：数组最大下标、getchar从stdin读取字符、字符不为换行符 
	for(i = 0;i<lim-1 && (c = getchar()) != EOF && c != '\n';++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
} 
int main(void){
	char Buffer[MAX_BUFFER];
	int TabSize = 5; 
	int i,j,k,l;
	//读取字符，判断制表符位置，并将其替换为空格 
	while(getline(Buffer,MAX_BUFFER) > 0)
	{
		for(i = 0,l = 0;Buffer[i] != '\0';i++)
		{
			if(Buffer[i] == TAB)
			{
				//j即为打印空格数，为什么添加了变量l来求空格数 
				j = CalculateNumberOfSpaces(l,TabSize);//(1,4)
				for(k = 0;k<j;k++)
				{
					//输出j-1个空格 
					putchar(SPACE);
					l++;//统计字符和空格总数，这个有什么用？ 
				}
			}
			else
			{
				putchar(Buffer[i]);
				l++;//输入不为TAB的字符，l自加1 
			}
		  }  
	}
	
	return 0;
} 
/*
asdfasdf        asdfa   asdf    asdf
asdfasdf *asdfa*****asdf*asdf
*/
/*
@New:将输入的字符输入到数组，变量数组找出制表符，并sizeof('\t')替换为空格
'\t'占用4个字节，每个tab需要用四个空格替换，这样就绪扩展数组 array_blank[len+mun*4-1]
#include<stdio.h>
#define MAX 1024
int getline(char s[],int len){
	int c,i;
	
	for(i=0; i<len-1 && (c = getchar())!= EOF;i++) //c != '\n'
	{
		s[i] = c;
	}
	if(c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int main(void){
	//printf("%d\n",sizeof('\t'));
	char array[MAX];
	char array_blank[MAX];
	char a[5];
	a[0] = '\t';
	int i,j,n;
	i = j =0;
	printf("t:%c\n",a[0]);
	while(getline(array,sizeof(array)) > 0){
		if(array[i] != '\t' && i < MAX && j< MAX){
			array_blank[j] = array[i];
			j++,i++;
		}
		else{
//			if(j < MAX)
			for(n=0;n<4;n++){
				if(j < MAX)
					array_blank[j++] =' ';
				else
					break; 
			}
			
		}
	}	
//	array_blank[j++] = '\0';
	printf("%s",array_blank);
	return 0;
}*/
