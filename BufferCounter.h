/*
 * BufferCounter.h
 *
 *  Created on: Oct 29, 2019
 *      Author: embedded
 */

#ifndef BUFFERCOUNTER_H_
#define BUFFERCOUNTER_H_

#include "stdint.h"

#define BufferSize 12

typedef enum
{
	buf_0,
	buf_1,
	buf_2,
	buf_3,
	buf_4,
	buf_5,
	buf_6,
	buf_7,
	buf_8,
	buf_9,
	buf_10,
	buf_11,
	buf_12
} buffer_index_t;

typedef struct
{
	uint8_t value;
	buffer_index_t next;
} buffer_t;

void buffer_init(uint8_t *buffer);


#endif /* BUFFERCOUNTER_H_ */
