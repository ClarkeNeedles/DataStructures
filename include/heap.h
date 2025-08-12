/*********************************************************************************************
**
**	File Name:		heap.h
**	Description:	Contains the data type definition for a heap. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		5/28/2025
**
**********************************************************************************************/

#pragma once

// For a min heap or a max heap
typedef enum HeapType
{
	MIN,
	MAX
} HeapType;

typedef struct HeapNode
{
	int data;
	int priority; // For priority queue implementation
} HeapNode;

typedef struct Heap
{
	int size;
	int count;
	HeapNode* root;
	HeapType type;

	void (*insert)(struct Heap* self, int data, int priority);
	void (*print)(struct Heap* self);
	void (*printTree)(struct Heap* self);
	void (*resize)(struct Heap* self, int size);
	int (*removeRoot)(struct Heap* self, int* data, int* priority);
	int (*delete)(struct Heap* self);
} Heap;

void initHeap(Heap* heap, int size, HeapType type);

