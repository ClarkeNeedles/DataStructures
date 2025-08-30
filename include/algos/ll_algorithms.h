/*********************************************************************************************
**
**	File Name:		ll_algorithms.c
**	Description:	Contains the function declarations for the linked list algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#pragma once

#include "ds/linkedlist.h"

int searchList(LinkedList* list, int data);

Node* splitList(Node* head);

void mergeList(Node** first, Node** second);

void mergeSortList(LinkedList* list);