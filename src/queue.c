/*********************************************************************************************
**
**	File Name:		queue.c
**	Description:	Contains the function definitions and assigning these functions to the
**					queue function pointers in the definition. These are all for
**					general usage of a queue.
**
**	Author:			Clarke Needles
**	Created:		6/6/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "queue_algorithms.h"

// Resize queue in memory
void resizeQueue(Queue* queue, int size)
{
	// Allocate space for the new size
	int* temp = (int*)malloc(sizeof(int) * size);
	if (!temp)
	{
		free(temp);
		return;
	}

	if (size < queue->count)
	{
		queue->count = size;
	}

	// Copying contents of old array in proper order
	// Because of the wraping when adding, 
	// We have to reset the order because of the new size
	int i = queue->head;
	for (int a = 0; a < queue->count; ++a)
	{
		temp[a] = queue->arr[i];
		i = (i + 1) % queue->size;
	}

	// Update queue values
	queue->size = size;
	queue->head = 0;
	queue->tail = queue->count;
	queue->arr = temp;
}

// Add a new item to the queue
int enqueueItem(Queue* queue, int data)
{
	// If the queue is full, do not add
	if (queue->count == queue->size)
	{
		return -1;
	}

	// Add new item, update the tail
	queue->arr[queue->tail] = data;
	// Wrap-around if necessary
	queue->tail = (queue->tail + 1) % queue->size;
	++queue->count;

	return 0;
}

// Remove an item from the queue
int dequeueItem(Queue* queue)
{
	// If the queue is empty, do not remove
	if (!queue->count)
	{
		return -1;
	}

	// Update the head (remove item from front)
	int temp = queue->head;
	queue->head = (queue->head + 1) % queue->size;
	--queue->count;

	// Return removed item
	return queue->arr[temp];
}

// Print the contents of the queue
void printQueue(Queue* queue)
{
	int i = queue->head;
	for (int a = 0; a < queue->count; ++a)
	{
		printf("%d, ", queue->arr[i]);
		i = (i + 1) % queue->size;
	}
}

// True for empty, False for not empty
int isQueueEmpty(Queue* queue)
{
	return !queue->count;
}

// Delete the heap memory the queue was using
int deleteQueue(Queue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	// Free the array
	if (queue->arr)
	{
		free(queue->arr);
		queue->arr = NULL;
	}

	// Successfull deletion
	return 0;
}

// Initialize the queue
void initQueue(Queue* queue, int size)
{
	// Allocate space for the queue array
	queue->arr = (int*)malloc(sizeof(int) * size);
	if (!queue->arr)
	{
		return;
	}

	queue->size = size;
	queue->head = 0;
	queue->tail = 0;
	queue->count = 0;
	queue->enqueue = enqueueItem;
	queue->resize = resizeQueue;
	queue->dequeue = dequeueItem;
	queue->search = searchQueue;
	queue->print = printQueue;
	queue->isEmpty = isQueueEmpty;
	queue->delete = deleteQueue;
}