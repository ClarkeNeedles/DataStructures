/*********************************************************************************************
**
**	File Name:		dstack_algorithms.c
**	Description:	Contains the function definitions for the dynamic stack algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "algos/dstack_algorithms.h"

// Searches a stack for a value
// Returns the index or -1 if not found
int searchDStack(DStack* stack, int data)
{
	Node* curr = stack->top;
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
Node* splitDStack(Node* head)
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
void mergeDStack(Node** first, Node** second)
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

	mergeDStack(&(*first)->next, second);
}

// For sorting the stack
void mergeSortDStack(DStack* stack)
{
	// Base case: list is empty or has one node, it is sorted
	if (!stack->top || !stack->top->next)
	{
		return;
	}

	// Split list into two halves
	Node* second = splitDStack(stack->top);

	mergeSortDStack(&(stack->top));
	mergeSortDStack(&(second));

	mergeDStack(&(stack->top), &second);
}