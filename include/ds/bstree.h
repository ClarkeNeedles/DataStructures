/*********************************************************************************************
**
**	File Name:		bstree.h
**	Description:	Contains the data type definition for a binary search tree. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		6/2/2025
**
**********************************************************************************************/

#pragma once

#include "bs_node.h"
#include "printorder.h"

typedef struct BST
{
	BSNode* root;

	void (*insert)(struct BST* self, int data);
	int (*deleteNode)(struct BST* self, int data);
	BSNode* (*search)(struct BST* self, int data);
	void (*print)(struct BST* self, PrintOrder order);
} BST;

void initBst(BST* bst);