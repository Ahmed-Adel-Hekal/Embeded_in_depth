/*
 ============================================================================
 Name        : Mid_Exam.c
 Author      : Ahmed Hekal
 Version     :
 Copyright   : This is open source projec tfeel free to contact if needed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


//c function to take a number and sum all digits?
//test case 1:
//input:123 ->output:6
//test case 2:
//input:4565 ->output:20
void task1(){
	unsigned long long number = 0 ;
	printf("Please Enter Number to Get it is sum");
	fflush(stdin);fflush(stdout);
	scanf("%llu",&number);
	unsigned long sum = 0 ;
	int rem  = 0 ;
	while(number >0){
		rem = number%10;
		sum+=rem ;
		number /= 10 ;
	}
	printf("The sum of number is %lu",sum);
}


//c function to take an integer number and calculate it's square root?
//test case 1:
//input:4 ->output:2.000
//test case 2:
//input:10 ->output:3.126

void task2(){
	double number, res ;
	printf("Enter number to get it is root ");
	fflush(stdin);fflush(stdout);
	scanf("%lf",&number);
	res = sqrt(number) ;
	printf("%.3lf",res);
}

//c function to revers digits in number?
//test case 1:
//input:2457 ->output:7542 .
//test case 2:
//input:1057 ->output:7501.

int reverse(unsigned long long number){
	int rem = 0 ;
	if(number > 0){
		rem = number%10;
		number =number/10;
		printf("%d",rem);
		reverse(number);
	}

		return 0 ;

}
void task3(){
	unsigned long long number = 0 ;
	printf("Please Enter Number");
	fflush(stdin);fflush(stdout);
	scanf("%lld",&number);
	reverse(number);
}


//c function to count number of ones in binary number?
//test case 1:
//input:5 ->output: 2 --->binary of 5 is 0101 so has 2 one's
//test case 2:
//input:15 ->output:4

# define Get_bit(reg,bit)  ((reg>>bit)&1)
void task4(){
	int number =0 ;
	int i =0 ,count =0;
	printf("Please enter number to check Ones");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);
	for(i=sizeof(number); i>=0; i--){
		if(Get_bit(number,i)){
			count ++ ;
		}
	}
	printf("%d\n",count);
}


//c function to return unique number in array with one loop?
//test case 1:
//input:  int a[7]={4,2,5,2,5,7,4}; output:7.
//test case 2:
//input: int a[3]={4,2,4};    output:2.

void task5(){
	int res = 0 ;
	int arr [] = {4,2,5,2,5,7,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0 ; i < size ; i++)
		res ^= arr[i];
	printf("The unique element in arr is %d", res);
}


///c function to sum numbers from 1 to 100(without loop)?

int task6(int x){
	if(x ==1){
		return 1 ;
	}else{
		return x+task6(x-1);
	}
}

// c function to take an array and revese its elements?

void task7(){
    # define size 5
	int arr[size] = {1,2,3,4,5};
	int temp [size] ;
	for(int i = 0 ; i<size; i++ )
	{
		temp[i] = arr[size-1-i];
	}
	for(int i=0; i < size ; i++)
		printf("%d ",temp[i]);
}
int main() {
	task7();
	return 0;
}
