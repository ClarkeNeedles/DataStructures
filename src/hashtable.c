/*********************************************************************************************
**
**	File Name:		hashtable.c
**	Description:	Contains the function definitions and assigning these functions to the
**					hash table function pointers in the definition. These are all for
**					general usage of a hash table that uses seperate chaining.
**
**	Author:			Clarke Needles
**	Created:		5/28/2025
**
**********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"
#include "algos/ht_algorithms.h"

// Insert new data into the hash table
void insertHash(HashTable* hashTable, const char* key, int data)
{
	unsigned int index = hashFunction(key, hashTable->size);

	// Add new node to the front of the linked list
	HNode* newNode = createHNode(key, data);
	newNode->next = hashTable->buckets[index];
	hashTable->buckets[index] = newNode;
}

int deleteHash(HashTable* hashTable, const char* key)
{
	unsigned int index = hashFunction(key, hashTable->size);

	HNode* curr = hashTable->buckets[index];
	// Only one node
	if (!curr->next)
	{
		int temp = curr->data;
		curr = NULL;
		return temp;
	}

	while (curr->next) 
	{
		if (strcmp(curr->next->key, key) == 0) 
		{
			int temp = curr->next->data;
			free(curr->next);
			curr->next = NULL;
			return temp;
		}
		curr = curr->next;
	}

	// Key not found
	return -1;
}

// Create more space for the current hash table
void expandHash(HashTable* hashTable)
{
	// Create new mem block
	// New size is half the old size more
	int oldSize = hashTable->size;
	hashTable->size += oldSize / 2;

	HNode** oldHash = hashTable->buckets;
	HNode** newHash = (HNode**)calloc(hashTable->size, sizeof(HNode*));
	if (!newHash)
	{
		free(newHash);
		return;
	}
	hashTable->buckets = newHash;

	// Rehashing all the contents into new hash table
	while (--oldSize)
	{
		HNode* curr = oldHash[oldSize];
		while (curr)
		{
			insertHash(hashTable, curr->key, curr->data);
			curr = curr->next;
		}
	}

	// Free old mem block
	free(oldHash);
}

// Print data from the hash table
void printHash(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->size; ++i)
	{
		if (hashTable->buckets[i])
		{
			printf("Index %d: ", i);
			HNode* curr = hashTable->buckets[i];
			while (curr)
			{
				printf("%d -> ", curr->data);
				curr = curr->next;
			}
			printf("NULL\n");
		}
	}
}

// Initialize the hash table
void initHashTable(HashTable* hashTable, int size)
{
	// Allocate space for the hash array
	hashTable->buckets = (HNode**)calloc(size, sizeof(HNode*));
	if (!hashTable->buckets)
	{
		return;
	}

	hashTable->size = size;
	hashTable->insert = insertHash;
	hashTable->deleteItem = deleteHash;
	hashTable->print = printHash;
	hashTable->search = searchHash;
	hashTable->expand = expandHash;
}