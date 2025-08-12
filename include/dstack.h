/*********************************************************************************************
**
**	File Name:		dstack.h
**	Description:	Contains the data type definition for a dynamic stack. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#pragma once

#include "node.h"

typedef struct DStack
{
	Node* top;

	void (*push)(struct DStack* self, int data);
	void (*sort)(struct DStack* self);
	void (*print)(struct DStack* self);
	int (*pop)(struct DStack* self);
	int (*search)(struct DStack* self, int data);
} DStack;

void initDStack(DStack* stack);