/*
 * main.c
 *
 *  Created on: Jan 18, 2024
 *      Author: ahmed
 */



void reverse_array(int arr1[]);


int main(){
	int arr[] = {1,2,3,4,5,6};
	reverse_array();
}

void reverse_array(int arr1[]){

	int sizeof_array = sizeof(&arr1)/sizeof(arr1[0]);
	printf("%d", sizeof_array);


}
