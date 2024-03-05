/*
 * main.c
 *
 * Created: 3/4/2024 5:50:31 PM
 *  Author: ahmed
 */ 

#include "std_types.h"
#include "bit_math.h"
#include "FreeRTOS.h"
#include "task.h"
#include "EXTI_INTERFACE.h"
#include "LCD_interface.h"
// #include "DIO_Private.h"

TaskHandle_t task_h ; 

void task1(void *ptr);
int main(void)
{
	HLCD_vInit();
	EXTI0_init();
	xTaskCreate(task1,NULL,80,NULL,2,&task_h);
	vTaskStartScheduler();
}

void task1(void *ptr){
	
	while(1){
		if (ulTaskNotifyTake(pdTRUE, 0) != 0 )
		{
			HLCD_vsendData('H');
		}
	}
}


void __vector_1(void) __attribute__((signal)) ; 
void __vector_1(void){
	vTaskNotifyGiveFromISR(task_h, pdFALSE);
} 