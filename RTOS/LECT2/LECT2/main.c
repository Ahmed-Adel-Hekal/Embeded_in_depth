/*
 * main.c
 *
 * Created: 2/28/2024 4:34:19 PM
 *  Author: ahmed
 */ 

#include "bit_math.h"
#include "std_types.h"
#include "FreeRTOS.h"
#include "task.h"

#include "LCD_interface.h"

#define F_CPU 16000000
#include <util/delay.h>


// Create Task handler 

TaskHandle_t led ; 

typedef struct {
	u8  pin_number;
	volatile u8* port_address ; 
	volatile u8* ddr_address ;
	}pin_t;
	
	
void Generic_led(void *ptr);
void Lcd (void *ptr);

int main(void)
{
	// make object from struct to use 
	pin_t Led3 = {3,&PORTD,&DDRD};
	pin_t Led2 = {2,&PORTC,&DDRC};
	pin_t Led1 = {7,&PORTC,&DDRC};
		
	// create Task 
	xTaskCreate(&Generic_led,"Led3",85, &Led3, 2, &led);
	//xTaskCreate(&Generic_led,"Led2",85, &Led2, 2, NULL);
	xTaskCreate(&Lcd,"LCD",120, NULL, 3, NULL);

	
	vTaskStartScheduler();
}


// create tasks for lcd & led 
void Generic_led(void *ptr){
	// cast pointer to struct pin that holds port_address & pin_number 
	pin_t *pin = (pin_t *) ptr  ;
	SET_BIT(*(pin->ddr_address), (pin->pin_number));
	// Adding periodicity to  task 
	// Note this is best way to make periodicity
	TickType_t last_wake = xTaskGetTickCount() ; 
	TickType_t delay     = 1000/ portTICK_PERIOD_MS  ;
	while (1)
	{
		vTaskDelayUntil(&last_wake, delay);
		Toggle_BIT(*(pin->port_address), (pin->pin_number));
		//_delay_ms(20);
	}
}


// LCD Task 

void Lcd (void *ptr){
	u8 temp = 0 ; 
	HLCD_vInit() ;
	
	// Task periodicity 
	TickType_t last_wake = xTaskGetTickCount ();
	TickType_t delay   = 500 / portTICK_PERIOD_MS;
	while(1){
		vTaskDelayUntil(&last_wake, delay) ; 
		temp = uxTaskPriorityGet(led) ; 
		//HLCD_vShowString("Task Priority :");
		HLCD_vShowInt(temp);
		temp++;
		vTaskPrioritySet(led, temp);
	
		if (temp >= 4 )
		{
			vTaskPrioritySet(led, 1);
		}
	}
}
