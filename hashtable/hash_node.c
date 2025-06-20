/*********************************************************************************************
**
**	File Name:		hash_node.c
**	Description:	Contains the function definition for creating a Node for a hash table
**					that uses seperate chaining.
**
**	Author:			Clarke Needles
**	Created:		5/28/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "hash_node.h"

HNode* createHNode(const char* key, int data)
{
	// Allocate memory
	HNode* head = (HNode*)malloc(sizeof(HNode));

	if (!head)
	{
		return NULL;
	}

	// Copying key
	size_t len = strlen(key) + 1;
	head->key = (char*)malloc(len);
	if (head->key)
	{
		memcpy(head->key, key, len);
	}

	head->data = data;
	head->next = NULL;

	return head;
}