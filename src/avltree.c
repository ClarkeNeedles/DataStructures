/*********************************************************************************************
**
**	File Name:		avltree.c
**	Description:	Contains the function definitions and assigning these functions to the
**					AVL tree function pointers in the definition. These are all for
**					general usage of an AVL tree.
**
**	Author:			Clarke Needles
**	Created:		6/2/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "ds/avltree.h"
#include "algos/avl_algorithms.h"

// Helper function that updates the height of a node
static void updateHeight(AVLNode* node)
{
	// If a node does not exist, the height is 0
	int heightL = (node->left) ? node->left->height : 0;
	int heightR = (node->right) ? node->right->height : 0;

	// Take the maximum height of two child nodes
	node->height = 1 + (heightL > heightR ? heightL : heightR);
}

// Rotate a node right in a AVL tree
static AVLNode* rightRotate(AVLNode* node)
{
	//        D             C
	//       / \     R     / \
	//      C   E   -->   A   D
	//     / \               / \
	//    A   B             B   E

	AVLNode* temp = node->left;
	node->left = temp->right;
	temp->right = node;

	// Update heights
	// Update temp last as it will be on top
	updateHeight(node);
	updateHeight(temp);

	return temp;
}

// Rotate a node left in a AVL tree
static AVLNode* leftRotate(AVLNode* node)
{
	//        D             C
	//       / \     L     / \
	//      C   E   <--   A   D
	//     / \               / \
	//    A   B             B   E

	AVLNode* temp = node->right;
	node->right = temp->left;
	temp->left = node;

	// Update heights
	// Update temp last as it will be on top
	// If a node does not exist, the height is 0
	updateHeight(node);
	updateHeight(temp);

	return temp;
}

// Recursive insertion that makes the process easier
static void recurseInsertAvl(AVLNode** root, int data)
{
	// Basic BST insertion initially
	if (!(*root))
	{
		(*root) = createAVLNode(data);
		return;
	}

	if (data < (*root)->data)
	{
		recurseInsertAvl(&(*root)->left, data);
	}
	else if (data > (*root)->data)
	{
		recurseInsertAvl(&(*root)->right, data);
	}
	// No duplicate entries
	else
	{
		return;
	}

	// Get the heights of left and right nodes for later usages
	// If a node does not exist, the height is 0
	int heightL = ((*root)->left) ? (*root)->left->height : 0;
	int heightR = ((*root)->right) ? (*root)->right->height : 0;

	// Update parent height after insertion
	(*root)->height = 1 + (heightL > heightR ? heightL : heightR);

	// Get balance factor of the parent node after insertion
	int balance = heightL - heightR;

	// Rotations (4 cases)
	// Left Left
	if (balance > 1 && data < (*root)->left->data)
	{
		*root = rightRotate(*root);
	}
	// Right Right
	else if (balance < -1 && data > (*root)->right->data)
	{
		*root = leftRotate(*root);
	}
	// Left Right
	else if (balance > 1 && data > (*root)->left->data)
	{
		(*root)->left = leftRotate(&(*root)->left);
		*root = rightRotate(*root);
	}
	// Right Left
	else if (balance < -1 && data < (*root)->right->data)
	{
		(*root)->right = rightRotate(&(*root)->right);
		*root = leftRotate(*root);
	}

	return;
}

// Inserting a new node into the AVL tree
void insertAvl(AVL* avl, int data)
{
	recurseInsertAvl(&avl->root, data);
}

// Recursive deletion that makes the process easier
static void recurseDeleteAvl(AVLNode** root, int data)
{
	// Node node to delete
	if (!(*root))
	{
		return;
	}

	// Search for the node
	if (data < (*root)->data)
	{
		recurseDeleteAvl(&(*root)->left, data);
	}
	else if (data > (*root)->data)
	{
		recurseDeleteAvl(&(*root)->right, data);
	}
	else
	{
		// Node with one or no children
		if ((*root)->left == NULL || (*root)->right == NULL)
		{
			AVLNode* temp = ((*root)->left) ? (*root)->left : (*root)->right;

			// No child, free parent
			if (!temp)
			{
				temp = (*root);
				*root = NULL;
			}
			// One child, assign child to parent
			else
			{
				**root = *temp;
			}

			free(temp);
		}
		else
		{
			// Getting the next smallest/largest number depending height of children
			// The child will larger height has more children, and is more optimal
			// In the left subtree, get the largest (largest predecessor)
			// In the right subtree, get the smallest (smallest successor)
			AVLNode* temp;
			if ((*root)->left->height >= (*root)->right->height)
			{
				AVLNode* curr = (*root)->left;
				while (curr->right)
				{
					curr = curr->right;
				}

				temp = curr;

				// Update value of node
				(*root)->data = temp->data;

				recurseDeleteAvl(&(*root)->left, temp->data);
			}
			else
			{
				AVLNode* curr = (*root)->right;
				while (curr->left)
				{
					curr = curr->left;
				}

				temp = curr;

				// Update value of node
				(*root)->data = temp->data;

				recurseDeleteAvl(&(*root)->right, temp->data);
			}
		}
	}

	// Node does not need balancing, it was deleted
	if (!(*root))
	{
		return;
	}

	// Get the heights of left and right nodes for later usages
	// If a node does not exist, the height is 0
	int heightL = ((*root)->left) ? (*root)->left->height : 0;
	int heightR = ((*root)->right) ? (*root)->right->height : 0;

	// Update parent height after insertion
	(*root)->height = 1 + (heightL > heightR ? heightL : heightR);

	// Get balance factor of the parent node after insertion
	int balance = heightL - heightR;

	// Rotations (4 cases)
	// Left Left
	if (balance > 1 && data < (*root)->left->data)
	{
		*root = rightRotate(*root);
	}
	// Right Right
	else if (balance < -1 && data >(*root)->right->data)
	{
		*root = leftRotate(*root);
	}
	// Left Right
	else if (balance > 1 && data > (*root)->left->data)
	{
		(*root)->left = leftRotate(&(*root)->left);
		*root = rightRotate(*root);
	}
	// Right Left
	else if (balance < -1 && data < (*root)->right->data)
	{
		(*root)->right = rightRotate(&(*root)->right);
		*root = leftRotate(*root);
	}

	return;
}

// Deleting a node from the AVL tree
void deleteAvl(AVL* avl, int data)
{
	recurseDeleteAvl(&avl->root, data);
}

// Printing AVL tree in pre order traversal
static void printAvlPre(AVLNode* root)
{
	if (!root)
	{
		return;
	}

	printf("%d, ", root->data);
	printAvlPre(root->left);
	printAvlPre(root->right);
}

// Printing AVL tree in normal order traversal
static void printAvlIn(AVLNode* root)
{
	if (!root)
	{
		return;
	}

	printAvlIn(root->left);
	printf("%d, ", root->data);
	printAvlIn(root->right);
}

// Printing AVL tree in post order traversal
static void printAvlPost(AVLNode* root)
{
	if (!root)
	{
		return;
	}

	printAvlPost(root->left);
	printAvlPost(root->right);
	printf("%d, ", root->data);
}

// Printing AVL tree depending on order passed in
void printAvl(AVL* avl, PrintOrder order)
{
	switch (order)
	{
	case PRE:
		printAvlPre(avl->root);
		break;
	case IN:
		printAvlIn(avl->root);
		break;
	case POST:
		printAvlPost(avl->root);
		break;
	default:
		break;
	}
}

// Initialize the AVL tree
void initAvl(AVL* avl)
{
	avl->root = NULL;
	avl->insert = insertAvl;
	avl->deleteNode = deleteAvl;
	avl->search = searchAvl;
	avl->print = printAvl;
}