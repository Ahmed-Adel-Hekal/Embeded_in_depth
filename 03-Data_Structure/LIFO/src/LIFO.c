/*
 ============================================================================
 Name        : LIFO.c
 Author      : Ahmed Hekal
 Version     :
 Copyright   : This is open source projec tfeel free to contact if needed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "LIFO.h"



LIFO_error_t LIFO_Buf_Is_Full(LIFO_buffer_t* buf){
	if(!buf|| !buf->head || !buf->base){
		return LIFO_Null ;
	}
	if(buf->head >=(buf->base + buf->count)){
		return LIFO_full ;
	}
	else{
		return LIFO_not_full ;
	}
}

LIFO_error_t LIFO_Add_Item(LIFO_buffer_t *buf, element_type item)
{
//	if(LIFO_Buf_Is_Full(buf)== LIFO_Null){
//		return LIFO_Null ;
//	}
//	if(LIFO_Buf_Is_Full(buf)==LIFO_full){
//		return LIFO_full ;
//	}
	*(buf->head) = item ;
	buf->count++ ;
	buf->head++ ;
	return LIFO_no_error ;
}

LIFO_error_t LIFO_pop_item (LIFO_buffer_t *buf, element_type *item){
//	if(LIFO_Buf_Is_Full(buf)==LIFO_Null){
//		return LIFO_Null;
//	}
//	if(LIFO_Buf_Is_Full(buf)==LIFO_empty){
//		return LIFO_empty ;
//	}
	buf->head--;
	*item=*(buf->head);
	buf->count--;
	return LIFO_no_error ;
}

