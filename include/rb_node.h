/*********************************************************************************************
**
**	File Name:		rb_node.h
**	Description:	Colour tree node. Contains the data type definition for a node that is used in a tree
**					that requires two colours, and the function declaration to create one.
**
**	Author:			Clarke Needles
**	Created:		6/3/2025
**
**********************************************************************************************/

#pragma once

#define DBLACK 2
#define RED 1
#define BLACK 0

typedef struct RBNode
{
	struct RBNode* left;
	struct RBNode* right;
	struct RBNode* parent;
	int data;
	unsigned char colour; // red/black/double black
} RBNode;

RBNode* createRBNode(int data);