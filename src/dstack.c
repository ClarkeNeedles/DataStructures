/*********************************************************************************************
**
**	File Name:		dstack.c
**	Description:	Contains the function definitions and assigning these functions to the
**					dynamic stack function pointers in the definition. These are all for
**					general usage of a dynamic stack.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "ds/dstack.h"
#include "algos/dstack_algorithms.h"

// Adding an item onto a dynamic stack
void pushDItem(DStack* stack, int data)
{
	Node* newNode = createNode(data);
	if (!stack->top)
	{
		stack->top = newNode;
		return;
	}

	// Update the top pointer
	newNode->next = stack->top;
	stack->top = newNode;
}

// Removing an item from a dynamic stack
int popDItem(DStack* stack)
{
	// Nothing to delete
	if (!stack->top)
	{
		return;
	}

	Node* temp = stack->top;
	stack->top = stack->top->next;

	int data = temp->data;
	free(temp);
	return data;
}

// Printing a dynamic stack
void printDStack(DStack* stack)
{
	Node* curr = stack->top;
	while (curr)
	{
		printf("%d -> ", curr->data);
		curr = curr->next;
	}

	printf("NULL\n");
}

// Initializing a dynamic stack
void initDStack(DStack* stack)
{
	stack->top = NULL;
	stack->push = pushDItem;
	stack->pop = popDItem;
	stack->search = searchDStack;
	stack->sort = mergeSortDStack;
	stack->print = printDStack;
}