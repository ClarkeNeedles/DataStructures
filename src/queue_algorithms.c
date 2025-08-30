/*********************************************************************************************
**
**	File Name:		queueu_algorithms.c
**	Description:	Contains the function definitions for the queue algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/10/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "algos/queue_algorithms.h"

// Search the queue for an item
// Returns the index
int searchQueue(Queue* queue, int data)
{
	int i = queue->head;
	for (int a = 0; a < queue->count; ++a)
	{
		if (queue->arr[i] == data)
		{
			return i;
		}
		i = (i + 1) % queue->size;
	}

	// Not found
	return -1;
}