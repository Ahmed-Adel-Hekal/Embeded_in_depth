/*
Description : Software Timers in Freertos
*/

#include "std_types.h"
#include "bit_math.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "LCD_interface.h"


TimerHandle_t oneShot, autoReload ;
BaseType_t    oneShot_started,autoRelaod_started ;

size_t timerHandleSize = sizeof(TimerHandle_t);

void OneshotTask(TimerHandle_t t){
	HLCD_vShowString("One");
}


void AutoReloadTask(TimerHandle_t t){
// 	HLCD_vShowString("Auto");
HLCD_vShowInt(sizeof(timerHandleSize));
}

int main(void)
{
	
	HLCD_vInit();
	oneShot = xTimerCreate("OneShot",
	1000/portTICK_PERIOD_MS,
	pdFALSE,
	NULL,
	&OneshotTask);
	
	autoReload = xTimerCreate("AutoReload",
	500/portTICK_PERIOD_MS,
	pdTRUE,
	NULL,
	&AutoReloadTask);
	
	oneShot_started = xTimerStart(oneShot,0);
	autoRelaod_started = xTimerStart(autoReload,0);

	vTaskStartScheduler();
}

