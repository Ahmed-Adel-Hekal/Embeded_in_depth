#include "bit_math.h"
#include "std_types.h"
#include "LCD_interface.h"

#include "FreeRTOS.h"
#include "task.h"

#define  F_CPU 16000000UL
#include <util/delay.h>

TaskHandle_t led2_handle , led7_handle ;
 
void led7(void *ptr);
void Generic_led(void *ptr);
void led2(void *ptr);
void print_priority(void *ptr);

typedef struct {
	u8 pin;
	volatile u8 *port; // Change from u8* to volatile u8*
} pin;

int main(void) {
	// pin pin2 = {2,&PORTC};
	// pin pin7 = {7,&PORTC};
	
	SET_BIT(DDRC, 2);
	SET_BIT(DDRC, 7);
	
	
//	xTaskCreate(&led2, NULL, 100, &pin2, 2, led2_handle);
	xTaskCreate(&print_priority, NULL, 100, NULL, 2,NULL);
	xTaskCreate(&led2, NULL, 100, NULL,1, &led2_handle);

	vTaskStartScheduler();

	while (1) {
		//TODO:: Please write your application code
	}
}


// void vApplicationIdleHook(void){
// 			vTaskPrioritySet(led2_handle,1);
// //			vTaskSuspend(led2_handle);
// }

void print_priority(void *ptr) {
	HLCD_vInit();
	UBaseType_t task_pri ;
	TickType_t lastWake ;
	const TickType_t xFrequency = 1000/portTICK_PERIOD_MS;
	lastWake= xTaskGetTickCount();
	while (1) {
		vTaskDelayUntil(&lastWake, xFrequency);
		task_pri  = uxTaskPriorityGet(led2_handle);
		HLCD_vShowInt(task_pri);
		_delay_ms(500);
	}
}
void Generic_led(void *ptr){
	pin* ledPin = (pin*) ptr; // Cast the void pointer to a pointer to the structure type
	while(1){
		SET_BIT(*(ledPin->port), ledPin->pin); // Access structure members using -> operator
	}
}

void led2(void *ptr){
	TickType_t lastWake;
	const TickType_t xFrequency = 2000/portTICK_PERIOD_MS;
	lastWake = xTaskGetTickCount();
	while (1)
	{
		vTaskDelayUntil(&lastWake, xFrequency);
		Toggle_BIT(PORTC,2);
		vTaskPrioritySet(led2_handle,3); // youcan pass null as it refer to task it self
		
	}
}

 void led7(void *ptr){
 	while (1)
 	{
 
 		//vTaskPrioritySet(led2_handle,3);
 	}
 }
