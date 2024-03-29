/*
 ============================================================================
 Name        : Lect6_Struct_Union_enum.c
 Author      : Ahmed Hekal
 Version     :
 Copyright   : This is open source project feel free to contact if needed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define flush()  {fflush(stdin);fflush(stdout);}

/*student data base*/
void task1(){
typedef struct {
	char name[20];
	int roll;
	float marks;
}student;

student s ={0};
printf("Please enter student data\n");
printf("Student Name : ");
flush();
scanf("%s",s.name);
printf("Enter Student roll :\n");
flush();
scanf("%d",&s.roll);
printf("Enter student marks : ");
flush();
scanf("%f",&s.marks);
printf("_______________________________________________");
printf("Your user data \n");
printf("Student Name : %s \n", s.name);
printf("Student roll : %d \n", s.roll);
printf("Student marks : %.2f \n", s.marks);
}


/* function that adds 2 distance in feet & inch*/
void task2(){
	typedef struct{
		int feet ;
		int inch;
	}distance;
distance first, second, sum ;
printf("Please enter first Number \n");
printf("Feet :");
flush();
scanf("%d",&first.feet);
printf("Inch :");
flush();
scanf("%d",&first.inch);
printf("----------------------------");
printf("Please enter second Number \n");
printf("Feet :");
flush();
scanf("%d",&second.feet);
printf("Inch :");
flush();
scanf("%d",&second.inch);

sum.feet = first.feet + second.feet ;
sum.inch = first.inch + second.inch ;
if(sum.inch > 12){
	sum.feet +=1 ;
	sum.inch -= 12 ;
}

printf(" Total Feet %d", sum.feet);
printf(" Total inch %d", sum.inch);
}



/*function to add 2 complex number */
void task3(){
	typedef struct {
		float real;
		float img ;
	}complex;
	void add_complex( complex e1,  complex e2){
		e1.real += e2.real ;
		e1.img  += e2.img  ;
		printf("the number is %f + %fi",e1.real,e1.img);
	}

	complex first_num, second_num ;
	printf("Please enter real part for first num\n");
	flush();
	scanf("%f",&first_num.real);
	printf("Please enter img part for first num\n");
	flush();
	scanf("%f",&first_num.img);
	printf("==========================================\n");
	printf("Please enter real part for second num\n");
	flush();
	scanf("%f",&second_num.real);
	printf("Please enter img part for second num\n");
	flush();
	scanf("%f",&second_num.img);
	printf("==========================================");
	add_complex(first_num, second_num);

}

/*Using array of struct create student database*/
void task4(){
#define student_count 3
	typedef struct {
		char name[20];
		int roll;
		float marks;
	}student;

	student s[student_count] ={{0}};

	for (int student_number = 0; student_number < student_count; student_number++) {
		printf("Please enter student[%d] data\n",student_number);
		printf("Student[%d] Name : ",student_number);
		flush();
		scanf("%s",s[student_number].name);
		printf("Enter Student[%d] roll :\n",student_number);
		flush();
		scanf("%d",&s[student_number].roll);
		printf("Enter Student[%d] marks : ",student_number);
		flush();
		scanf("%f",&s[student_number].marks);
		printf("_______________________________________________\n");
	}
	for (int student_number = 0; student_number < student_count; student_number++) {
		printf("Your Student[%d] data \n" ,student_number);
		printf("Student[%d] Name : %s \n", student_number,s[student_number].name);
		printf("Student[%d] roll : %d \n", student_number,s[student_number].roll);
		printf("Student[%d] marks : %.2f \n",student_number, s[student_number].marks);
		printf("_______________________________________________\n");

	}
}
int main(void) {


	task4();
	return EXIT_SUCCESS;
}
