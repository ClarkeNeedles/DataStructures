/*********************************************************************************************
**
**	File Name:		edge_node.h
**	Description:	Edge node. Contains the data type definition for a node that is used in a
**					graph, and the function declaration to create one.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#pragma once

typedef struct ENode 
{
    int dest;
    int weight;
    struct ENode* next;
} ENode;

ENode* createENode(int dest, int weight);
