/*********************************************************************************************
**
**	File Name:		avl_node.c
**	Description:	Contains the function definition for creating a Node for a tree that
**					needs to keep track of a node height. AVL trees.
**
**	Author:			Clarke Needles
**	Created:		6/2/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "avl_node.h"

AVLNode* createAVLNode(int data)
{
	// Allocate memory
	AVLNode* root = (AVLNode*)malloc(sizeof(AVLNode));

	if (!root)
	{
		return NULL;
	}

	root->data = data;
	root->left = NULL;
	root->right = NULL;
	root->height = 1;

	return root;
}