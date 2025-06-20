/*********************************************************************************************
**
**	File Name:		dqueue_algorithms.c
**	Description:	Contains the function definitions for the dynamic queue algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "dqueue_algorithms.h"

// Searches a queue for a value
// Returns the index or -1 if not found
int searchDQueue(DQueue* queue, int data)
{
	Node* curr = queue->front;
	int index = 0;
	while (curr)
	{
		// Item found
		if (curr->data == data)
		{
			return index;
		}

		curr = curr->next;
		++index;
	}

	// Item was not found
	return -1;
}

// Helper for MergeSort
Node* splitDQueue(Node* front)
{
	Node* slow = front;
	Node* fast = front;

	// Fast moves twice as fast as slow
	// This will locate the middle of the list
	while (fast && fast->next)
	{
		fast = fast->next->next;

		if (fast)
		{
			slow = slow->next;
		}
	}

	// Split the list into half
	Node* temp = slow->next;
	slow->next = NULL;

	return temp;
}

// Helper for MergeSort
void mergeDQueue(Node** first, Node** second)
{
	if (!*first)
	{
		*first = *second;
		return;
	}
	if (!*second)
	{
		return;
	}

	// Pick the smaller value between first and second nodes
	if ((*first)->data > (*second)->data)
	{
		Node* temp = *second;
		*second = (*second)->next;
		temp->next = *first;
		*first = temp;
	}

	mergeDQueue(&(*first)->next, second);
}

// For sorting the queue
void mergeSortDQueue(DQueue* queue)
{
	// Base case: list is empty or has one node, it is sorted
	if (!queue->front || !queue->front->next)
	{
		return;
	}

	// Split list into two halves
	Node* second = splitDQueue(queue->front);

	mergeSortDQueue(&(queue->front));
	mergeSortDQueue(&(second));

	mergeDQueue(&(queue->front), &second);
}