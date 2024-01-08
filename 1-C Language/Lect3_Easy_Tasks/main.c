/*
 * mian.c
 *
 *  Created on: 26 Dec 2023
 *  Author: Ahmed Adel Hekal
 *  Description: this simple tasks used to demonestrate C Basics
 */

# include <stdio.h>

//EX1:
//
//Write C Program to Print a Sentence
void Ex1() {
	printf("C Language");
}

//EX2:
//
//Write C Program to Print a Integer Entered by a User
void Ex2() {
	int x = 0;
	printf("Enter Number : ");
	scanf("%d", &x);
	printf("This the number : %d", x);
}

//EX3:
//
//Write C Program to Add Two Integers
void Ex3() {
	int x = 0;
	int y = 0;
	fflush(stdout);
	printf("Please Enter 2 Numbers :\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d\n", &x);
	fflush(stdin);
	fflush(stdout);
	scanf("%d\n", &y);
	fflush(stdin);
	fflush(stdout);
	printf("the number is %d", x + y);
	fflush(stdin);
	fflush(stdout);

}

//EX4:
//Write C Program to Multiply two Floating Point Numbers
void Ex4() {
	double x = 0;
	double y = 0;
	printf("Please Enter Float Number :\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%lf    %lf", &x, &y);
	fflush(stdin);
	fflush(stdout);
	printf("Is your Float summition %lf", x + y);
}

//EX5:
//Write C Program to Find ASCII Value of a Character
void Ex5() {
	char x = 0;
	printf("Please Enter your charcter: \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &x);
	printf("The ASCII code for %c is  %d", x, x);
}



//EX6:
//Write Source Code to Swap Two Numbers
void Ex6(){
	int x,y ;
	printf("Please Enter Two Numbers \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d   %d", &x, &y);
	x = x+y;
	y = x-y;
	x = x-y;
	printf(" two numbers are %d  %d", x, y);
}



#include <stdio.h>
int main()
{


}


