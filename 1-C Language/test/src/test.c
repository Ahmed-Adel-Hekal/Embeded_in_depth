#include <stdio.h>
#include <stdlib.h>


enum days{Mon=-1,tue,wed=6,thu,fri,sat};
char abc(){
	int y =20 ;
	return y;
}

int main() {
union t{
	int x ;
	char arr[4];
	int y ;
}tt;

tt.x = 0 ;
tt.arr[1] = 'G' ;
tt.arr[2] = '\0';

printf("%s",tt.arr);

}


