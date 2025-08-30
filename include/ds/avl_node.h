/*********************************************************************************************
**
**	File Name:		avl_node.h
**	Description:	Height Tree Node. Contains the data type definition for a node that is used in a tree
**					that requires the height of a node, and the function declaration to create one.
**
**	Author:			Clarke Needles
**	Created:		6/2/2025
**
**********************************************************************************************/

#pragma once

typedef struct AVLNode
{
	struct AVLNode* left;
	struct AVLNode* right;
	int data;
	int height;
} AVLNode;

AVLNode* createAVLNode(int data);