/*********************************************************************************************
**
**	File Name:		dll_algorithms.c
**	Description:	Contains the function definitions for the doubly linked list algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "dll_algorithms.h"

// Searches a linked list for a value
// Returns the index or -1 if not found
int searchDList(DLinkedList* list, int data)
{
	DNode* curr = list->head;
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
DNode* splitDList(DNode* head)
{
	DNode* slow = head;
	DNode* fast = head;

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
	DNode* temp = slow->next;
	if (temp)
	{
		slow->next->prev = NULL;
	}
	slow->next = NULL;

	return temp;
}

// Helper for MergeSort
void mergeDList(DNode** first, DNode** second)
{
	// Base cases
	if (!*first)
	{
		*first = *second;
		return;
	}

	if (!*second)
	{
		*second = *first;
		return;
	}

	// Merged linked list head
	if ((*first)->data < (*second)->data)
	{
		mergeDList(&(*first)->next, &(*second));
		(*first)->next->prev = *first;
		(*first)->prev = NULL;
	}
	else
	{
		mergeDList(&(*first), &(*second)->next);
		(*second)->next->prev = *second;
		(*second)->prev = NULL;
		*first = *second;
	}
}

// For sorting the linked list
void mergeSortDList(DLinkedList* list)
{
	// Base case: list is empty or has one node, it is sorted
	if (!list->head || !list->head->next)
	{
		return;
	}

	// Split list into two halves
	DNode* second = splitDList(list->head);

	mergeSortDList(&(list->head));
	mergeSortDList(&(second));

	mergeDList(&(list->head), &second);
}