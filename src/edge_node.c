/*********************************************************************************************
**
**	File Name:		edge_node.c
**	Description:	Contains the function definition for creating a Node for a graph.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "ds/edge_node.h"

ENode* createENode(int dest, int weight)
{
	ENode* node = (ENode*)malloc(sizeof(ENode));
	if (!node)
	{
		return NULL;
	}

	node->dest = dest;
	node->weight = weight;
	node->next = NULL;

	return node;
}