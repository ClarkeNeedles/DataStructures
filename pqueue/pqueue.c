/*********************************************************************************************
**
**	File Name:		pqueue.c
**	Description:	Contains the function definitions and assigning these functions to the
**					priority queue function pointers in the definition. These are all for
**					general usage of a priority queue.
**
**	Author:			Clarke Needles
**	Created:		6/18/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"

// Enqueue an item into the priority queue
int enqueuePItem(PQueue* pqueue, int data, int priority)
{
	pqueue->heap.insert(&pqueue->heap, data, priority);
}

// Dequeue an item from the priority queue
// Uses pointers to essentially return both data
// and priority of the dequeued item
int dequeuePItem(PQueue* pqueue, int* data, int* priority)
{
	if (!pqueue->heap.root)
	{
		return -1;
	}

	pqueue->heap.removeRoot(&pqueue->heap, data, priority);

	return 0;
}

// Print the priority queue
void printPQueue(PQueue* pqueue)
{
	printf("Front\n");

	for (int i = 0; i < pqueue->heap.count; ++i)
	{
		printf("Data: %d, Priority: %d\n", 
			pqueue->heap.root[i].data, pqueue->heap.root[i].priority);
	}

	printf("Rear\n");
}

// Check if the priority queue is empty
int isPQueueEmpty(PQueue* pqueue)
{
	return !pqueue->heap.count;
}

// Delete the priority queue
int deletePQueue(PQueue* pqueue)
{
	pqueue->heap.delete(&pqueue->heap);

	if (pqueue->heap.root)
	{
		return -1;
	}

	return 0;
}

void initPQueue(PQueue* pqueue, int size, QueueType type)
{
	initHeap(&pqueue->heap, size, type);

	pqueue->enqueue = enqueuePItem;
	pqueue->dequeue = dequeuePItem;
	pqueue->print = printPQueue;
	pqueue->delete = deletePQueue;
	pqueue->isEmpty = isPQueueEmpty;
}