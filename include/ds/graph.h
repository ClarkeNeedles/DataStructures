/*********************************************************************************************
**
**	File Name:		graph.h
**	Description:	Contains the data type definition for a graph. Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#pragma once

#include "edge_node.h"

typedef enum VisitState
{
    NOT_VISITED,
    VISITED
} VisitState;

typedef enum DirectedFlag
{ 
    NOT_DIRECTED,
    DIRECTED
} DirectedFlag;

typedef enum DegreeDirection
{
    INCOMING,
    OUTGOING
} DegreeDirection;

typedef enum SearchType
{
    DFS,
    BFS
} SearchType;

typedef struct Vertex 
{
    ENode* head;
    int numEdges;
    int distance;
    int parent;
    unsigned char visited;
} Vertex;

typedef struct Graph 
{
    Vertex* vertices; // Adjacency list
    int numVertices;
    unsigned char directed; 
    
    void (*addEdge)(struct Graph* graph, int src, int dest, int weight);
    void (*deleteEdge)(struct Graph* graph, int src, int dest);
    void (*print)(struct Graph* graph);
    int (*edgeExists)(struct Graph* graph, int src, int dest);
    int (*isConnected)(struct Graph* graph, int src);
    int (*hasCycle)(struct Graph* graph, int src);
    int (*getDegree)(struct Graph* graph, int vertex, DegreeDirection direction);
    int (*vertexExists)(struct Graph* graph, int src, int dest, SearchType type);
    void (*shortestPath)(struct Graph* graph, int src);
} Graph;

void initGraph(Graph* graph, int numVertices, DirectedFlag isDirected);