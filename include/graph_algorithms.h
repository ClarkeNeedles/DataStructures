/*********************************************************************************************
**
**	File Name:		graph_algorithms.h
**	Description:	Contains the function declarations for the graph algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#pragma once

#include "graph.h"

int graphConnected(Graph* graph, int src);

int graphCycle(Graph* graph, int src);

int searchVertex(Graph* graph, int src, int dest, SearchType type);

void shortestPathAlgorithm(Graph* graph, int src);