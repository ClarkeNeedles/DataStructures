/*********************************************************************************************
**
**	File Name:		hash_node.h
**	Description:	Hash node. Contains the data type definition for a node that is used in a
**					hash table with seperate chaining, and the function declaration to create one.
**
**	Author:			Clarke Needles
**	Created:		5/28/2025
**
**********************************************************************************************/

#pragma once

typedef struct HNode
{
	char* key;
	struct HNode* next;
	int data;
} HNode;

HNode* createHNode(const char* key, int data);