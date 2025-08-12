/*********************************************************************************************
**
**	File Name:		dqueue.c
**	Description:	Contains the function definitions and assigning these functions to the
**					dynamic queue function pointers in the definition. These are all for
**					general usage of a dynamic queue.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "dqueue.h"
#include "dqueue_algorithms.h"

// Enqueue an item to the dynamic queue
void enqueueDItem(DQueue* queue, int data)
{
	Node* newNode = createNode(data);
	if (!queue->end)
	{
		queue->front = queue->end = newNode;
		return;
	}

	// The front always points towards the end
	queue->end->next = newNode;
	queue->end = newNode;
}

// Dequeue an item from the dynamic queue
int dequeueDItem(DQueue* queue)
{
	// Nothing to delete
	if (!queue->front)
	{
		return;
	}
	
	Node* temp = queue->front;
	queue->front = queue->front->next;

	// Queue is empty
	if (!queue->front)
	{
		queue->end = NULL;
	}

	int data = temp->data;
	free(temp);
	return data;
}

// Print the dynamic queue
void printDQueue(DQueue* queue)
{
	Node* curr = queue->front;
	while (curr)
	{
		printf("%d -> ", curr->data);
		curr = curr->next;
	}

	printf("NULL\n");
}

// Initialize the dynamic queue
void initDQueue(DQueue* queue)
{
	queue->front = NULL;
	queue->end = NULL;
	queue->enqueue = enqueueDItem;
	queue->dequeue = dequeueDItem;
	queue->search = searchDQueue;
	queue->sort = mergeSortDQueue;
	queue->print = printDQueue;
}