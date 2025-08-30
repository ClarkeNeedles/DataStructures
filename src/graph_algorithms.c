/*********************************************************************************************
**
**	File Name:		graph_algorithms.c
**	Description:	Contains the function definitions for the graph algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include "ds/queue.h"
#include "ds/stack.h"
#include "ds/pqueue.h"
#include "algos/graph_algorithms.h"

// Helper to mark all vertices as unvisited
// At the start of a search algorithm
static void resetVisitState(Vertex* vertices, int numVertices)
{
	for (int i = 0; i < numVertices; ++i)
	{
		vertices[i].visited = NOT_VISITED;
	}
}

// Return whether a graph is connected or not
// Based on a starting node. Using BFS.
int graphConnected(Graph* graph, int src)
{
	resetVisitState(graph->vertices, graph->numVertices);

	// Create queue for vertex neighbors
	Queue queue;
	initQueue(&queue, graph->numVertices);

	// Enqueue the starting vertex
	queue.enqueue(&queue, src);

	int visited = 0;
	while (!queue.isEmpty(&queue))
	{
		// Dequeue current node
		int indx = queue.dequeue(&queue);

		// Check it has not been visited already
		if (graph->vertices[indx].visited == VISITED)
		{
			continue;
		}
		graph->vertices[indx].visited = VISITED;
		++visited;

		// Add all of the neighbors
		ENode* curr = graph->vertices[indx].head;
		while (curr)
		{
			queue.enqueue(&queue, curr->dest);
			curr = curr->next;
		}
	}

	return visited == graph->numVertices;
}

// Check if there exists a cycle for the given node
// Uses DFS
int graphCycle(Graph* graph, int src)
{
	resetVisitState(graph->vertices, graph->numVertices);

	// Create queue for vertex neighbors
	Queue queue;
	initQueue(&queue, graph->numVertices);

	// Enqueue the starting vertex
	queue.enqueue(&queue, src);

	while (!queue.isEmpty(&queue))
	{
		// Dequeue current node
		int indx = queue.dequeue(&queue);

		// Check it has not been visited already
		if (graph->vertices[indx].visited == VISITED)
		{
			if (indx == src)
			{
				return 1;
			}
			continue;
		}
		graph->vertices[indx].visited = VISITED;

		// Add all of the neighbors
		ENode* curr = graph->vertices[indx].head;
		while (curr)
		{
			queue.enqueue(&queue, curr->dest);
			curr = curr->next;
		}
	}

	// No cycle found
	return 0;
}

// Vertex search either using BFS or DFS
// Starting from a given vertex, graph must be connected
// in order to find the destination vertex
int searchVertex(Graph* graph, int src, int dest, SearchType type)
{
	resetVisitState(graph->vertices, graph->numVertices);

	// Depth first search algorithm on a graph
	if (type == DFS)
	{
		// Create stack for vertex neighbors
		Stack stack;
		initStack(&stack, graph->numVertices);

		// Push the starting vertex
		stack.push(&stack, src);

		while (!stack.isEmpty(&stack))
		{
			// Dequeue current node
			int indx = stack.pop(&stack);

			// Check it has not been visited already
			if (graph->vertices[indx].visited == VISITED)
			{
				continue;
			}
			graph->vertices[indx].visited = VISITED;

			// Add all of the neighbors
			ENode* curr = graph->vertices[indx].head;
			while (curr)
			{
				// Checking if the vertex exists
				if (curr->dest == dest)
				{
					stack.delete(&stack);
					return 1;
				}

				stack.push(&stack, curr->dest);
				curr = curr->next;
			}
		}

		// Vertex does not exist
		stack.delete(&stack);
		return 0;
	}
	// Breadth first search algorithm on a graph
	else
	{
		// Create queue for vertex neighbors
		Queue queue;
		initQueue(&queue, graph->numVertices);

		// Enqueue the starting vertex
		queue.enqueue(&queue, src);

		while (!queue.isEmpty(&queue))
		{
			// Dequeue current node
			int indx = queue.dequeue(&queue);

			// Check it has not been visited already
			if (graph->vertices[indx].visited == VISITED)
			{
				continue;
			}
			graph->vertices[indx].visited = VISITED;

			// Add all of the neighbors
			ENode* curr = graph->vertices[indx].head;
			while (curr)
			{
				// Checking if the vertex exists
				if (curr->dest == dest)
				{
					queue.delete(&queue);
					return 1;
				}

				queue.enqueue(&queue, curr->dest);
				curr = curr->next;
			}
		}

		// Vertex does not exist
		queue.delete(&queue);
		return 0;
	}
}

// Get the shortest path to every vertex in the graph
// Uses various algorithms
void shortestPathAlgorithm(Graph* graph, int src)
{
	// Shortest path has already been determined
	if (graph->vertices[src].distance != __INT_MAX__ &&
		graph->vertices[src].parent != -1)
	{
		return;
	}

	resetVisitState(graph->vertices, graph->numVertices);

	// Initialize priority queue
	PQueue pqueue;
	initPQueue(&pqueue, graph->numVertices, MIN);

	// Update source vertex values
	graph->vertices[src].distance = 0;
	graph->vertices[src].parent = src;

	// Enqueue source vertex
	pqueue.enqueue(&pqueue, src, graph->vertices[src].distance);
	
	while (!pqueue.isEmpty(&pqueue))
	{
		int indx, priority;
		pqueue.dequeue(&pqueue, &indx, &priority);

		ENode* curr = graph->vertices[indx].head;
		while (curr)
		{
			// Updating the distance and parent of neighbors
			// Only if the new distance is smaller
			if (curr->weight < graph->vertices[curr->dest].distance)
			{
				graph->vertices[curr->dest].distance = curr->weight;
				graph->vertices[curr->dest].parent = indx;
			}

			pqueue.enqueue(&pqueue, curr->dest, graph->vertices[curr->dest].distance);
		}
	}

	pqueue.delete(&pqueue);
}