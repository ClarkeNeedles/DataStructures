/*********************************************************************************************
**
**	File Name:		dll_algorithms.h
**	Description:	Contains the function declarations for the doubly linked list algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#pragma once

#include "ds/dlinkedlist.h"

int searchDList(DLinkedList* list, int data);

DNode* splitDList(DNode* head);

void mergeDList(DNode** first, DNode** second);

void mergeSortDList(DLinkedList* list);