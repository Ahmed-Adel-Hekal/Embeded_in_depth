/*
 ============================================================================
 Name        : Lect5_Function.c
 Author      : Ahmed Hekal
 Version     :
 Copyright   : This is open source projec tfeel free to contact if needed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * main.c
 *
 *  Created on: Jan 18, 2024
 *      Author: ahmed
 */

# include <stdio.h>

// Function to check if a number is prime
int isPrime(int number) {
    if (number <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0; // Not a prime number
        }
    }

    return 1; // Prime number
}

void ex1(){
	/*
	 * this code to print prime number
	 * between 2 intervals
	 */
	int a=0,b=0;
	printf("Enter 2 numbers as interval");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&a,&b);
	for (int i = a ; i<=b; i++)
		if(isPrime(i)){
			printf("%d is prime\n",i);
		}

}


int fact(int n){
	if(n>0){
		return n*fact(n-1);
	}else{
		return 1;
	}
}
void ex2(){
	int num ;
	printf("Please Enter Number");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	printf("Factorial of %d is %d",num,fact(num));
}

void reverse(char *text){
	if(*text != '\0'){
		reverse(text+1);
		printf("%c",*text);
	}
}


void ex3(){
	char sent[100];
	printf("Enter sentence");
	fflush(stdin); fflush(stdout);
	gets(sent);
	reverse(sent);
}

int power(int base, int pow){
	if(pow>0){
		pow-- ;
		return base*power(base, pow--);
	}
	else{
		return 1;
	}
}
void ex4(){
	int base=0,pow=0;
	printf("Please base and power");
	fflush(stdin);fflush(stdout);
	scanf("%d   %d",&base,&pow);
	printf("Number is %d",power(base,pow));
}
int main(){
	ex1();
}

