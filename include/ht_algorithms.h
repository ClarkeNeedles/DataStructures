/*********************************************************************************************
**
**	File Name:		ht_algorithms.h
**	Description:	Contains the function declarations for the hash table algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#pragma once

#include "hashtable.h"

unsigned int hashFunction(const char* key, size_t size);

int searchHash(HashTable* hashTable, const char* key);