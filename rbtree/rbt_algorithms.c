/*********************************************************************************************
**
**	File Name:		rbt_algorithms.c
**	Description:	Contains the function definitions for the red and black tree algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "rbt_algorithms.h"

// Searching for a value in a RB tree
RBNode* searchRbt(RBT* rbt, int data)
{
	RBNode* curr = rbt->root;
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