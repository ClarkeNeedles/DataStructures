/*********************************************************************************************
**
**	File Name:		dstack_algorithms.h
**	Description:	Contains the function declarations for the dynamic stack algorithms.
**
**	Author:			Clarke Needles
**	Created:		6/5/2025
**
**********************************************************************************************/

#pragma once

#include "dstack.h"

int searchDStack(DStack* stack, int data);

Node* splitDStack(Node* head);

void mergeDStack(Node** first, Node** second);

void mergeSortDStack(DStack* stack);