/*********************************************************************************************
**
**	File Name:		avl_algorithms.c
**	Description:	Contains the function definitions for the avl tree algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "avl_algorithms.h"

// Searching for a value in an AVL tree
AVLNode* searchAvl(AVL* avl, int data)
{
	AVLNode* curr = avl->root;
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