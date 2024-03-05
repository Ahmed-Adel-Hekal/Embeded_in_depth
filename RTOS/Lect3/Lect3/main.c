/*

	Description :- Using QueueSets with Tasks

*/


#include "std_types.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "LCD_interface.h"

#define MAX_MESSAGE_LENGTH 10
#define QUEUE_LENGTH 5

// Declare queue handles
QueueHandle_t xQueue1, xQueue2;

// Declare a queue set handle
QueueSetHandle_t xQueueSet;

// Task prototypes
void SenderTask1(void *pvParameters);
void SenderTask2(void *pvParameters);
void ReceiverTask(void *pvParameters);

int main(void) {
	// Initialize LCD
	HLCD_vInit();
	
	// Create two queues
	xQueue1 = xQueueCreate(QUEUE_LENGTH, sizeof(char *));
	xQueue2 = xQueueCreate(QUEUE_LENGTH, sizeof(char *));
	
	// Create a queue set
	xQueueSet = xQueueCreateSet(QUEUE_LENGTH * 2);
	
	// Add the queues to the queue set
	xQueueAddToSet(xQueue1, xQueueSet);
	xQueueAddToSet(xQueue2, xQueueSet);
	
	if (xQueue1 != NULL && xQueue2 != NULL && xQueueSet != NULL) {
		// Create Sender tasks
		xTaskCreate(SenderTask1, "Sender1", 120, NULL, tskIDLE_PRIORITY + 1, NULL);
		xTaskCreate(SenderTask2, "Sender2", 120, NULL, tskIDLE_PRIORITY + 1, NULL);
		
		// Create the Receiver task
		xTaskCreate(ReceiverTask, "Receiver", 120, NULL, tskIDLE_PRIORITY + 2, NULL);
		
		// Start the FreeRTOS scheduler
		vTaskStartScheduler();
	}
	
	// The scheduler should never return, but in case it does, return 1
	return 1;
}

void SenderTask1(void *pvParameters) {
	const char *message = "H1";
	TickType_t lastwake = xTaskGetTickCount();
	TickType_t delay = 4000/portTICK_PERIOD_MS ;
	BaseType_t  state ;
	while (1)
	{
		vTaskDelayUntil(&lastwake, delay);
		// Send the message pointer to Queue1
		state = xQueueSend(xQueue1, &message, portMAX_DELAY);
// 		if(state == pdTRUE ){
// 			HLCD_vsendData('D');
// 		}
	}

	
	// Delete the task (optional)
	// 	vTaskDelete(NULL);
}

void SenderTask2(void *pvParameters) {
	const char *message = "H2";
	TickType_t lastwake = xTaskGetTickCount();
	TickType_t delay = 2000/portTICK_PERIOD_MS ;
	while (1)
	{
		vTaskDelayUntil(&lastwake, delay);
		// Send the message pointer to Queue1
		xQueueSend(xQueue2, &message, portMAX_DELAY);
	}

}


void ReceiverTask(void *pvParameters) {
	const char *receivedMessage[2];
	QueueSetMemberHandle_t xActivatedMember;
	
	while (1) {
		// Wait to receive a pointer to a string from any queue in the queue set
		xActivatedMember = xQueueSelectFromSet(xQueueSet, portMAX_DELAY);
		
		// Check which queue the message came from
		if (xActivatedMember == xQueue1) {
			
			// Receive message from Queue1
			xQueueReceive(xQueue1, &receivedMessage[0], portMAX_DELAY);
			
			} else if (xActivatedMember == xQueue2) {
			// Receive message from Queue2
			xQueueReceive(xQueue2, &receivedMessage[0], portMAX_DELAY);

		}
		// Display the received message on LCD
// 		HLCD_u8GotoXY(1,1);
		HLCD_vShowString(receivedMessage[0]);

		// 		HLCD_vShowString(receivedMessage[1]);

	}
}



