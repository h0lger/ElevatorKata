/*
* Elevator.c
*
*  Created on: Aug 20, 2014
*      Author: david
*/
#include <stdio.h>
#include "Elevator.h"
#include <stdlib.h>

#define INIT_SIZE 1

Request _reqArray[INIT_SIZE];

void insert(ListNodePtr *sPtr, Request value)
{
	ListNodePtr newPtr; //new one
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;

	newPtr = malloc(sizeof(ListNode)); //Create node

	if (newPtr != NULL)
	{
		newPtr->data = value;
		newPtr->nextPtr = NULL; //no link here

		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && (value.Floor != currentPtr->data.Floor && value.ElevatorFloor != currentPtr->data.ElevatorFloor))
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		//insert new node
		if (previousPtr == NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else
	{
		printf("No memory available\n");
	}

}

int isEmpty(ListNodePtr sPtr)
{
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr)
{
	if (isEmpty(currentPtr))
	{
		puts("List is empty\n");
	}
	else
	{
		puts("The list contains:");
		while (currentPtr != NULL)
		{			
			printf_s("Floor: %d direction: %s from: %d",
				currentPtr->data.Floor, currentPtr->data.Direction, currentPtr->data.ElevatorFloor);
			currentPtr = currentPtr->nextPtr;
		}
		puts("NULL\n");
	}
}