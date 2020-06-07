/*3_1_binsearch.c
�۰�����У�whileѭ�������ִ�������β��ԣ���ʵһ�ξ͹���
�������ǽ�����Ĳ�����ѭ����ִ�У�����д������ʹ����ѭ���ڲ�ִֻ��һ�β��ԣ�
�Ƚ����ְ汾����������ʱ�� 
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
	
	/*��ʼ��test data*/
	for(i=0;i<MAX_ELEMENT;++i)
		testdata[i] = i;
		
	/*��binsearch 2()100,000�ε�������ʱ���Ƽ�����*/
	for(i=0,time_taken = clock();i<100000;++i) 
		index = binsearch(n,testdata,MAX_ELEMENT); 
		//�����������ʱ�� 
	time_taken = clock() - time_taken;
	printf("%d.\n",time_taken);
	//binsearch����ֵ 
	if(index < 0)
		printf("Elemnt %d not found.\n",n);
	else
		printf("Elemnt %d found at index%d.\n",n,index);
		
	printf("binsearch() took %lu clocks(%lu seconds)\n",
			(unsigned long)time_taken,
			(unsigned long)time_taken / CLOCKS_PER_SEC);
			
	/*binsearch 2()100,000�ε�������ʱ���Ƽ�����*/ 
	for(i=0,time_taken = clock();i<100000;++i) 
		index = binsearch2(n,testdata,MAX_ELEMENT); 
		//�����������ʱ�� 
	time_taken = clock() - time_taken;
	printf("%d.\n",time_taken);
	//binsearch����ֵ 
	if(index < 0)
		printf("Elemnt %d not found.\n",n);
	else
		printf("Elemnt %d found at index%d.\n",n,index);
		
	printf("binsearch() took %lu clocks(%lu seconds)\n",
			(unsigned long)time_taken,
			(unsigned long)time_taken / CLOCKS_PER_SEC);	
	//�滻Ϊ����ָ�� 
	return ;
} 
/*�ھ���n��Ԫ�ص�����v[]��ִ��Ԫ��x�Ķ���������*/ 
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
/*��ѭ����ֻʹ��һ������ʵ��binsearch()*/ 
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
