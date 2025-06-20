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
#include "rbtree.h"
#include "rbt_algorithms.h"

// Rotate a node right in a RB tree
static void rightRotate(RBNode** root, RBNode* node)
{
	//        D             C
	//       / \     R     / \
	//      C   E   -->   A   D
	//     / \               / \
	//    A   B             B   E

	// Temp becomes C
	RBNode* temp = node->left;
	// Left node of D becomes B
	node->left = temp->right;

	if (temp->right)
	{
		// Parent of B becomes D
		temp->right->parent = node;
	}

	// Parent of C becomes parent of D
	temp->parent = node->parent;

	// If no parent, temp becomes the new root
	if (!temp->parent)
	{
		(*root) = temp;
	}
	// Assign the parent left/right node to temp
	else if (node == node->parent->left)
	{
		node->parent->left = temp;
	}
	else
	{
		node->parent->right = temp;
	}

	// Right node of C becomes D
	temp->right = node;
	// Parent of D becomes C
	node->parent = temp;
}

// Rotate a node left in a RB tree
static void leftRotate(RBNode** root, RBNode* node)
{
	//        D             C
	//       / \     L     / \
	//      C   E   <--   A   D
	//     / \               / \
	//    A   B             B   E

	// Temp becomes D
	RBNode* temp = node->right;
	// Right node of C becomes B
	node->right = temp->left;

	if (temp->left)
	{
		// Parent of B becomes C
		temp->left->parent = node;
	}

	// Parent of D becomes parent of C
	temp->parent = node->parent;

	// If no parent, temp becomes the new root
	if (!temp->parent)
	{
		(*root) = temp;
	}
	// Assign the parent left/right node to temp
	else if (node == node->parent->left)
	{
		node->parent->left = temp;
	}
	else
	{
		node->parent->right = temp;
	}

	// Left node of D becomes C
	temp->left = node;
	// Parent of C becomes D
	node->parent = temp;
}

// Fixing the red and black tree after an insertion
static void rbtInsertFixUp(RBNode** root, RBNode* node)
{
	// Continue as long as we have not reached the root
	// As well as the parent node is red, if it is black, no rules are broken
	while (node != *root && node->parent->colour == RED)
	{
		// Get uncle node
		RBNode* uncle;
		if (node->parent == node->parent->parent->left)
		{
			uncle = node->parent->parent->right;
		}
		else
		{
			uncle = node->parent->parent->left;
		}

		// Uncle node is NULL, set it to black
		char colour = (!uncle) ? BLACK : uncle->colour;

		// Uncle is red
		// Parent and uncle = BLACK
		// Grandparent = RED
		// Update node to be the grandparent
		if (colour == RED)
		{
			node->parent->colour = BLACK;
			uncle->colour = BLACK;
			node = node->parent->parent;
			node->colour = RED;
		}
		// Uncle is black
		// Four cases: LL, RR, LR, RL
		else
		{
			// LL case
			// Swap parent and grandparent colour
			// Right rotate grandparent
			if (node == node->parent->left 
				&& node->parent == node->parent->parent->left)
			{
				char temp = node->parent->colour;
				node->parent->colour = node->parent->parent->colour;
				node->parent->parent->colour = temp;
				rightRotate(root, node->parent->parent);
			}
			// RR case
			// Swap parent and grandparent colour
			// Left rotate grandparent
			else if (node == node->parent->right 
				&& node->parent == node->parent->parent->right)
			{
				char temp = node->parent->colour;
				node->parent->colour = node->parent->parent->colour;
				node->parent->parent->colour = temp;
				leftRotate(root, node->parent->parent);
			}
			// LR case
			// Swap node and grandparent colour
			// Left rotate parent
			// Right rotate grandparent
			else if (node == node->parent->right 
				&& node->parent == node->parent->parent->left)
			{
				char temp = node->colour;
				node->colour = node->parent->parent->colour;
				node->parent->parent->colour = temp;
				leftRotate(root, node->parent);
				rightRotate(root, node->parent->parent);
			}
			// RL case
			// Swap node and grandparent colour
			// Right rotate parent
			// Left rotate grandparent
			else if (node == node->parent->left
				&& node->parent == node->parent->parent->right)
			{
				char temp = node->colour;
				node->colour = node->parent->parent->colour;
				node->parent->parent->colour = temp;
				rightRotate(root, node->parent);
				leftRotate(root, node->parent->parent);
			}
		}
	}

	// Root must always be black
	(*root)->colour = BLACK;
}

// Inserting a new node into the RB tree
void insertRbt(RBT* rbt, int data)
{
	RBNode* newNode = createRBNode(data);

	// For a new tree
	if (!rbt->root)
	{
		newNode->colour = BLACK;
		rbt->root = newNode;
		return;
	}

	RBNode* parent = NULL;
	RBNode* curr = rbt->root;

	// Inserting the new node
	while (curr)
	{
		// Getting the previous (parent) value
		parent = curr;

		curr = (data < curr->data) ? curr->left : curr->right;
	}

	// Assigning the parent
	newNode->parent = parent;

	// Assigning the child
	if (data < parent->data)
	{
		parent->left = newNode;
	}
	else
	{
		parent->right = newNode;
	}

	// Fix the red and black tree
	rbtInsertFixUp(&rbt->root, newNode);
}

// Fixing the red and black tree after a deletion
static void rbtDeleteFixUp(RBNode** root, RBNode* node) {
	// Continue as long as the current node is not the root and we have a double-black issue
	while (node != *root && (node == NULL || node->colour == DBLACK)) {
		RBNode* sibling;

		// Node is a left child
		if (node->parent->left == node) 
		{
			sibling = node->parent->right;

			// Sibling is red
			// Swap colours of parent and sibling
			// Left rotate parent
			if (sibling && sibling->colour == RED) 
			{
				sibling->colour = BLACK;
				node->parent->colour = RED;
				leftRotate(root, node->parent);
				// Sibling changes after rotation
				sibling = node->parent->right;
			}

			// Sibling is black and both its children are black
			// Make sibling red
			// Move double-black up to the parent
			if ((!sibling || sibling->colour == BLACK) &&
				(!sibling->left || sibling->left->colour == BLACK) &&
				(!sibling->right || sibling->right->colour == BLACK)) 
			{
				if (sibling)
				{
					sibling->colour = RED;
				}
				node->parent->colour =
					(node->parent->colour == RED) ? BLACK : DBLACK;
				node = node->parent;  // Move double-black up
			}
			else 
			{
				// Sibling is black and one of its children is red
				// Perform rotations to balance the tree

				// Sibling's left child is red
				// Swap colours of sibling and its left child
				// Right rotate sibling
				if (sibling->left && sibling->left->colour == RED) 
				{
					sibling->left->colour = sibling->colour;
					sibling->colour = node->parent->colour;
					rightRotate(root, sibling);
					sibling = node->parent->right;  // Update sibling after rotation
				}

				// Sibling's right child is red
				// Swap colours of sibling and parent
				// Set sibling's right child to black
				// Left rotate the parent
				sibling->colour = node->parent->colour;
				node->parent->colour = BLACK;
				if (sibling->right) sibling->right->colour = BLACK;
				leftRotate(root, node->parent);

				// Fix completed, exit the loop
				node = *root;
			}
		}
		// Node is a right child
		else 
		{ 
			sibling = node->parent->left;

			// Sibling is red
			if (sibling && sibling->colour == RED) 
			{
				sibling->colour = BLACK;
				node->parent->colour = RED;
				rightRotate(root, node->parent);
				sibling = node->parent->left;
			}

			// Sibling is black and both its children are black
			if ((!sibling || sibling->colour == BLACK) &&
				(!sibling->left || sibling->left->colour == BLACK) &&
				(!sibling->right || sibling->right->colour == BLACK)) 
			{
				if (sibling)
				{
					sibling->colour = RED;
				}
				node->parent->colour =
					(node->parent->colour == RED) ? BLACK : DBLACK;
				node = node->parent;
			}
			else 
			{
				// Sibling is black and one of its children is red

				// Sibling's right child is red
				if (sibling->right && sibling->right->colour == RED) 
				{
					sibling->right->colour = sibling->colour;
					sibling->colour = node->parent->colour;
					leftRotate(root, sibling);
					sibling = node->parent->left;
				}

				// Sibling's left child is red
				sibling->colour = node->parent->colour;
				node->parent->colour = BLACK;
				if (sibling->left) sibling->left->colour = BLACK;
				rightRotate(root, node->parent);

				// Fix completed, exit the loop
				node = *root;
			}
		}
	}

	// Root is always black
	if (node) node->colour = BLACK;
}

// Deleting a node from the RB tree
void deleteRbt(RBT* rbt, int data)
{
	RBNode* curr = rbt->root;
	// Finding the node
	while (curr)
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
			break;
		}
	}

	// Empty tree / node not found
	if (!curr)
	{
		return;
	}

	// One left child
	RBNode* deleteNode = NULL;
	RBNode* replaceNode = curr;
	if (!curr->right)
	{
		deleteNode = curr->left;
	}
	// One right child
	else if (!curr->left)
	{
		deleteNode = curr->right;
	}
	// Two children
	// Find the in order predecessor (max in left subtree)
	else
	{
		replaceNode = curr->left;
		while (replaceNode->right)
		{
			replaceNode = replaceNode->right;
		}


		deleteNode = replaceNode->left ? replaceNode->left : replaceNode->right;
	}
	
	// If there are no children for the node to delete
	if (!deleteNode)
	{
		deleteNode = replaceNode;
	}

	char delColour;
	// Just update the values of the nodes, instead of swapping (faster)
	if (curr != replaceNode)
	{
		curr->data = replaceNode->data;
	}

	replaceNode->data = deleteNode->data;
	delColour = replaceNode->colour;
	replaceNode->colour = deleteNode->colour;

	// Update the parent
	if (deleteNode->parent)
	{
		if (deleteNode == deleteNode->parent->left)
		{
			deleteNode->parent->left = NULL;
		}
		else
		{
			deleteNode->parent->right = NULL;
		}
	}

	// Free the deleted node
	free(deleteNode);
	deleteNode = NULL;

	// Fix the red and black tree only if deleted node is black
	if (delColour == BLACK)
	{
		int a = 0;
		rbtDeleteFixUp(&rbt->root, replaceNode);
	}
}

// Printing RB tree in pre order traversal
static void printRbtPre(RBNode* root)
{
	if (!root)
	{
		return;
	}

	printf("%d, ", root->data);
	printRbtPre(root->left);
	printRbtPre(root->right);
}

// Printing RB tree in normal order traversal
static void printRbtIn(RBNode* root)
{
	if (!root)
	{
		return;
	}

	printRbtIn(root->left);
	printf("%d, ", root->data);
	printRbtIn(root->right);
}

// Printing RB tree in post order traversal
static void printRbtPost(RBNode* root)
{
	if (!root)
	{
		return;
	}

	printRbtPost(root->left);
	printRbtPost(root->right);
	printf("%d, ", root->data);
}

// Printing RB tree depending on order passed in
void printRbt(RBT* rbt, PrintOrder order)
{
	switch (order)
	{
	case PRE:
		printRbtPre(rbt->root);
		break;
	case IN:
		printRbtIn(rbt->root);
		break;
	case POST:
		printRbtPost(rbt->root);
		break;
	default:
		break;
	}
}

// Initialize the RBT tree
void initRbt(RBT* rbt)
{
	rbt->root = NULL;
	rbt->insert = insertRbt;
	rbt->delete = deleteRbt;
	rbt->search = searchRbt;
	rbt->print = printRbt;
}