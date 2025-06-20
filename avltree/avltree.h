/*********************************************************************************************
**
**	File Name:		avltree.h
**	Description:	Contains the data type definition for an AVL tree. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		6/2/2025
**
**********************************************************************************************/

#pragma once

#include "avl_node.h"
#include "../printorder.h"

typedef struct AVL
{
	AVLNode* root;

	void (*insert)(struct AVL* self, int data);
	void (*deleteNode)(struct AVL* self, int data);
	AVLNode* (*search)(struct AVL* self, int data);
	void (*print)(struct AVL* self, PrintOrder order);
} AVL;

void initAvl(AVL* avl);