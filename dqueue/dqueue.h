/*********************************************************************************************
**
**	File Name:		dqueue.h
**	Description:	Contains the data type definition for a dynamic queue. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#pragma once

#include "../node.h"

typedef struct DQueue
{
	Node* front;
	Node* end;

	int (*dequeue)(struct DQueue* self);
	int (*search)(struct DQueue* self, int data);
	void (*enqueue)(struct DQueue* self, int data);
	void (*sort)(struct DQueue* self);
	void (*print)(struct DQueue* self);
} DQueue;

void initDQueue(DQueue* queue);