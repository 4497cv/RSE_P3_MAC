/*
 * MyNewTask.c
 *
 *  Created on: Oct 27, 2019
 *      Author: embedded
 */

#include "MyNewTask.h"
#include "stdio.h"

static osaEventId_t mMyEvents;

/* global variable to store timer ID */
static tmrTimerID_t myTimerID = gTmrInvalidTimerID_c;

/* Handler ID for the task */
static osaTaskId_t gMyTaskHandler_ID;
/* local variable to store the current state of the leds */
static uint8_t ledsState = 0;

OSA_TASK_DEFINE(My_Task, gMyTaskPriority_c, 1, gMyTaskStackSize_c, FALSE);

static void myTaskTimerCallback(void*param)
{
	OSA_EventSet(mMyEvents, gMyNewTaskEvent2_c);
}

void My_Task(osaTaskParam_t argument)
{
	osaEventFlags_t customEvent;
	myTimerID = TMR_AllocateTimer();

	while(1)
	{
		OSA_EventWait(mMyEvents, osaEventFlagsAll_c, FALSE, osaWaitForever_c, &customEvent);

		if( !gUseRtos_c && !customEvent)
		{
			break;
		}

		/* Depending on the received event */
		switch(customEvent)
		{
			case gMyNewTaskEvent1_c:
				TMR_StartIntervalTimer(myTimerID,
											1000,
							 myTaskTimerCallback,
											NULL
									   );
				TurnOffLeds();
			break;
			case gMyNewTaskEvent2_c:
				if(!ledsState)
				{
					TurnOnLeds();
					ledsState = 1;
				}
				else
				{
					TurnOffLeds();
					ledsState = 0;
				}
			break;
			case gMyNewTaskEvent3_c:
				ledsState = 0;
				TurnOffLeds();
				TMR_StopTimer(myTimerID);
			break;
			default:
			break;
		}
	}
}

void MyTask_Init(void)
{
	mMyEvents = OSA_EventCreate(TRUE);

	gMyTaskHandler_ID = OSA_TaskCreate(OSA_TASK(My_Task), NULL);
}

void MyTaskTimer_Stop(void)
{
	OSA_EventSet(mMyEvents, gMyNewTaskEvent3_c);
}

void MyTaskTimer_Start(void)
{
	OSA_EventSet(mMyEvents, gMyNewTaskEvent1_c);
}
