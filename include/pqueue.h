/*********************************************************************************************
**
**	File Name:		pqueue.h
**	Description:	Contains the data type definition for a priority queue. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		6/18/2025
**
**********************************************************************************************/

#pragma once

#include "heap.h"

typedef HeapType QueueType;

typedef struct PQueue
{
	Heap heap; // For the priority values

	int (*dequeue)(struct PQueue* self, int* data, int* priority);
	int (*enqueue)(struct PQueue* self, int data, int priority);
	void (*print)(struct PQueue* self);
	int (*delete)(struct PQueue* self);
	int (*isEmpty)(struct PQueue* self);
} PQueue;

void initPQueue(PQueue* pqueue, int size, QueueType type);