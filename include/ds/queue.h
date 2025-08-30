/*********************************************************************************************
**
**	File Name:		queue.h
**	Description:	Contains the data type definition for a queue. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		6/6/2025
**
**********************************************************************************************/

#pragma once

typedef struct Queue
{
	int* arr;
	int size;
	int count;
	int head;
	int tail;

	int (*dequeue)(struct Queue* self);
	int (*search)(struct Queue* self, int data);
	int (*enqueue)(struct Queue* self, int data);
	void (*print)(struct Queue* self);
	void (*resize)(struct Queue* self, int size);
	int (*isEmpty)(struct Queue* self);
	int (*delete)(struct Queue* self);
} Queue;

void initQueue(Queue* queue, int size);
