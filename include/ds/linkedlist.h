/*********************************************************************************************
**
**	File Name:		linkedlist.h
**	Description:	Contains the data type definition for a singly linked list. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#pragma once

#include "node.h"

typedef struct LinkedList
{
	Node* head;

	void (*add)(struct LinkedList* self, int data);
	void (*deleteList)(struct LinkedList* self);
	void (*print)(struct LinkedList* self);
	void (*sort)(struct LinkedList* self);
	int (*search)(struct LinkedList* self, int data);
	int (*deleteItem)(struct LinkedList* self);
} LinkedList;

void initLinkedList(LinkedList* list);