/*********************************************************************************************
**
**	File Name:		bs_node.h
**	Description:	Tree node. Contains the data type definition for a node that is used in a tree, 
**					and the function declaration to create one.
**
**	Author:			Clarke Needles
**	Created:		5/28/2025
**
**********************************************************************************************/

#pragma once

typedef struct BSNode
{
	struct BSNode* left;
	struct BSNode* right;
	int data;
} BSNode;

BSNode* createBSNode(int data);