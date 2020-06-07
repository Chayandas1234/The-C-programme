/*1_3_4_5:print_title.c修改温度转换程序，使之能在转换表的顶部打印一个标题*/ 
#include<stdio.h>
 /* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300; floating-point version 
 C =(5/9)*(F-32.0)
 F = C*(9/5)+32.0
 */
void FtoC_fun();
void CtoF_fun();
void FtoC_reverse_print();
void FtoC_reverse_print_1();
main()
{
//	 float fahr, celsius;
	FtoC_fun();
	CtoF_fun();
	FtoC_reverse_print();/*1_5*/
	FtoC_reverse_print_1();

}
 
 
void FtoC_fun(){
 	float fahr, celsius;
	float lower, upper, step;
	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	fahr = lower;
	printf("  F\tC\n\n");
	while (fahr <= upper) {
	celsius = (5.0/9.0) * (fahr-32.0);
	printf("%3.0f %6.1f\n", fahr, celsius);
	fahr = fahr + step;
// 	return fahr;
 	}
 }

void CtoF_fun(){
 	float fahr, celsius;
	float lower, upper, step;
	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
//	fahr = lower;
	celsius = lower;
	printf("  C\tF\n\n");
	while (celsius <= upper) {
		fahr = celsius*(9.0/5.0) +32.0;
		if(!(fahr<=upper)){
			break;
		}
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius += step;
	}	
//	return fahr;
}

void FtoC_reverse_print(){
 	float fahr, celsius;
	float lower, upper, step;
	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	fahr = upper;
	printf("  F\tC\n\n");
	while (fahr >= lower) {
	celsius = (5.0/9.0) * (fahr-32.0);
	printf("%3.0f %6.1f\n", fahr, celsius);
	fahr -= step;
// 	return fahr;
 	}
 }
 
void FtoC_reverse_print_1(){
 	int fahr;
 	printf("  F\tC\n\n");
 	for(fahr = 300;fahr >= 0;fahr -= 20)
 		printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
 }
