/*
 * MyNewTask.h
 *
 *  Created on: Oct 27, 2019
 *      Author: embedded
 */

#ifndef MYNEWTASK_H_
#define MYNEWTASK_H_

/* Drv */
#include "LED.h"

/* Fwk */
#include "TimersManager.h"
#include "FunctionLib.h"

#include "fsl_common.h"
#include "EmbeddedTypes.h"
#include "fsl_os_abstraction.h"

#include "stdio.h"

/* Define the available Task's Events */
#define gMyNewTaskEvent1_c (1 << 0)
#define gMyNewTaskEvent2_c (1 << 1)
#define gMyNewTaskEvent3_c (1 << 2)

#define gMyTaskPriority_c 3
#define gMyTaskStackSize_c 400

void My_Task(osaTaskParam_t argument);
void MyTaskTimer_Start(void);
void MyTaskTimer_Stop(void);
void MyTask_Init(void);

//void My_Task(osaTaskParam_t argument);

#endif /* MYNEWTASK_H_ */
