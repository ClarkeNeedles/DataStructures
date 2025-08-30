/*********************************************************************************************
**
**	File Name:		ht_algorithms.c
**	Description:	Contains the function definitions for the hash table algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#include <string.h>
#include "algos/ht_algorithms.h"

// Uses the FNV-1a hash function
unsigned int hashFunction(const char* key, size_t size)
{
	const unsigned int fnvPrime = 16777619;
	const unsigned int offsetBasis = 2166136261;

	unsigned int hash = offsetBasis;
	for (size_t i = 0; key[i] != '\0'; i++)
	{
		// Bitwise XOR
		hash ^= (unsigned char)key[i];
		hash *= fnvPrime;
	}

	return hash % size;
}

// Search for a value in a hash table
// This will return the data corresponding to the key, not the index
int searchHash(HashTable* hashTable, const char* key) {
	unsigned int index = hashFunction(key, hashTable->size);

	HNode* curr = hashTable->buckets[index];
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
		{
			return curr->data;
		}
		curr = curr->next;
	}

	// Key not found
	return -1;
}