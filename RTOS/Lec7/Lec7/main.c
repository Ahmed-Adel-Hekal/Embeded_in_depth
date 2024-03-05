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

void setter(void *ptr) {
	while (1) {
		xEventGroupSetBits(eHandler, bit1);
		vTaskDelay(pdMS_TO_TICKS(500));
		xEventGroupSetBits(eHandler, bit2);
		vTaskDelay(pdMS_TO_TICKS(500));
		xEventGroupSetBits(eHandler, bit3);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

// Remeber your task is in block state till all flags are set
void getter(void *ptr) {
	EventBits_t xEventGroup;
	const EventBits_t flags_s = (bit1 | bit2 | bit3);

	while (1) {
		xEventGroup = xEventGroupWaitBits(eHandler, flags_s, pdTRUE, pdFALSE, portMAX_DELAY);
 		HLCD_vShowInt(xEventGroup);
		if (xEventGroup != 0) {
			xEventGroupClearBits(eHandler, flags_s);
			// Update LCD
			HLCD_vsendData('x');
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
	xTaskCreate(setter, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(getter, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);

	// Start the scheduler
	vTaskStartScheduler();

	// Execution should not reach here
	return 0;
}
