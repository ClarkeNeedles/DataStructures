/*********************************************************************************************
**
**	File Name:		dll_node.h
**	Description:	Double node. Contains the data type definition for a node that is used in a doubly
**					linked list, and the function declaration to create one.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#pragma once

typedef struct DNode
{
	struct DNode* next;
	struct DNode* prev;
	int data;
} DNode;

DNode* createDNode(int data);