/*
FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
All rights reserved

VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

This file is part of the FreeRTOS distribution.

FreeRTOS is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License (version 2) as published by the
Free Software Foundation >>!AND MODIFIED BY!<< the FreeRTOS exception.

***************************************************************************
>>!   NOTE: The modification to the GPL is included to allow you to     !<<
>>!   distribute a combined work that includes FreeRTOS without being   !<<
>>!   obliged to provide the source code for proprietary components     !<<
>>!   outside of the FreeRTOS kernel.                                   !<<
***************************************************************************

FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  Full license text is available on the following
link: http://www.freertos.org/a00114.html

http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
the FAQ page "My application does not run, what could be wrong?".  Have you
defined configASSERT()?

http://www.FreeRTOS.org/support - In return for receiving this top quality
embedded software for free we request you assist our global community by
participating in the support forum.

http://www.FreeRTOS.org/training - Investing in training allows your team to
be as productive as possible as early as possible.  Now you can receive
FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
Ltd, and the world's leading authority on the world's leading RTOS.

http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
including FreeRTOS+Trace - an indispensable productivity tool, a DOS
compatible FAT file system, and our tiny thread aware UDP/IP stack.

http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
licenses offer ticketed support, indemnification and commercial middleware.

http://www.SafeRTOS.com - High Integrity Systems also provide a safety
engineered and independently SIL3 certified version for use in safety and
mission critical applications that require provable dependability.

1 tab == 4 spaces!
*/

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>

/* Demo includes. */
#include "supporting_functions.h"

/* Used as a loop counter to create a very crude delay. */
#define mainDELAY_LOOP_COUNT		( 0xffffff )

/* The task functions. */
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);
void vTask3(void *pvParameters);


/*-----------------------------------------------------------*/

int main(void)
{
	/* Create one of the two tasks. */
	xTaskCreate(vTask1,		/* Pointer to the function that implements the task. */
		"Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
		1000,		/* Stack depth - most small microcontrollers will use much less stack than this. */
		NULL,		/* We are not using the task parameter. */
		1,			/* This task will run at priority 1. */
		NULL);		/* We are not using the task handle. */
	xTaskCreate(vTask2,		/* Pointer to the function that implements the task. */
		"Task 2",	/* Text name for the task.  This is to facilitate debugging only. */
		1000,		/* Stack depth - most small microcontrollers will use much less stack than this. */
		NULL,		/* We are not using the task parameter. */
		2,			/* This task will run at priority 2. */
		NULL);		/* We are not using the task handle. */
					/* Create the other task in exactly the same way. */
	xTaskCreate(vTask3,		/* Pointer to the function that implements the task. */
		"Task 3",	/* Text name for the task.  This is to facilitate debugging only. */
		1000,		/* Stack depth - most small microcontrollers will use much less stack than this. */
		NULL,		/* We are not using the task parameter. */
		3,			/* This task will run at priority 3. */
		NULL);		/* We are not using the task handle. */

					/* Start the scheduler to start the tasks executing. */
	vTaskStartScheduler();

	/* The following line should never be reached because vTaskStartScheduler()
	will only return if there was not enough FreeRTOS heap memory available to
	create the Idle and (if configured) Timer tasks.  Heap management, and
	techniques for trapping heap exhaustion, are described in the book text. */
	for (;; );
	return 0;
}
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/

void vTask1(void *pvParameters)
{
	const char *pcTaskName = "Task 1 is running\r\n";


	/* As per most tasks, this task is implemented in an infinite loop. */
	FILE *ptr_file;
	int sx1, sy1, sx2, sy2;
	ptr_file = fopen("C:\\UNT\\input.txt", "w");
	if (ptr_file != NULL) {
		const char *text = "Write this to the file";
	}
	else {
		printf("\nerror reading file\n");
	}

	while (1) {
                   clock_t begin = clock();
		   vTaskDelay(200);
		/* Task body, always written as an infinite loop.       */
		printf("\n****This is task 1 begin****");
		ptr_file = fopen("C:\\UNT\\input.txt", "r");
		if (ptr_file != NULL) {
			fscanf(ptr_file, "%d %d %d %d", &sx1, &sy1, &sx2, &sy2);
		}
		else {
			printf("\nerror reading file\n");
		}
		float x = ((sx1 - sx2)*(sx1 - sx2)) + ((sy1 - sy2)*(sy1 - sy2));
		//printf("x value=%f\n", x);
		double dist = sqrt(x);
                clock_t end = clock();
		double time_spent = end - begin;
		double velocity = dist / time_spent;
		printf("\ndistance is %f and responsetime is %0.3f and velocity=%0.3f", dist, time_spent, velocity);
		printf("\n****This is task 1 end****\n");
	}
}
/*-----------------------------------------------------------*/

void vTask2(void *pvParameters)
{

	const char *pcTaskName = "Task 2 is running\r\n";
	int i, n, sum = 0, count = 0, max = 50, min = 20;
	float avg;
	while (1)
	{
		vTaskDelay(200);
		clock_t begin = clock();
		for (i = 1; i <= 24; i++)
		{
			n = rand() % 31 + 20;
			printf("\nno.of students in %d hour is %d\n", i, n);
			sum = sum + n;
			avg = sum / i;
			if (n > max) max = n;
			if (min > n) min = n;
		}
		clock_t end = clock();
		double resp_time = end - begin;
		printf("max number is %d and min number is %d\n ", max, min);
		printf("\nTotal number of students in class for 24hrs is %d\n", sum);
		printf("\n average of the class for one day is %f", avg);
		printf("\n Responsetime of task is %0.3f", resp_time);
	}

}


void vTask3(void *pvParameters)
{

	int i, power, energy, sum = 0, t = 1;
	float avg;

	while (1)
	{
		vTaskDelay(100);
		clock_t begin = clock();
		for (i = 1; i <= 60; i++)
		{
			power = rand() % 191 + 10;
			printf("\n power reading for every second is %d\n", power);
			energy = power*t;
			sum = sum + energy;
			avg = (float)sum / i;
			if (power>5 * avg)
				printf("spikes found when the power %d", power);

		}
		clock_t end = clock();
		float resp_time = end - begin;
		printf("Total energy consumption %d\n", sum);
		printf("\n average energy consumed per minute is  %d", avg);
		printf("\n Responsetime of task 3 is %0.3f", resp_time);
	}
}