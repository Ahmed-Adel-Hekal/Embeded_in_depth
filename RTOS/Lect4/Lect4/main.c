#include "std_types.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h" // Include semaphore support
#include "LCD_interface.h"

// Semaphore handle for LCD access
SemaphoreHandle_t xLCDSemaphore;

void Task1(void *pvParameters);
void Task2(void *pvParameters);

int main(void) {
	// Initialize LCD
	HLCD_vInit();

	// Create semaphore
	xLCDSemaphore = xSemaphoreCreateBinary();


		// Create Task1
		xTaskCreate(Task1, "Task1", 100, NULL, 2, NULL);
		
		// Create Task2
		xTaskCreate(Task2, "Task2", 100, NULL, 2, NULL);

		// Start scheduler
		vTaskStartScheduler();
	

	return 0;
}

void Task1(void *pvParameters) {
	    while (1) {
		    // Attempt to take the LCD semaphore
// 		    if (xSemaphoreTake(xLCDSemaphore, portMAX_DELAY) == pdTRUE) {
			    // Task 1 has exclusive access to LCD
				HLCD_u8GotoXY(0,0);
			    HLCD_vShowString("Task 1");
			    
			    // Release the semaphore
// 			    xSemaphoreGive(xLCDSemaphore);
// 		    }

		    // Delay before next iteration
		    vTaskDelay(500 / portTICK_PERIOD_MS);
	    }
}

void Task2(void *pvParameters) {
 	    xSemaphoreGive(xLCDSemaphore);
	    while (1) {
		    // Attempt to take the LCD semaphore
// 		    if (xSemaphoreTake(xLCDSemaphore, portMAX_DELAY) == pdTRUE) {
			    // Task 1 has exclusive access to LCD
				HLCD_u8GotoXY(1,0);
			    HLCD_vShowString("Task 2");
// 			    
// 			    // Release the semaphore
// 			    xSemaphoreGive(xLCDSemaphore);
// 		    }


		    // Delay before next iteration
		    vTaskDelay(500 / portTICK_PERIOD_MS);
	    }
}
