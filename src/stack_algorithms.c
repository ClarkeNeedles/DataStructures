/*********************************************************************************************
**
**	File Name:		stack_algorithms.c
**	Description:	Contains the function definitions for the stack algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/10/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "algos/stack_algorithms.h"

// Search for an item in a stack
// Returns the index
int searchStack(Stack* stack, int data)
{
	for (int i = 0; i < stack->top; ++i)
	{
		if (stack->arr[i] == data)
		{
			return i;
		}
	}

	// Not found
	return -1;
}