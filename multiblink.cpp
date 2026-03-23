/***
 * Demo program to flash 5 LED attached to GPIO PAD 0, 2,3,4, 5.
 * Uses FreeRTOS Task
 * Bing Weng
 * 3-Mar-2026
 */


#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

#include "BlinkAgent.h"


//Standard Task priority
#define TASK_PRIORITY		( tskIDLE_PRIORITY + 1UL )

//LED PAD to use
#define LED0_PAD 25
#define LED1_PAD 0
#define LED2_PAD 1
#define LED3_PAD 2
#define LED4_PAD 3
#define LED5_PAD 4
#define LED6_PAD 5
#define LED7_PAD 6
#define LED8_PAD 7
#define LED9_PAD 8
#define LED10_PAD 9
#define LED11_PAD 10
#define LED12_PAD 11
#define LED13_PAD 12
#define LED14_PAD 13
#define LED15_PAD 14
#define LED16_PAD 15
#define LED17_PAD 16
#define LED18_PAD 17
#define LED19_PAD 18
#define LED20_PAD 19
#define LED21_PAD 20
#define LED22_PAD 21
#define LED23_PAD 22
#define LED24_PAD 23
#define LED25_PAD 24
#define LED26_PAD 26
#define LED27_PAD 27
#define LED28_PAD 28
#define LED29_PAD 29

void runTimeStats(   ){
	TaskStatus_t *pxTaskStatusArray;
	volatile UBaseType_t uxArraySize, x;
	unsigned long ulTotalRunTime;


   // Get number of takss
   uxArraySize = uxTaskGetNumberOfTasks();
   printf("Number of tasks %d\n", uxArraySize);

   //Allocate a TaskStatus_t structure for each task.
   pxTaskStatusArray = (TaskStatus_t *)pvPortMalloc( uxArraySize * sizeof( TaskStatus_t ) );

   if( pxTaskStatusArray != NULL ){
      // Generate raw status information about each task.
      uxArraySize = uxTaskGetSystemState( pxTaskStatusArray,
                                 uxArraySize,
                                 &ulTotalRunTime );

	 // Print stats
	 for( x = 0; x < uxArraySize; x++ )
	 {
		 printf("Task: %d \t cPri:%d \t bPri:%d \t hw:%d \t%s\n",
				pxTaskStatusArray[ x ].xTaskNumber ,
				pxTaskStatusArray[ x ].uxCurrentPriority ,
				pxTaskStatusArray[ x ].uxBasePriority ,
				pxTaskStatusArray[ x ].usStackHighWaterMark ,
				pxTaskStatusArray[ x ].pcTaskName
				);
	 }


      // Free array
      vPortFree( pxTaskStatusArray );
   } else {
	   printf("Failed to allocate space for stats\n");
   }

   //Get heap allocation information
   HeapStats_t heapStats;
   vPortGetHeapStats(&heapStats);
   printf("HEAP avl: %d, blocks %d, alloc: %d, free: %d\n",
		   heapStats.xAvailableHeapSpaceInBytes,
		   heapStats.xNumberOfFreeBlocks,
		   heapStats.xNumberOfSuccessfulAllocations,
		   heapStats.xNumberOfSuccessfulFrees
		   );
}


/***
 * Main task to blink external LED
 * @param params - unused
 */
void mainTask(void *params){

    BlinkAgent led0(LED0_PAD);
    BlinkAgent led1(LED1_PAD);
    BlinkAgent led2(LED2_PAD);
    BlinkAgent led3(LED3_PAD);
    BlinkAgent led4(LED4_PAD);
    BlinkAgent led5(LED5_PAD);
    BlinkAgent led6(LED6_PAD);
    BlinkAgent led7(LED7_PAD);
    BlinkAgent led8(LED8_PAD);
    BlinkAgent led9(LED9_PAD);
    BlinkAgent led10(LED10_PAD);
    BlinkAgent led11(LED11_PAD);
    BlinkAgent led12(LED12_PAD);
    BlinkAgent led13(LED13_PAD);
    BlinkAgent led14(LED14_PAD);
    BlinkAgent led15(LED15_PAD);
    BlinkAgent led16(LED16_PAD);
    BlinkAgent led17(LED17_PAD);
    BlinkAgent led18(LED18_PAD);
    BlinkAgent led19(LED19_PAD);
    BlinkAgent led20(LED20_PAD);
    BlinkAgent led21(LED21_PAD);
    BlinkAgent led22(LED22_PAD);
    BlinkAgent led23(LED23_PAD);
    BlinkAgent led24(LED24_PAD);
    BlinkAgent led25(LED25_PAD);
    BlinkAgent led26(LED26_PAD);
    BlinkAgent led27(LED27_PAD);
    BlinkAgent led28(LED28_PAD);
    BlinkAgent led29(LED29_PAD);

	printf("Main task started\n");

	led0.start("LED0", TASK_PRIORITY);
	led1.start("LED1", TASK_PRIORITY + 1);
	led2.start("LED2", TASK_PRIORITY + 2);
	led3.start("LED3", TASK_PRIORITY + 3);
	led4.start("LED4", TASK_PRIORITY + 4);
	led5.start("LED5", TASK_PRIORITY + 5);
	led6.start("LED6", TASK_PRIORITY + 6);
	led7.start("LED7", TASK_PRIORITY + 7);
	led8.start("LED8", TASK_PRIORITY + 8);
    led9.start("LED9", TASK_PRIORITY + 9);
	led10.start("LED10", TASK_PRIORITY + 10);
	led11.start("LED11", TASK_PRIORITY + 11);
	led12.start("LED12", TASK_PRIORITY + 12);
	led13.start("LED13", TASK_PRIORITY + 13);
	led14.start("LED14", TASK_PRIORITY + 14);
	led15.start("LED15", TASK_PRIORITY + 15);
	led16.start("LED16", TASK_PRIORITY + 16);
    led17.start("LED17", TASK_PRIORITY + 17);
	led18.start("LED18", TASK_PRIORITY + 18);
	led19.start("LED19", TASK_PRIORITY + 19);
	led20.start("LED20", TASK_PRIORITY + 20);
	led21.start("LED21", TASK_PRIORITY + 21);
	led22.start("LED22", TASK_PRIORITY + 22);
	led23.start("LED23", TASK_PRIORITY + 23);
	led24.start("LED24", TASK_PRIORITY + 24);
    led25.start("LED25", TASK_PRIORITY + 25);
	led26.start("LED26", TASK_PRIORITY + 26);
    led27.start("LED27", TASK_PRIORITY + 24);
    led28.start("LED28", TASK_PRIORITY + 25);
	led29.start("LED29", TASK_PRIORITY + 26);

	while (true) { // Loop forever
		runTimeStats();
		vTaskDelay(1000);
	}
}




/***
 * Launch the tasks and scheduler
 */
void vLaunch( void) {

	//Start blink task
    TaskHandle_t task;
    xTaskCreate(mainTask, "MainThread", 500, NULL, TASK_PRIORITY, &task);

    /* Start the tasks and timer running. */
    vTaskStartScheduler();
}

/***
 * Main
 * @return
 */
int main( void )
{
	//Setup serial over USB and give a few seconds to settle before we start
    stdio_init_all();
    sleep_ms(3000);
    printf("GO\n");

    //Start tasks and scheduler
    const char *rtos_name = "FreeRTOS";
    printf("Starting %s on core 0:\n", rtos_name);
    vLaunch();


    return 0;
}
