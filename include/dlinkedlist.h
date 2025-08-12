/*********************************************************************************************
**
**	File Name:		dlinkedlist.h
**	Description:	Contains the data type definition for a doubly linked list. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#pragma once

#include "dll_node.h"

typedef struct DLinkedList
{
	DNode* head;

	void (*addAt)(struct DLinkedList* self, int data, int index);
	void (*add)(struct DLinkedList* self, int data);
	void (*deleteList)(struct DLinkedList* self);
	void (*print)(struct DLinkedList* self);
	void (*sort)(struct DLinkedList* self);
	int (*search)(struct DLinkedList* self, int data);
	int (*deleteItem)(struct DLinkedList* self);
	int (*deleteItemAt)(struct DLinkedList* self, int index);
} DLinkedList;

void initDLinkedList(DLinkedList* list);