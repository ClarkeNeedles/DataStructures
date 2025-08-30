/*********************************************************************************************
**
**	File Name:		dqueue_algorithms.h
**	Description:	Contains the function declarations for the dynamic queue algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#pragma once

#include "ds/dqueue.h"

int searchDQueue(DQueue* queue, int data);

Node* splitDQueue(Node* front);

void mergeDQueue(Node** first, Node** second);

void mergeSortDQueue(DQueue* queue);