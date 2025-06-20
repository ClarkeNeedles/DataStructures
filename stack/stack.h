/*********************************************************************************************
**
**	File Name:		stack.h
**	Description:	Contains the data type definition for a stack. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		6/9/2025
**
**********************************************************************************************/

#pragma once

typedef struct Stack
{
	int* arr;
	int size;
	int top;

	int (*push)(struct Stack* self, int data);
	void (*print)(struct Stack* self);
	int (*pop)(struct Stack* self);
	int (*search)(struct Stack* self, int data);
	void (*resize)(struct Stack* self, int size);
	int (*isEmpty)(struct Stack* self);
	int (*delete)(struct Stack* self);
	int (*peek)(struct Stack* self);
} Stack;

void initStack(Stack* stack, int size);