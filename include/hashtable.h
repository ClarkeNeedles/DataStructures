/*********************************************************************************************
**
**	File Name:		hashtable.h
**	Description:	Contains the data type definition for a hash table that uses
**					collision resolution (separate chaining). Also contains
**					the function declaration for initializing one.
**
**	Author:			Clarke Needles
**	Created:		5/28/2025
**
**********************************************************************************************/

#pragma once

#include "hash_node.h"

typedef struct HashTable
{
	int size;
	HNode** buckets;

	void (*insert)(struct HashTable* self, const char* key, int data);
	int (*deleteItem)(struct HashTable* self, const char* key);
	void (*expand)(struct HashTable* self);
	void (*print)(struct HashTable* self);
	int (*search)(struct HashTable* self, const char* key);
} HashTable;

void initHashTable(HashTable *hashTable, int size);
