/*!
* Copyright (c) 2014, Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* All rights reserved.
*
* \file
*
* This header file is for MyWirelessApp Demo End Device application.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef _APP_H_
#define _APP_H_

/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */

#include "FreeRTOS.h"
#include "task.h"
#include  "stdio.h"

/* Fwk */
#include "LED.h"
#include "Keyboard.h"
#include "SecLib.h"
#include "SerialManager.h"
#include "RNG_Interface.h"
#include "Panic.h"
#include "MemManager.h"
#include "TimersManager.h"
#include "FunctionLib.h"

/* 802.15.4 */
#include "PhyInterface.h"
#include "MacInterface.h"

/* KSDK */
#include "board.h"
#include "fsl_os_abstraction.h"


/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/
#define mDefaultValueOfChannel_c   (0x00008000) /* channel 15 */
#define mMacExtendedAddress_c      (0xFFFFFFFFFFFFFFFF)

#define mDefaultBufferSize 		   13

#define mMaxKeysToReceive_c        32
#define mAppStackSize_c            700
#define mAppTaskPrio_c             4

/* Maximum number of outstanding packets */
#define mDefaultValueOfMaxPendingDataPackets_c 2

/* The slow polling interval is used if the coordinator
   had no data last time we polled. */
#define mDefaultValueOfPollIntervalSlow_c 820 /* ~(0.001*mDefaultValueOfPollIntervalSlow_c) secs */

/* The fast polling interval is used if the coordinator had data last time we
   polled, thus we increase the band-width while data is available. */
#define mDefaultValueOfPollIntervalFast_c 82 /* ~(0.001*mDefaultValueOfPollIntervalFast_c) secs */

#if gNvmTestActive_d
  #define mDefaultValueOfTimeoutError_c 10
#endif

#if mEnterLowPowerWhenIdle_c
  #define mDefaultValueOfMlmeHandlersToAllowSleep_c 30
#endif

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/

/* All states in the applications state machine */
enum {
  stateInit,
  stateScanActiveStart,
  stateScanActiveWaitConfirm,
  stateAssociate,
  stateAssociateWaitConfirm,
  stateListen
};

/* Events that are passed to the application task. 
   Are defined as byte masks to make possible 
   send multiple events to the task */

#define gAppEvtDummyEvent_c            (1 << 0)
#define gAppEvtRx_c           		   (1 << 1)
#define gAppEvtMessageFromMLME_c       (1 << 2)
#define gAppEvtMessageFromMCPS_c       (1 << 3)
#define gAppEvtPressedRestoreNvmBut_c  (1 << 4)
#define gAppEvTimer 				   (1 << 5)

/* Error codes */
enum {
  errorNoError,
  errorWrongConfirm,
  errorNotSuccessful,
  errorNoMessage,
  errorAllocFailed,
  errorInvalidParameter,
  errorNoScanResults
};

/******************************************************************************
*******************************************************************************
* Public Prototypes
*******************************************************************************
******************************************************************************/
#ifdef __cplusplus
    extern "C" {
#endif


#ifdef __cplusplus
}
#endif

/**********************************************************************************/
#endif /* _APP_H_ */
