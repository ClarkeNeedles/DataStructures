/*********************************************************************************************
**
**	File Name:		bs_node.c
**	Description:	Contains the function definition for creating a Node for a tree.
**
**	Author:			Clarke Needles
**	Created:		5/28/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "bs_node.h"

BSNode* createBSNode(int data)
{
	// Allocate memory
	BSNode* root = (BSNode*)malloc(sizeof(BSNode));

	if (!root)
	{
		return NULL;
	}

	root->data = data;
	root->left = NULL;
	root->right = NULL;

	return root;
}