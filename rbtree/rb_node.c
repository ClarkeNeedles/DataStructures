/*********************************************************************************************
**
**	File Name:		rb_node.c
**	Description:	Contains the function definition for creating a Node for a tree that
**					needs to keep track of a node colour. Red and black trees.
**
**	Author:			Clarke Needles
**	Created:		6/3/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "rb_node.h"

RBNode* createRBNode(int data)
{
	// Allocate memory
	RBNode* root = (RBNode*)malloc(sizeof(RBNode));

	if (!root)
	{
		return NULL;
	}

	root->data = data;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	// New RB nodes are red
	root->colour = RED;

	return root;
}