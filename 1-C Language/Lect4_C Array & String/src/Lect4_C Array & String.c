/*
 ============================================================================
 Name        : Lect4_C.c
 Author      : Ahmed Hekal
 Version     :
 Copyright   : This is open source projec tfeel free to contact if needed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * c program for finding average of user input
 */
void assignment_1(){
	float average=0 , sum=0 , num ;
	for(;;){
		printf("Please enter your number ");
		fflush(stdin);fflush(stdout);
		scanf("%f", &num);
		if(num<0){break;}
		else{
			sum +=num ;
			average++;
		}
	}
	average = sum / average ;
	printf("the average is %f", average);
}
/*
find average of 4 integer numbers entered by user if it is 0 skip it
the output is integer
*/
void assignment_2(){
	int arr[5]  = {0} ;
	int counter = 0 ;
	for(;counter<4;counter++){
		printf("Please enter number");
		fflush(stdin);fflush(stdout);
		scanf("%d", &arr[counter]);
		if(arr[counter]==0){
			counter--;
			continue;
		}
		arr[4] += arr[counter];
	}
	printf("the average is %d", arr[4]/4);
}

/*
 * find the sum of 2 matrix (2x2) entered by user
 * */
void assignment_3(){
	float arr[2][2]={0};
	float temp = 0 ;
	// Getting first matrix
	for(int i=0; i<2; i++){
		for(int j=0;j<2;j++){
			printf("Please enter M [%d] [%d}",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%d",&arr[i][j]);
		}
	}
	// Getting second matrix
	for(int i=0; i<2; i++){
		for(int j=0;j<2;j++){
			printf("Please enter M [%d] [%d}",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%d",&temp);
			arr[i][j]+=temp ;
		}
	}
	for(int i=0; i<2; i++){
		for(int j=0;j<2;j++){
			printf("[%d] ",arr[i][j]);
		}
		printf("\n");
	}
}

void assignment_4(){
	float arr[100] = {0},avr;
	int max = 0 ;
	int i =0;
	printf("Please enter number of data") ;
	fflush(stdin); fflush(stdout);
	scanf("%d",&max);
	for( ; i<max ; i++){
		printf("please enter element %d",i);
		fflush(stdin); fflush(stdout);
		scanf("%f", &arr[i]);
		avr += arr[i];
	}
	printf("Average is %f",avr/i );

}

/*
 * c program to calculate frequency of charcter in sentence
 */

void assignment_5(){
	char st[100]={0},ch;
	printf("enter your string");
	fflush(stdin);fflush(stdout);
	gets(st);
	printf("enter letter to check");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	int i = 0 ,counter=0;
	while(st[i]!='\0'){

		if(st[i]==ch){
			counter++;
		}
		i++;
	}
	printf("your letter found %d",counter);

}

/*
 *
 * this progam counts lenght of sentence
 */
void assignment_6(){
	char arr[100] = {0};
	int counter = 0, i =0 ;
	printf("Please enter sentence");
	fflush(stdin);fflush(stdout);
	gets(arr);
	while(arr[i]!='\0'){
		counter++;
		i++ ;
	}
	printf("your text length %d",counter);
}

int main(void) {

	assignment_6();
	return EXIT_SUCCESS;
}
