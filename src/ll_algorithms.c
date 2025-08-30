/*********************************************************************************************
**
**	File Name:		ll_algorithms.c
**	Description:	Contains the function definitions for the linked list algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "algos/ll_algorithms.h"

// Searches a linked list for a value
// Returns the index or -1 if not found
int searchList(LinkedList* list, int data)
{
	Node* curr = list->head;
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
Node* splitList(Node* head)
{
	Node* slow = head;
	Node* fast = head;

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
void mergeList(Node** first, Node** second)
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

	mergeList(&(*first)->next, second);
}

// For sorting the linked list
void mergeSortList(LinkedList* list)
{
	// Base case: list is empty or has one node, it is sorted
	if (!list->head || !list->head->next)
	{
		return;
	}

	// Split list into two halves
	Node* second = splitList(list->head);

	mergeSortList(&(list->head));
	mergeSortList(&(second));

	mergeList(&(list->head), &second);
}