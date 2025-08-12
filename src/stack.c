/*********************************************************************************************
**
**	File Name:		stack.c
**	Description:	Contains the function definitions and assigning these functions to the
**					stack function pointers in the definition. These are all for
**					general usage of a stack.
**
**	Author:			Clarke Needles
**	Created:		6/9/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "stack_algorithms.h"

// Resize the stack in memory
void resizeStack(Stack* stack, int size)
{
	int* temp = realloc(stack->arr, sizeof(int) * size);
	if (!temp)
	{
		return;
	}

	// Updating stack attributes
	stack->arr = temp;
	stack->size = size;

	if (size < stack->top)
	{
		stack->top = size;
	}
}

// Adding an item onto a stack
int pushItem(Stack* stack, int data)
{
	// If the stack is full
	if (stack->top == stack->size)
	{
		return -1;
	}

	stack->arr[stack->top++] = data;
}

// Removing an item from a stack
int popItem(Stack* stack)
{
	// If the stack is empty
	if (!stack->top)
	{
		return -1;
	}

	--stack->top;

	// Return removed item
	return stack->arr[stack->top];
}

// Printing a stack
void printStack(Stack* stack)
{
	for (int i = 0; i < stack->top; ++i)
	{
		printf("%d, ", stack->arr[i]);
	}
}

// Check if the stack is empty
int isStackEmpty(Stack* stack)
{
	return !stack->top;
}

// Delete the heap memory the stack was using
int deleteStack(Stack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	// Free the array
	if (stack->arr)
	{
		free(stack->arr);
		stack->arr = NULL;
	}

	// Successfull deletion
	return 0;
}

// Peek the top element of the stack
int peek(Stack* stack)
{
	return stack->arr[stack->top - 1];
}

// Initializing a stack
void initStack(Stack* stack, int size)
{
	// Allocate space for the stack array
	stack->arr = (int*)malloc(sizeof(int) * size);
	if (!stack->arr)
	{
		return;
	}

	stack->size = size;
	stack->top = 0;
	stack->pop = popItem;
	stack->push = pushItem;
	stack->print = printStack;
	stack->resize = resizeStack;
	stack->search = searchStack;
	stack->isEmpty = isStackEmpty;
	stack->delete = deleteStack;
}