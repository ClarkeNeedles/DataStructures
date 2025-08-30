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
#include "ds/graph.h"
#include "algos/graph_algorithms.h"

// Helper function for addGraphEdge that adds an edge at a given vertex index
static void newEdge(ENode** edge, int dest, int weight)
{
	ENode* newNode = createENode(dest, weight);
	// Creating a new list if v1 index is empty
	if (!(*edge))
	{
		*edge = newNode;
	}
	else
	{
		// Add at the front of list; faster
		newNode->next = *edge;
		*edge = newNode;
	}
}

// Add an edge between two vertices with a weight
// Does not check for duplicates
void addGraphEdge(Graph* graph, int src, int dest, int weight)
{
	// Must use vertices that exist
	if (src >= graph->numVertices || src < 0 ||
		dest >= graph->numVertices || dest < 0)
	{
		return;
	}

	// Add one edge to the directed graph
	newEdge(&graph->vertices[src].head, dest, weight);

	if (!graph->directed)
	{
		// Add both edges to the undirected graph
		newEdge(&graph->vertices[dest].head, src, weight);
	}
}

// Helper function for deleteGraphEdge that deletes an edge at a given vertex index
static void removeEdge(ENode** node, int dest)
{
	// For a single edge node
	if ((*node)->dest == dest)
	{
		*node = NULL;
		return;
	}

	ENode* prev = *node;
	ENode* curr = (*node)->next;
	while (curr)
	{
		if (curr->dest == dest)
		{
			prev->next = curr->next;
			free(curr);
			curr = NULL;
			return;
		}

		prev = prev->next;
		curr = curr->next;
	}
}

// Delete an edge between two vertices
void deleteGraphEdge(Graph* graph, int src, int dest)
{
	// Must use vertices that exist
	if (src >= graph->numVertices || src < 0 ||
		dest >= graph->numVertices || dest < 0)
	{
		return;
	}

	// Remove one edge from the directed graph
	removeEdge(&graph->vertices[src], dest);

	if (!graph->directed)
	{
		// Remove both edges from the undirected graph
		removeEdge(&graph->vertices[dest], src);
	}
}

// Print the connections in a graph
// Works for directed or undirected
void printGraph(Graph* graph)
{
	printf("%sirected Graph.\n", (graph->directed) ? "D" : "Und");

	for (int i = 0; i < graph->numVertices; ++i)
	{
		// Skip the null vertices
		if (!graph->vertices[i].head)
		{
			continue;
		}

		printf("Vertex %d: ", i);

		ENode* curr = graph->vertices[i].head;
		int a = 0;
		while (curr)
		{
			printf("%d, ", curr->dest);

			curr = curr->next;
		}
		printf("\n");
	}
}

// Check if a graph edge exists or not
int graphEdgeExists(Graph* graph, int src, int dest)
{
	ENode* curr = graph->vertices[src].head;
	while (curr)
	{
		if (curr->dest == dest)
		{
			return 1;
		}

		curr = curr->next;
	}

	return 0;
}

// Get the in or out degree for a given vertex
int vertexDegree(Graph* graph, int vertex, DegreeDirection direction)
{
	int degree = 0;
	if (direction == INCOMING)
	{
		for (int i = 0; i < graph->numVertices; ++i)
		{
			if (i == vertex)
			{
				continue;
			}

			ENode* curr = graph->vertices[i].head;
			while (curr)
			{
				if (curr->dest == vertex)
				{
					++degree;
				}
		
				curr = curr->next;
			}
		}
	}
	else
	{
		ENode* curr = graph->vertices[vertex].head;
		while (curr)
		{
			++degree;
			curr = curr->next;
		}
	}

	return degree;
}

// Initialize all the values for a new graph
void initGraph(Graph* graph, int numVertices, DirectedFlag isDirected)
{
	Vertex* vertices = (Vertex*)malloc(sizeof(Vertex) * numVertices);
	if (!vertices)
	{
		return;
	}

	// Initialize all vertex members to their default values
	for (int i = 0; i < numVertices; ++i)
	{
		vertices[i].head = NULL;
		vertices[i].numEdges = 0;
		vertices[i].distance = __INT_MAX__;
		vertices[i].parent = -1;
		vertices[i].visited = NOT_VISITED;
	}

	// Initialize all graph members to their default values
	graph->vertices = vertices;
	graph->numVertices = numVertices;
	graph->directed = isDirected;
	graph->addEdge = addGraphEdge;
	graph->deleteEdge = deleteGraphEdge;
	graph->print = printGraph;
	graph->edgeExists = graphEdgeExists;
	graph->isConnected = graphConnected;
	graph->hasCycle = graphCycle;
	graph->getDegree = vertexDegree;
	graph->vertexExists = searchVertex;
	graph->shortestPath = shortestPathAlgorithm;
}