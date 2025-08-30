/*********************************************************************************************
**
**	File Name:		main.c
**	Description:	This is the main file that demonstrates how the data structures
**					can be used.
**
**	Author:			Clarke Needles
**	Created:		5/27/2025
**
**********************************************************************************************/

#include <stdio.h>
#include "linkedlist.h"
#include "queue.h"
#include "dqueue.h"
#include "pqueue.h"
#include "stack.h"
#include "dstack.h"
#include "dlinkedlist.h"
#include "hashtable.h"
#include "heap.h"
#include "bstree.h"
#include "avltree.h"
#include "rbtree.h"
#include "graph.h"

void testSLL()
{
	LinkedList list;
	initLinkedList(&list);

	list.add(&list, 1);
	list.add(&list, 4);
	list.add(&list, 2);
	list.add(&list, 3);
	list.add(&list, 10);
	list.add(&list, 6);
	list.add(&list, 5);

	list.print(&list);

	printf("%d\n", list.deleteItem(&list));

	list.print(&list);

	list.sort(&list);

	list.print(&list);

	printf("%d\n", list.search(&list, 4));

	list.deleteList(&list);

	list.print(&list);

	return 0;
}

void testDQ()
{
	DQueue queue;
	initDQueue(&queue);

	queue.enqueue(&queue, 4);
	queue.print(&queue);

	queue.enqueue(&queue, 3);
	queue.print(&queue);

	queue.enqueue(&queue, 2);
	queue.print(&queue);

	printf("%d\n", queue.dequeue(&queue));
	queue.print(&queue);

	queue.enqueue(&queue, 1);
	queue.print(&queue);

	printf("%d\n", queue.search(&queue, 1));

	queue.sort(&queue);
	queue.print(&queue);
}

void testQ() 
{
	Queue queue;
	initQueue(&queue, 10);

	printf("Allocating queue with numbers.\n");
	for (int i = 0; i < 10; ++i)
	{
		queue.enqueue(&queue, i);
	}

	queue.print(&queue);
	printf("\n");

	printf("Dequeue first 5 numbers.\n");
	for (int i = 0; i < 5; ++i)
	{
		queue.dequeue(&queue);
	}

	queue.print(&queue);
	printf("\n");

	int num = 1;
	printf("%d was found at index %d.\n", num, queue.search(&queue, num));

	printf("Add %d back to the queue.\n", num);
	queue.enqueue(&queue, num);

	printf("%d was found at index %d.\n", num, queue.search(&queue, num));

	printf("Resize the queue.\n");
	queue.resize(&queue, 7);

	printf("Add 2 back to the queue.\n");
	queue.enqueue(&queue, 2);

	queue.print(&queue);
	printf("\n");

	printf("Delete the queue\n");
	printf("Queue was%s deleted successfully\n", !queue.delete(&queue) ? "" : " not");
}

void testPQ()
{
	PQueue pqueue;
	initPQueue(&pqueue, 10, MIN);

	printf("Enqueueing items\n");
	pqueue.enqueue(&pqueue, 0, 3);
	pqueue.enqueue(&pqueue, 1, 5);
	pqueue.enqueue(&pqueue, 2, 1);
	pqueue.enqueue(&pqueue, 3, 4);
	pqueue.enqueue(&pqueue, 4, 2);

	printf("Printing the priority queue\n");
	pqueue.print(&pqueue);
	printf("\n");

	int num = 2;
	printf("Dequeueing %d items\n", num);
	for (int i = 0; i < num; ++i)
	{
		int data, priority;
		pqueue.dequeue(&pqueue, &data, &priority);

		printf("Dequeued: Data %d, Priority %d\n", data, priority);
	}

	printf("Printing the priority queue\n");
	pqueue.print(&pqueue);
	printf("\n");
}

void testDS()
{
	DStack stack;
	initDStack(&stack);

	stack.push(&stack, 1);
	stack.print(&stack);

	stack.push(&stack, 2);
	stack.print(&stack);

	stack.push(&stack, 3);
	stack.print(&stack);

	printf("%d\n", stack.pop(&stack));
	stack.print(&stack);

	stack.push(&stack, 4);
	stack.print(&stack);

	printf("%d\n", stack.search(&stack, 1));

	stack.sort(&stack);
	stack.print(&stack);
}

void testS() 
{
	Stack stack;
	initStack(&stack, 10);

	printf("Adding 10 elements to the stack.\n");
	for (int i = 0; i < 10; ++i)
	{
		stack.push(&stack, i);
	}
	
	printf("Printing the stack.\n");
	stack.print(&stack);
	printf("\n");

	printf("Removing 5 elements from the stack.\n");
	for (int i = 0; i < 5; ++i)
	{
		stack.pop(&stack);
	}

	printf("Printing the stack.\n");
	stack.print(&stack);
	printf("\n");

	int num = 4;
	printf("%d was found at index %d.\n", num, stack.search(&stack, num));

	printf("Removing %d from the stack.\n", num);
	stack.pop(&stack);

	printf("%d was found at index %d.\n", num, stack.search(&stack, num));

	printf("Resize the stack.\n");
	stack.resize(&stack, 4);

	printf("Printing the stack.\n");
	stack.print(&stack);
	printf("\n");

	printf("Try and add to a full stack.\n");
	stack.push(&stack, 4);

	printf("Printing the stack.\n");
	stack.print(&stack);
	printf("\n");

	printf("Delete the stack\n");
	printf("Stack was%s deleted successfully\n", !stack.delete(&stack) ? "" : " not");
}

void testDLL()
{
	DLinkedList list;
	initDLinkedList(&list);

	list.add(&list, 1);
	list.add(&list, 2);
	list.add(&list, 3);

	list.print(&list);

	list.addAt(&list, 4, 0);

	list.print(&list);

	list.addAt(&list, 5, 10);

	list.print(&list);

	printf("%d\n", list.deleteItem(&list));

	list.print(&list);

	printf("%d\n", list.deleteItemAt(&list, 1));

	list.print(&list);

	printf("%d\n", list.search(&list, 2));

	list.sort(&list);

	list.print(&list);

	list.deleteList(&list);

	list.print(&list);
}

void testHT()
{
	HashTable hashTable;
	initHashTable(&hashTable, 10);

	hashTable.insert(&hashTable, "alpha", 5);
	hashTable.insert(&hashTable, "beta", 6);
	hashTable.insert(&hashTable, "charlie", 8);

	hashTable.print(&hashTable);
	printf("\n");

	hashTable.expand(&hashTable);

	hashTable.insert(&hashTable, "delta", 1);
	hashTable.insert(&hashTable, "epsilon", 3);

	hashTable.print(&hashTable);

	printf("%d\n", hashTable.search(&hashTable, "beta"));

	printf("%d\n", hashTable.deleteItem(&hashTable, "beta"));

	printf("%d\n", hashTable.search(&hashTable, "beta"));
}

void testH()
{
	Heap heap;
	initHeap(&heap, 15, MIN);

	printf("Adding elements to the heap\n");
	heap.insert(&heap, 5, 5);
	heap.insert(&heap, 4, 4);
	heap.insert(&heap, 1, 1);
	heap.insert(&heap, 2, 2);
	heap.insert(&heap, 3, 3);
	heap.insert(&heap, 9, 9);
	heap.insert(&heap, 101, 101);
	heap.insert(&heap, 6, 6);
	heap.insert(&heap, 7, 7);
	heap.insert(&heap, 9, 9);
	heap.insert(&heap, 100, 100);
	heap.insert(&heap, 10, 10);
	heap.insert(&heap, 11, 11);
	heap.insert(&heap, 12, 12);
	heap.insert(&heap, 15, 15);
	heap.insert(&heap, 17, 17);

	printf("Printing the heap\n");
	heap.print(&heap);
	printf("\n");

	printf("Printing the heap as a tree\n");
	heap.printTree(&heap);
	printf("\n");

	printf("Deleting the root\n");
	int data, priority;
	printf("Root deleted %ssuccessfully\n", !heap.removeRoot(&heap, &data, &priority) ? "" : "un");
	printf("Node deleted: data %d, priority %d\n", data, priority);

	printf("Printing the heap\n");
	heap.print(&heap);
	printf("\n");
}

void testBST()
{
	BST bst;
	initBst(&bst);

	bst.insert(&bst, 6);
	bst.insert(&bst, 4);
	bst.insert(&bst, 9);
	bst.insert(&bst, 8);
	bst.insert(&bst, 10);

	bst.print(&bst, PRE);
	printf("\n");

	bst.print(&bst, IN);
	printf("\n");

	bst.print(&bst, POST);
	printf("\n");

	printf("Element %s found.\n", (bst.search(&bst, 9)) ? "" : "not");

	printf("%d\n", bst.deleteNode(&bst, 9));

	printf("Element %s found.\n", (bst.search(&bst, 9)) ? "" : "not");

	bst.print(&bst, IN);
	printf("\n");
}

void testAVL()
{
	AVL avl;
	initAvl(&avl);

	avl.insert(&avl, 8);
	avl.insert(&avl, 3);
	avl.insert(&avl, 10);
	avl.insert(&avl, 9);
	avl.insert(&avl, 11);
	avl.insert(&avl, 2);
	avl.insert(&avl, 6);
	avl.insert(&avl, 1);
	avl.insert(&avl, 4);
	avl.insert(&avl, 7);
	avl.insert(&avl, 12);
	avl.insert(&avl, 13);
	avl.insert(&avl, 14);
	avl.insert(&avl, 15);
	avl.insert(&avl, 16);

	avl.print(&avl, IN);
	printf("\n");

	printf("Element %s found.\n", (avl.search(&avl, 8)) ? "" : "not");

	avl.deleteNode(&avl, 8);

	printf("Element %s found.\n", (avl.search(&avl, 8)) ? "" : "not");

	avl.print(&avl, IN);
	printf("\n");
	
}

void testRBT()
{
	RBT rbt;
	initRbt(&rbt);

	rbt.insert(&rbt, 50);
	rbt.insert(&rbt, 12);
	rbt.insert(&rbt, 75);
	rbt.insert(&rbt, 6);
	rbt.insert(&rbt, 25);
	rbt.insert(&rbt, 5);
	rbt.insert(&rbt, 7);

	rbt.print(&rbt, IN);
	printf("\n");

	printf("Element %s found.\n", (rbt.search(&rbt, 12)) ? "" : "not");

	rbt.delete(&rbt, 12);

	printf("Element %s found.\n", (rbt.search(&rbt, 12)) ? "" : "not");

	rbt.print(&rbt, IN);
	printf("\n");
}

void testG()
{
	Graph graphD;
	initGraph(&graphD, 10, DIRECTED);

	printf("Adding edges to a directed graph\n");
	graphD.addEdge(&graphD, 0, 1, 0);
	graphD.addEdge(&graphD, 2, 7, 0);
	graphD.addEdge(&graphD, 2, 8, 0);
	graphD.addEdge(&graphD, 2, 9, 0);
	graphD.addEdge(&graphD, 4, 5, 0);

	graphD.print(&graphD);
	printf("\n");

	int num1 = 2, num2 = 8;
	printf("Edge between %d and %d does%s exist\n", num1, num2, 
		graphD.edgeExists(&graphD, num1, num2) ? "" : " not");

	printf("Deleting edge between %d and %d\n", num1, num2);
	graphD.deleteEdge(&graphD, 2, 8);

	printf("Edge between %d and %d does%s exist\n", num1, num2,
		graphD.edgeExists(&graphD, num1, num2) ? "" : " not");

	graphD.print(&graphD);
	printf("\n");

	Graph graphUnd;
	initGraph(&graphUnd, 10, NOT_DIRECTED);

	printf("Adding edges to an undirected graph\n");
	graphUnd.addEdge(&graphUnd, 0, 1, 0);
	graphUnd.addEdge(&graphUnd, 2, 7, 0);
	graphUnd.addEdge(&graphUnd, 2, 8, 0);
	graphUnd.addEdge(&graphUnd, 2, 9, 0);
	graphUnd.addEdge(&graphUnd, 4, 5, 0);

	graphUnd.print(&graphUnd);
	printf("\n");

	printf("Edge between %d and %d does%s exist\n", num1, num2,
		graphUnd.edgeExists(&graphUnd, num1, num2) ? "" : " not");

	printf("Deleting edge between %d and %d\n", num1, num2);
	graphUnd.deleteEdge(&graphUnd, 2, 8);

	printf("Edge between %d and %d does%s exist\n", num1, num2,
		graphUnd.edgeExists(&graphUnd, num1, num2) ? "" : " not");

	graphUnd.print(&graphUnd);
	printf("\n");

	// TESTING FOR CONNECTIVITY
	printf("Testing the connectivity of the directed graph\n");
	printf("The graph is %sconnected\n", graphD.isConnected(&graphD, 0) ? "" : "not ");

	printf("Adding edges to make the graph connected\n");
	graphD.addEdge(&graphD, 1, 3, 0);
	graphD.addEdge(&graphD, 2, 4, 0);
	graphD.addEdge(&graphD, 3, 5, 0);
	graphD.addEdge(&graphD, 5, 2, 0);
	graphD.addEdge(&graphD, 5, 6, 0);
	graphD.addEdge(&graphD, 7, 8, 0);

	graphD.print(&graphD);
	printf("The graph is %sconnected\n", graphD.isConnected(&graphD, 0) ? "" : "not ");

	printf("\nTesting the connectivity of the undirected graph\n");
	printf("The graph is %sconnected\n", graphUnd.isConnected(&graphUnd, 0) ? "" : "not ");

	printf("Adding edges to make the graph connected\n");
	graphUnd.addEdge(&graphUnd, 1, 3, 0);
	graphUnd.addEdge(&graphUnd, 2, 4, 0);
	graphUnd.addEdge(&graphUnd, 3, 5, 0);
	graphUnd.addEdge(&graphUnd, 5, 2, 0);
	graphUnd.addEdge(&graphUnd, 5, 6, 0);
	graphUnd.addEdge(&graphUnd, 7, 8, 0);

	graphUnd.print(&graphUnd);
	printf("The graph is %sconnected\n", graphUnd.isConnected(&graphUnd, 0) ? "" : "not ");

	// TESTING FOR CYCLES
	printf("\nTesting if the directed graph has a cycle\n");
	printf("The graph does%s have a cycle\n", graphD.hasCycle(&graphD, 0) ? "" : " not");

	printf("Adding edges to create a cycle\n");
	graphD.addEdge(&graphD, 6, 0, 0);

	graphD.print(&graphD);
	printf("The graph does%s have a cycle\n", graphD.hasCycle(&graphD, 0) ? "" : " not");

	printf("\nTesting if the undirected graph has a cycle\n");
	printf("The graph does%s have a cycle\n", graphUnd.hasCycle(&graphUnd, 0) ? "" : " not");

	printf("Adding edges to create a cycle\n");
	graphUnd.addEdge(&graphUnd, 6, 0, 0);

	graphUnd.print(&graphUnd);
	printf("The graph does%s have a cycle\n", graphUnd.hasCycle(&graphUnd, 0) ? "" : " not");

	// TESTING THE VERTEX DEGREE
	printf("\nTesting the vertex degree for a directed graph\n");
	int vertex = 2;
	printf("The in degree of %d is %d\n", vertex, graphD.getDegree(&graphD, vertex, INCOMING));
	printf("The out degree of %d is %d\n", vertex, graphD.getDegree(&graphD, vertex, OUTGOING));

	printf("Testing the vertex degree for a undirected graph\n");
	printf("The in degree of %d is %d\n", vertex, graphUnd.getDegree(&graphUnd, vertex, INCOMING));
	printf("The out degree of %d is %d\n", vertex, graphUnd.getDegree(&graphUnd, vertex, OUTGOING));

	// TESTING SEARCH
	printf("\nTesting the search for a directed graph\n");
	num1 = 0, num2 = 8;
	printf("%d was%s found starting from %d using DFS\n", num2, 
		graphD.vertexExists(&graphD, num1, num2, DFS) ? "" : " not", num1);
	printf("%d was%s found starting from %d using BFS\n", num2,
		graphD.vertexExists(&graphD, num1, num2, BFS) ? "" : " not", num1);
	printf("%d was%s found starting from %d using DFS\n", num1,
		graphD.vertexExists(&graphD, num2, num1, DFS) ? "" : " not", num2);
	printf("%d was%s found starting from %d using BFS\n", num1,
		graphD.vertexExists(&graphD, num2, num1, BFS) ? "" : " not", num2);

	printf("\nTesting the search for a undirected graph\n");
	printf("%d was%s found starting from %d using DFS\n", num2,
		graphUnd.vertexExists(&graphUnd, num1, num2, DFS) ? "" : " not", num1);
	printf("%d was%s found starting from %d using BFS\n", num2,
		graphUnd.vertexExists(&graphUnd, num1, num2, BFS) ? "" : " not", num1);
	printf("%d was%s found starting from %d using DFS\n", num1,
		graphUnd.vertexExists(&graphUnd, num2, num1, DFS) ? "" : " not", num2);
	printf("%d was%s found starting from %d using BFS\n", num1,
		graphUnd.vertexExists(&graphUnd, num2, num1, BFS) ? "" : " not", num2);

	// TESTING SHORTEST PATH
	printf("Testing the shortest path algorithms\n");
	printf("Creating a new graph");

	Graph graphW;
	initGraph(&graphW, 6, DIRECTED);
	
	graphW.addEdge(&graphW, 0, 1, 2);
	graphW.addEdge(&graphW, 0, 2, 4);
	graphW.addEdge(&graphW, 1, 2, 1);
	graphW.addEdge(&graphW, 1, 3, 4);
	graphW.addEdge(&graphW, 1, 4, 2);
	graphW.addEdge(&graphW, 2, 4, 3);
	graphW.addEdge(&graphW, 3, 5, 2);
	graphW.addEdge(&graphW, 4, 3, 3);
	graphW.addEdge(&graphW, 4, 5, 2);

	graphW.shortestPath(&graphW, 0);

	printf("The shortest path:\n");
	int total = 0;
	int start = 0, end = 5;
	while (end != start)
	{
		printf("Vertex: %d\n", end);
		end = graphW.vertices[end].parent;
		total += graphW.vertices[end].distance;
	}

	printf("The distance of the shortest path is %d", total);
}

int main()
{
	testG();
}
