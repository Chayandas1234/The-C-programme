/*3_1_binsearch.c
折半查找中，while循环语句内执行了两次测试，其实一次就够了
（代价是将更多的测试在循环外执行）。重写函数，使得在循环内部只执行一次测试，
比较两种版本函数的运行时间 
*/
/*binsearch:find x in v[0] <= v[1] <= ...<= v[n-1]*/
#include<stdio.h>
#include<time.h>
int binsearch(int x,int v[],int n);
int binsearch2(int x,int v[],int n);

#define MAX_ELEMENT 200

int main(void){
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
		index = binsearch(n,testdata,MAX_ELEMENT); 
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
		index = binsearch2(n,testdata,MAX_ELEMENT); 
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
