/**/ 
#include<stdio.h>
#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/

/*count lines,words,and characters in input*/
int main(void){
	int ch,nl,nw,nc,state;
	state = OUT;
	nl = nw = nc =0;
	while((ch = getchar())!=EOF){
		++nc;
		if(ch == '\n'){
			++nl;	
		} 
		if(ch==' ' || ch == '\n' || ch == '\t')
			state = OUT;
		else if(state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n",nl,nw,nc);
}
/*
welcome to lianyungang!
you can have a great time in Lindao.
you also can eat a diasd
^Z
3 17 88
*/
/*
标点符号  其他特殊的符号 会被统计为单词个数 
*/
