/*********************************************************************************************
**
**	File Name:		dlinkedlist.c
**	Description:	Contains the function definitions and assigning these functions to the
**					doubly linked list function pointers in the definition. These are all for
**					general usage of a doubly linked list.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "dlinkedlist.h"
#include "dll_algorithms.h"

// Adds a node to a doubly linked list at a location
void addDItemAt(DLinkedList* list, int data, int index)
{
	DNode* newNode = createDNode(data);
	// For a new list
	if (!list->head)
	{
		list->head = newNode;
		return;
	}

	DNode* curr = list->head;
	int i = 0;
	// Index - 1 so that it is inserted "behind" curr
	// But it takes the proper index in the list
	while (i < index-1 && i >= 0) 
	{
		if (!curr->next)
		{
			break;
		}

		curr = curr->next;
		++i;
	}

	// Inserting at the front
	if (curr->prev == NULL)
	{
		newNode->next = curr;
		curr->prev = newNode;
		list->head = newNode;
		return;
	}

	DNode* temp = curr->next;
	curr->next = newNode;
	newNode->prev = curr;

	if (temp)
	{
		temp->prev = newNode;
		newNode->next = temp;
	}
}

// Adds a node to a doubly linked list at the end
void addDItem(DLinkedList* list, int data)
{
	DNode* newNode = createDNode(data);
	// For a new list
	if (!list->head)
	{
		list->head = newNode;
		return;
	}

	DNode* curr = list->head;
	while (curr->next)
	{
		curr = curr->next;
	}

	curr->next = newNode;
	newNode->prev = curr;
}

// Deletes an item from a doubly linked list
int deleteDItem(DLinkedList* list)
{
	// Empty, nothing to delete
	if (!list->head)
	{
		return -1;
	}

	// Only one node
	if (!list->head->next)
	{
		int data = list->head->data;
		free(list->head);
		list->head = NULL;
		return data;
	}

	DNode* curr = list->head->next;
	while (curr->next)
	{
		curr = curr->next;
	}

	int data = curr->data;
	curr->prev->next = NULL;
	free(curr);
	return data;
}

// Deletes an item from a doubly linked list
int deleteDItemAt(DLinkedList* list, int index)
{
	// Empty, nothing to delete
	if (!list->head)
	{
		return -1;
	}

	// Only one node
	if (!list->head->next)
	{
		int data = list->head->data;
		free(list->head);
		list->head = NULL;
		return data;
	}

	DNode* curr = list->head;
	int i = 0;
	while (i < index && i >= 0)
	{
		if (!curr->next)
		{
			break;
		}

		curr = curr->next;
		++i;
	}

	int data = curr->data;
	// Deleting at the front
	if (curr->prev == NULL)
	{
		curr->next->prev = NULL;
		curr->prev = NULL;
		list->head = curr->next;
	}
	// Deleting at the end
	else if (curr->next == NULL)
	{
		curr->prev->next = NULL;
	}
	// Linking to two adjacent nodes
	else 
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
	}

	free(curr);
	return data;
}

// Deletes the entire linked list and the head
void deleteDList(DLinkedList* list)
{
	while (list->head)
	{
		deleteDItem(list);
	}
}

// Prints a doubly linked list
void printDList(DLinkedList* list)
{
	DNode* curr = list->head;
	while (curr)
	{
		printf("%d -> ", curr->data);
		curr = curr->next;
	}

	printf("NULL\n");
}

void initDLinkedList(DLinkedList* dll)
{
	dll->head = NULL;
	dll->add = addDItem;
	dll->addAt = addDItemAt;
	dll->print = printDList;
	dll->deleteItem = deleteDItem;
	dll->deleteItemAt = deleteDItemAt;
	dll->deleteList = deleteDList;
	dll->search = searchDList;
	dll->sort = mergeSortDList;
}