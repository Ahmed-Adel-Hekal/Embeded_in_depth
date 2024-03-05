


#include "LIFO.h"
#include <stdlib.h>


int main(){
	element_type Staticbuffer [LIFO_buffer_length] ;
	unsigned char i, temp ;
	LIFO_buffer_t static_buf, dynamic_buf ;
	//
	static_buf.length = LIFO_buffer_length ;
	static_buf.base = Staticbuffer ;
	static_buf.head = Staticbuffer ;

	printf("\n Pushing data to static buffer ");
	for(i=0; i<LIFO_buffer_length; i++){
		printf(" %d, ",i);
		LIFO_Add_Item(&static_buf, i);
	}

	printf("\n pop data from static buffer ");
	for(i=0; i<LIFO_buffer_length; i++){
		LIFO_pop_item(&static_buf,&temp);
		printf(" %d,", temp);
	}



	return 0 ;
}
