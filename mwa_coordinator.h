/*!
* Copyright (c) 2014, Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* All rights reserved.
*
* \file
*
* This header file is for MyWirelessApp Demo Coordinator application.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef _APP_H_
#define _APP_H_

#include "stdint.h"
/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/
#ifdef gPHY_802_15_4g_d
  #define mDefaultValueOfChannel_c (0x0001FFFF)
  #define mDefaultMaxChannel_c     (0x11)
#else
  #define mDefaultValueOfChannel_c (0x00008000)
#endif

#define mMacExtendedAddress_c    (0x1111111111111111)

/* Set the Coordinator short address */ 
#define mDefaultValueOfShortAddress_c     0xCAFE

/* Set the Coordinator PanID */ 
#define mDefaultValueOfPanId_c            0xBEEF

/* Maximum number of outstanding packets */
#define mDefaultValueOfMaxPendingDataPackets_c 2

#define mDefaultBufferSize 		 		  13

#define QNodesAllowed     				  5

#define NETWORK_IS_NODE_FULL			  10

/************************************************************************************
*************************************************************************************
* Private type definitions
*************************************************************************************
************************************************************************************/

/* The various states of the applications state machines. */
enum {
  stateInit,
  stateScanEdStart,
  stateScanEdWaitConfirm,
  stateStartCoordinator,
  stateStartCoordinatorWaitConfirm,
  stateListen
};

/* Events that are passed to the application task. 
   Are defined as byte masks to make possible 
   send multiple events to the task */

#define gAppEvtDummyEvent_c            (1 << 0)
#define gAppEvtRxFromUart_c            (1 << 1)
#define gAppEvtMessageFromMLME_c       (1 << 2)
#define gAppEvtMessageFromMCPS_c       (1 << 3)
#define gAppEvtStartCoordinator_c      (1 << 4)
#define gAppEvCounter1_c               (1 << 5)
#define gAppEvCounter2_c               (1 << 6)
#define gAppEvCounter3_c               (1 << 7)
#define gAppEvCounter4_c               (1 << 8)

enum
{
	counter_state_1 = 49,
	counter_state_2 = 50,
	counter_state_3 = 51,
	counter_state_4 = 52
};

typedef enum
{
	FALSE = 0,
	TRUE  = 1
} boolean_t;

typedef enum
{
	RFD = 0,
	FFD = 1
} device_t;
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

typedef struct
{
  uint16_t short_address;
  uint8_t extended_address;
  boolean_t RxOnIdle;
  device_t DeviceType;
  boolean_t IsNodeSet;
} node_t;
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
#endif /* _MAPP_H_ */
