/*********************************************************************************************
**
**	File Name:		node.h
**	Description:	Basic node. Contains the data type definition for a Node, and the function declaration 
**					to create one.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#pragma once

typedef struct Node
{
	struct Node* next;
	int data;
} Node;

Node* createNode(int data);