/*********************************************************************************************
**
**	File Name:		dll_node.c
**	Description:	Contains the function definition for creating a Node for a doubly linked list.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "dll_node.h"

DNode* createDNode(int data)
{
	// Allocate memory
	DNode* head = (DNode*)malloc(sizeof(DNode));

	if (!head)
	{
		return NULL;
	}

	head->data = data;
	head->next = NULL;
	head->prev = NULL;

	return head;
}