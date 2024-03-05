/*
 
 Desription : Using interrupt with freertos 
 */ 

#include "std_types.h"
#include "bit_math.h"
#include "DIO_Private.h"
#include "LCD_interface.h"
#include "EXTI_INTERFACE.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

//Create queue handler

QueueHandle_t q_handler ; 

void task1(void *ptr) ;
void task2(void *ptr) ;
int main(void)
{
	EXTI0_init();
	SET_BIT(DDRD,3);
	xTaskCreate(task1,NULL,85,NULL,2,NULL);
	xTaskCreate(task2,NULL,85,NULL,2,NULL);
	q_handler = xQueueCreate(3,sizeof(char));
	
	
	vTaskStartScheduler();
}

void task1(void *ptr){
	HLCD_vInit();
	while (1)
	{
		HLCD_vsendData('A');
		vTaskDelay(1000);

	}
}

void task2(void *ptr)
{
	char data = 0;
	while (1)
	{
		// Receive data from the queue
		if (xQueueReceive(q_handler, &data, pdMS_TO_TICKS(1000)) == pdPASS)
		{
			// Send data to the LCD
			HLCD_vsendData(data);
		}
	}
}


// Interrupt service routine for external interrupt 0
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	// Send data to the queue from ISR
	char data = 'h';
	xQueueSendFromISR(q_handler, &data, pdFALSE); // Use pdFALSE to indicate that this function is called from an ISR
}