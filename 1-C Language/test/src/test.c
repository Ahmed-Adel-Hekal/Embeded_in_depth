/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void plusMinus(int arr_count, int* arr) {
    int positive=0, negative=0, zero=0 ;
    for (int i = 0 ; i<arr_count; i++) {
        //negativwe number
        printf("%d\n",(arr[i]>>32)&1);
        if ((arr[i]>>32)&1) {
            negative++;
        }else if(arr[i]&1) {
        positive ++ ;
        }
        else {
        zero++;
        }
    }
    printf("positive %d, negative %d, zero %d", positive,negative,zero);
}
int x = 20 ;
 f1(){x=x+10;return x; }
 f2(){x=x-5;return x;}
int main()
{
//    int arr [] = {1,-1,2,-3};
//    plusMinus(4,arr);
	int p = f1()+f2() ;
    printf("  %d",p);

    return 0;
}
