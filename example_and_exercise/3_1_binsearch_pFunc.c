/*3_1_binsearch_pFunc.c
函数指针 
*/

#include<stdio.h>
#include<time.h>
int binsearch(int x,int v[],int n);
int binsearch2(int x,int v[],int n);

#define MAX_ELEMENT 200
//定义了一个函数指针类型pFunc，它指向一种特定参数列表和返回值的函数 
typedef int (*pFunc)(int,int [],int); 

typedef int qFunc(int ,int);
#define  M(x,y) x*x+y*y

int main(void){
	//
	pFunc p1 =NULL;
	pFunc p2 = NULL;
	p1 =  binsearch;
	p2 = binsearch2;
	
	int testdata[MAX_ELEMENT];
	int index;
	int n = 55;
	int i;
	clock_t time_taken;
	
	/*初始化test data*/
	for(i=0;i<MAX_ELEMENT;++i)
		testdata[i] = i;
		
	/*迭binsearch 2()100,000次迭代所需时近似间的输出*/
	for(i=0,time_taken = clock();i<100000;++i) 
//		index = binsearch(n,testdata,MAX_ELEMENT); 
		index = p1(n,testdata,MAX_ELEMENT); 
		//计算迭代所需时间 
	time_taken = clock() - time_taken;
	printf("%d.\n",time_taken);
	//binsearch返回值 
	if(index < 0)
		printf("Elemnt %d not found.\n",n);
	else
		printf("Elemnt %d found at index%d.\n",n,index);
		
	printf("binsearch() took %lu clocks(%lu seconds)\n",
			(unsigned long)time_taken,
			(unsigned long)time_taken / CLOCKS_PER_SEC);
			
	/*binsearch 2()100,000次迭代所需时近似间的输出*/ 
	for(i=0,time_taken = clock();i<100000;++i) 
//		index = binsearch2(n,testdata,MAX_ELEMENT); 
		index = p2(n,testdata,MAX_ELEMENT); 
		
		//计算迭代所需时间 
	time_taken = clock() - time_taken;
	printf("%d.\n",time_taken);
	//binsearch返回值 
	if(index < 0)
		printf("Elemnt %d not found.\n",n);
	else
		printf("Elemnt %d found at index%d.\n",n,index);
		
	printf("binsearch() took %lu clocks(%lu seconds)\n",
			(unsigned long)time_taken,
			(unsigned long)time_taken / CLOCKS_PER_SEC);	
	//替换为函数指针 
	return ;
} 
/*在具有n个元素的数组v[]中执行元素x的二进制搜索*/ 
int binsearch(int x,int v[],int n){
//	printf() 
	int low,high,mid;
	
	low = 0;
	high = n-1;
	while(low <= high){
		mid = (low+high)/2;
		if(x < v[mid])
			high = mid+1;
		else if(x>v[mid])
			low = mid +1;
		else  /*found match*/
			return mid;
	}
	return -1;/*no match*/
}
/*在循环中只使用一个测试实现binsearch()*/ 
int binsearch2(int x,int v[],int n){
	int low,high,mid;
	
	low = 0;
	high = n-1;
	mid = (low+high)/2;
	while(low<=high && x!=v[mid]){
		if(x < v[mid])
			high = mid-1;
		else
			low = mid+1;
		mid = (low+high)/2; 
	}
	if(x == v[mid])
		return mid;
	else 
		return -1;
}
