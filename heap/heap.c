/*********************************************************************************************
**
**	File Name:		hashtable.c
**	Description:	Contains the function definitions and assigning these functions to the
**					hash table function pointers in the definition. These are all for
**					general usage of a hash table that uses seperate chaining.
**
**	Author:			Clarke Needles
**	Created:		5/28/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"

// Resize the heap in memory
void resizeHeap(Heap* heap, int size)
{
	int* temp = realloc(heap->root, sizeof(int) * size);
	if (!temp)
	{
		free(heap->root);
		heap->root = NULL;
		return;
	}

	// Updating heap attributes
	heap->root = temp;
	heap->size = size;

	if (size < heap->count)
	{
		heap->count = size;
	}
}

// Bubble function for min heap and max heap insertion
static void bubbleUp(HeapNode* root, int index, HeapType type)
{
	while (index > 0)
	{
		int parent = (index - 1) / 2;

		if (type == MIN)
		{
			// If the child node is smaller than the parent, swap
			if (root[index].priority < root[parent].priority)
			{
				// Swap the nodes
				HeapNode temp = root[index];
				root[index] = root[parent];
				root[parent] = temp;

				// Check if item bubbles up
				index = parent;
			}
			// Min heap is satisfied
			else
			{
				break;
			}
		}
		else
		{
			// If the child node is greater than the parent, swap
			if (root[index].priority > root[parent].priority)
			{
				// Swap the nodes
				HeapNode temp = root[index];
				root[index] = root[parent];
				root[parent] = temp;

				// Check if item bubbles up
				index = parent;
			}
			// Max heap is satisfied
			else
			{
				break;
			}
		}
	}
}

// Insert a new data into the heap with a priority
void insertHeap(Heap* heap, int data, int priority)
{
	// Cannot add to a full heap
	if (heap->count == heap->size - 1)
	{
		return;
	}

	heap->root[heap->count].data = data;
	heap->root[heap->count].priority = priority;

	bubbleUp(heap->root, heap->count++, heap->type);
}

// Bubble function for min heap and max heap deletion
static void bubbleDown(HeapNode* root, int count, HeapType type)
{
	int index = 0;
	while (index * 2 + 1 < count)
	{
		int leftChild = index * 2 + 1;
		if (type == MIN)
		{
			// If parent is greater than either child
			// swap with the smaller child
			if (root[index].priority > root[leftChild].priority ||
				root[index].priority > root[leftChild + 1].priority)
			{
				// Swap
				HeapNode temp = root[index];
				if (root[leftChild].priority < root[leftChild + 1].priority)
				{
					root[index] = root[leftChild];
					root[leftChild] = temp;
					index = leftChild;
				}
				else
				{
					root[index] = root[leftChild + 1];
					root[leftChild + 1] = temp;
					index = leftChild + 1;
				}
			}
			// Min heap is satisfied
			else
			{
				break;
			}
		}
		else
		{
			// If parent is less than either child
			// swap with the larger child
			if (root[index].priority < root[leftChild].priority ||
				root[index].priority < root[leftChild + 1].priority)
			{
				// Swap
				HeapNode temp = root[index];
				if (root[leftChild].priority > root[leftChild + 1].priority)
				{
					root[index] = root[leftChild];
					root[leftChild] = temp;
					index = leftChild;
				}
				else
				{
					root[index] = root[leftChild + 1];
					root[leftChild + 1] = temp;
					index = leftChild + 1;
				}
			}
			// Max heap is satisfied
			else
			{
				break;
			}
		}
	}
}

// Remove the root element from the heap
int removeHeapRoot(Heap* heap, int* data, int* priority)
{
	// Empty heap
	if (!heap->root)
	{
		return -1;
	}

	*data = heap->root[0].data;
	*priority = heap->root[0].priority;

	heap->root[0] = heap->root[--heap->count];

	bubbleDown(heap->root, heap->count, heap->type);

	return 0;
}

// Print the heap contents as a tree
// Only meant for numbers up to three digits
void printHeapTree(Heap* heap)
{
	// Calculating the spacing for printing tree
	int spaces = 0;
	int spacing = 1;
	if (heap->count != 1)
	{
		int pow = 1, total = 1;
		while (heap->count > total)
		{
			pow *= 2;
			total += pow;
			spacing *= 2;
			spaces += spacing;
		}
	}

	int start = 0;
	int levelSize = 1;

	// String for printing whitespace
	char* spaceStrBefore = (char*)malloc(sizeof(char) * spaces + 1);
	if (!spaceStrBefore)
	{
		return;
	}
	memset(spaceStrBefore, ' ', spaces);
	// Make sure to null terminate string
	spaceStrBefore[spaces] = '\0';

	// Capturing the last amount of whitespace printed
	char* prevSpaceStr = (char*)malloc(sizeof(char) * spaces + 1);
	if (!prevSpaceStr)
	{
		return;
	}

	while (start < heap->count)
	{
		printf("%s", spaceStrBefore);

		// Print the data
		for (int i = 0; i < levelSize; ++i)
		{
			if (start + i < heap->count)
			{
				// For chaning the spacing based on number length
				int size;
				int currVal = heap->root[start + i].data;
				if (currVal / 100 > 0 && currVal / 100 < 10)
				{
					size = strlen(prevSpaceStr) - 2;
				}
				else if (currVal / 10 > 0 && currVal / 10 < 10)
				{
					size = strlen(prevSpaceStr) - 1;
				}
				else
				{
					size = strlen(prevSpaceStr);
				}

				// Print a number with the offset
				printf("%d%.*s%c", currVal, size, start ? prevSpaceStr : "", ' ');
			}
		}
		
		// Printing white space, 1 less than before
		printf("\n%.*s", spaces - 1, spaceStrBefore);

		if (spaces > 0)
		{
			// Print the tree legs
			for (int i = 0; i < levelSize; ++i)
			{
				printf("/ \\%.*s", (spaces + spacing * 2) - 1, start ? prevSpaceStr : "");
			}
			printf("\n");
		}

		// Special alignment requirement
		spaces -= spacing;
		spacing /= 2;

		// Saving the last spaceStrBefore value
		prevSpaceStr = spaceStrBefore;

		// Updating the spaceStrBefore value
		char* temp = realloc(spaceStrBefore, spaces + 1 * sizeof(char));
		if (!temp)
		{
			return;
		}
		spaceStrBefore = temp;
		spaceStrBefore[spaces] = '\0';

		// Go to next tree level
		start += levelSize;
		levelSize *= 2;
	}

	free(prevSpaceStr);
	free(spaceStrBefore);
}

// Print the heap contents normally, no special tree format
void printHeap(Heap* heap)
{
	int start = 0;
	int levelSize = 1;

	while (start < heap->count)
	{
		// Print the data
		for (int i = 0; i < levelSize; ++i)
		{
			if (start + i < heap->count)
			{
				printf("%d ", heap->root[start + i].data);
			}
		}
		printf("\n");

		// Go to next tree level
		start += levelSize;
		levelSize *= 2;
	}
}

// Delete the heap
int deleteHeap(Heap* heap)
{
	if (!heap)
	{
		return -1;
	}

	// Free the heap
	if (heap->root)
	{
		free(heap->root);
		heap->root = NULL;
	}

	// Successfull deletion
	return 0;
}

// Initialize the hash table
void initHeap(Heap* heap, int size, HeapType type)
{
	// Allocate space for the heap array
	heap->root = (HeapNode*)malloc(sizeof(HeapNode)*size);
	if (!heap->root)
	{
		return;
	}

	heap->size = size;
	heap->count = 0;
	heap->type = type;
	heap->insert = insertHeap;
	heap->print = printHeap;
	heap->printTree = printHeapTree;
	heap->resize = resizeHeap;
	heap->removeRoot = removeHeapRoot;
}