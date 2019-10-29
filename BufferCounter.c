/*
 * Buffer.c
 *
 *  Created on: Oct 29, 2019
 *      Author: embedded
 */

#include "BufferCounter.h"

buffer_t g_buffer[BufferSize] =
{
	{0x63, buf_1}, /* 'c' */
	{0x6f, buf_2}, /* 'o' */
	{0x75, buf_3}, /* 'u' */
	{0x6e, buf_4}, /* 'n' */
	{0x74, buf_5}, /* 't' */
	{0x65, buf_6}, /* 'e' */
	{0x72, buf_7}, /* 'r' */
	{0x3d, buf_8}, /* '=' */
};

void buffer_init(uint8_t *buffer)
{
	uint8_t buff_index;

	buff_index = 0;

	do
	{
		buffer[buff_index] = g_buffer[buff_index].value;
		buff_index = g_buffer[buff_index].next;
	}while(buf_8 != buff_index);

}
