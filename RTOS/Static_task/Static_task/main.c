#include "std_types.h"
#include "bit_math.h"
#include "FreeRTOS.h"
#include "task.h"

#define STACK_SIZE 100

// Function prototypes
void task1(void *ptr);

// Define task stack and control block statically
StaticTask_t tcb_block;
StackType_t task_stack[STACK_SIZE];



int main(void)
{
	// Create the task statically
	xTaskCreateStatic(task1,          // Task function
	NULL,           // Task name (not used)
	STACK_SIZE,     // Stack size
	NULL,           // Task parameters (not used)
	2,              // Task priority
	task_stack,     // Task stack buffer
	&tcb_block);    // Task control block

	// Start the FreeRTOS scheduler
	vTaskStartScheduler();

	return 0;
}

void task1(void *ptr)
{
	SET_BIT(DDRD, 3);  // Set pin as output

	while (1)
	{
		// Toggle the output pin
		Toggle_BIT(PORTD, 3);

		// Delay for a while
		vTaskDelay(500);
	}
}



void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
StackType_t ** ppxIdleTaskStackBuffer,
uint32_t * pulIdleTaskStackSize )
{
	// Define the idle task control block and stack statically
	static StaticTask_t xIdleTaskTCB;
	static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

	// Pass out pointers to the idle task control block and stack
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
	*ppxIdleTaskStackBuffer = uxIdleTaskStack;

	// Pass out the size of the idle task stack
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}