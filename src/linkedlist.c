/*********************************************************************************************
**
**	File Name:		linkedlist.c
**	Description:	Contains the function definitions and assigning these functions to the
**					singly linked list function pointers in the definition. These are all for
**					general usage of a singly linked list.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include "ll_algorithms.h"

// Adds a node to a linked list
void addItem(LinkedList* list, int data)
{
	Node* newNode = createNode(data);
	// For a new list
	if (!list->head)
	{
		list->head = newNode;
		return;
	}

	Node* curr = list->head;
	while (curr->next)
	{
		curr = curr->next;
	}
	
	curr->next = newNode;
}

// Deletes a node from a linked list
int deleteItem(LinkedList* list)
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

	Node* curr = list->head->next;
	Node* prev = list->head;
	while (curr->next)
	{
		curr = curr->next;
		prev = prev->next;
	}

	int data = curr->data;
	free(curr);
	prev->next = NULL;
	return data;
}

// Deletes the entire linked list and the head
void deleteList(LinkedList* list)
{
	while (list->head)
	{
		deleteItem(list);
	}
}

// Prints a linked list
void printList(LinkedList* list)
{
	Node* curr = list->head;
	while (curr)
	{
		printf("%d -> ", curr->data);
		curr = curr->next;
	}

	printf("NULL\n");
}

void initLinkedList(LinkedList* list)
{
	list->head = NULL;
	list->add = addItem;
	list->deleteItem = deleteItem;
	list->deleteList = deleteList;
	list->print = printList;
	list->search = searchList;
	list->sort = mergeSortList;
}