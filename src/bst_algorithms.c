/*********************************************************************************************
**
**	File Name:		bst_algorithms.c
**	Description:	Contains the function definitions for the binary search tree algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "algos/bst_algorithms.h"

// Searching for a value in a binary search tree
BSNode* searchBst(BST* bst, int data)
{
	BSNode* curr = bst->root;
	while (curr != NULL)
	{
		if (data < curr->data)
		{
			curr = curr->left;
		}
		else if (data > curr->data)
		{
			curr = curr->right;
		}
		else
		{
			return curr;
		}
	}

	// The value was not found
	return NULL;
}