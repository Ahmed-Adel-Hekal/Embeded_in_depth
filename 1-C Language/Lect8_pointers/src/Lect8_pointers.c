/*
 ============================================================================
 Name        : Lect8_pointers.c
 Author      : Ahmed Hekal
 Version     :
 Copyright   : This is open source projec tfeel free to contact if needed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * a C program  to demonstrate how to handle the pointers
in the program.*/
void task1(){

	int x = 5 ;
	int *ptr = &x ;
	printf("Variable Address : %d\n",&x);
	printf("Variable Value : %d\n",x);
	printf("Pointer address :%d\n",&ptr);
	printf("Variable address %d\n", ptr);
	printf("Variable value using pointer %d\n",*ptr);
	*ptr = 7 ;
	printf("Variable Address : %d\n",&x);
	printf("Variable New Value : %d\n",x);

}
/*
 * print all alphapit using pointer
 * */
void task2(){
	char c = 65 ;
	char *ptr = &c ;
	for(char i=0; i<26; i++)
		printf("%C ",*ptr+i);
}

void task3(){
	char s[100];
	printf("please enter word ");
	fflush(stdin);fflush(stdout);
	gets(s);
	char size = strlen(s);
	char *ptr = s ;
	size--;
	for(;size>=0;size--){
		printf("%C", *(ptr+size));
	}
}


void task4(){
	#define MAX  15
	int num = 0 ;
	int arr[MAX] ={0} ;
	int *ptr  =arr;
	printf("Please Enter number of element\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	for(int i =0 ; i<num; i++)
		{
			printf("Element number %d\n", i+1);
			fflush(stdin); fflush(stdout);
			scanf("%d", &arr[i]);
		}
	printf("------------------------------");
	printf("array in reverse order is\n ");
	num--;
	for( ; num>=0; num--)
		{
			printf("Element number %d  %d\n", num,*(ptr+num));

		}

}
int main(void) {
	task2();
	return EXIT_SUCCESS;
}
