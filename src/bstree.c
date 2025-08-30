/*********************************************************************************************
**
**	File Name:		bstree.c
**	Description:	Contains the function definitions and assigning these functions to the
**					binary search tree function pointers in the definition. These are all for
**					general usage of a binary search tree.
**
**	Author:			Clarke Needles
**	Created:		6/2/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "ds/bstree.h"
#include "algos/bst_algorithms.h"

// Inserting a new node into the binary search tree
void insertBst(BST* bst, int data)
{
	BSNode* newNode = createBSNode(data);
	
	// For a new tree
	if (!bst->root)
	{
		bst->root = newNode;
		return;
	}

	// Larger values go to the right
	// Smaller values go to the left
	BSNode* curr = bst->root;
	while (curr != NULL)
	{
		if (data < curr->data)
		{
			if (!curr->left)
			{
				curr->left = newNode;
				return;
			}

			curr = curr->left;
		}
		else
		{
			if (!curr->right)
			{
				curr->right = newNode;
				return;
			}

			curr = curr->right;
		}
	}
}

// Deleting a node from the binary search tree
int deleteBst(BST* bst, int data)
{
	// Empty tree
	if (!bst->root)
	{
		return -1;
	}

	// Only one node
	if (!bst->root->left && !bst->root->right && 
		data == bst->root->data)
	{
		int val = bst->root->data;
		free(bst->root);
		bst->root = NULL;
		return val;
	}

	BSNode* prev = bst->root;
	BSNode* curr = (data < bst->root->data) ?
		bst->root->left : bst->root->right;
	while (curr != NULL)
	{
		if (data < curr->data)
		{
			prev = prev->left;
			curr = curr->left;
		}
		else if (data > curr->data)
		{
			prev = prev->right;
			curr = curr->right;
		}
		else
		{
			if (curr->data < prev->data)
			{
				prev->left = curr->right;
				curr->right->left = curr->left;
			}
			else
			{
				prev->right = curr->left;
				curr->left->right = curr->right;
			}

			int val = curr->data;
			free(curr);
			return val;
		}
	}

	// The value was not found
	return -1;
}

// Printing binary search tree in pre order traversal
static void printBstPre(BSNode* root)
{
	if (!root)
	{
		return;
	}

	printf("%d, ", root->data);
	printBstPre(root->left);
	printBstPre(root->right);
}

// Printing binary search tree in normal order traversal
static void printBstIn(BSNode* root)
{
	if (!root)
	{
		return;
	}

	printBstIn(root->left);
	printf("%d, ", root->data);
	printBstIn(root->right);
}

// Printing binary search tree in post order traversal
static void printBstPost(BSNode* root)
{
	if (!root)
	{
		return;
	}

	printBstPost(root->left);
	printBstPost(root->right);
	printf("%d, ", root->data);
}

// Printing binary search tree depending on order passed in
void printBst(BST* bst, PrintOrder order)
{
	switch (order)
	{
	case PRE:
		printBstPre(bst->root);
		break;
	case IN:
		printBstIn(bst->root);
		break;
	case POST:
		printBstPost(bst->root);
		break;
	default:
		break;
	}
}

// Initialize the binary search tree
void initBst(BST* bst)
{
	bst->root = NULL;
	bst->insert = insertBst;
	bst->deleteNode = deleteBst;
	bst->search = searchBst;
	bst->print = printBst;
}