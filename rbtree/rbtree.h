/*********************************************************************************************
**
**	File Name:		rbtree.h
**	Description:	Contains the data type definition for a red and black tree. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		6/3/2025
**
**********************************************************************************************/

#pragma once

#include "rb_node.h"
#include "../printorder.h"

typedef struct RBT
{
	RBNode* root;

	void (*insert)(struct RBT* self, int data);
	void (*delete)(struct RBT* self, int data);
	RBNode* (*search)(struct RBT* self, int data);
	void (*print)(struct RBT* self, PrintOrder order);
} RBT;

void initRbt(RBT* rbt);