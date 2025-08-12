/*********************************************************************************************
**
**	File Name:		node.c
**	Description:	Contains the function definition for creating a Node.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "node.h"

Node* createNode(int data)
{
	// Allocate memory
	Node* head = (Node*)malloc(sizeof(Node));

	if (!head)
	{
		return NULL;
	}

	head->data = data;
	head->next = NULL;

	return head;
}