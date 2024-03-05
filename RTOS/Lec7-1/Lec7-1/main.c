#include "std_types.h"
#include "bit_math.h"
#include "DIO_Private.h"
#include "LCD_interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

#define bit1 (1 << 0)
#define bit2 (1 << 1)
#define bit3 (1 << 2)

// Create Event handler
EventGroupHandle_t eHandler = NULL;
const EventBits_t flags = (bit1| bit2 | bit3);
void setter1(void *ptr) {
	EventBits_t f ;
	while (1) {
		HLCD_vsendData('1');
		vTaskDelay(2000);
		f = xEventGroupSync(eHandler,bit1,flags,portMAX_DELAY);
// 		HLCD_vShowString("T1");
		vTaskDelete(NULL);
	}
}

void setter2(void *ptr) {
	while (1) {

		xEventGroupSync(eHandler,bit2,flags,portMAX_DELAY);
		//HLCD_vShowString("T2");
		vTaskDelete(NULL);
	}
}

void setter3(void *ptr) {
	EventBits_t ret ;
	while (1) {
		ret = xEventGroupSync(eHandler,bit3,flags,portMAX_DELAY);
		if ((ret & flags)!=0)
		{
			HLCD_vShowString("Done");
		}
		
	}
}



int main(void) {
	HLCD_vInit();	
	// Create event group
	eHandler = xEventGroupCreate();
	if (eHandler == NULL) {
		// Error handling if event group creation fails
		while (1) {
		}
	}

	// Create tasks
	xTaskCreate(setter1, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(setter2, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(setter3, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);

	// Start the scheduler
	vTaskStartScheduler();

	// Execution should not reach here
	return 0;
}
