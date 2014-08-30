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

		while (currentPtr != NULL && (value.Floor != currentPtr->data.Floor))
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
		puts("Requested floors:");
		while (currentPtr != NULL)
		{			
			printf_s("[%d - %s]",
				currentPtr->data.Floor, getDirection(currentPtr->data.Direction));
			currentPtr = currentPtr->nextPtr;
		}
		puts("");
	}
}

const char* getDirection(enum DirectionEnum dir)
{
	switch (dir)
	{
	case down:
		return "down";
		break;
	case up:
		return "up";
		break;
	default:
		return "NOT_DEFINED";
		break;
	}
}

//Create request
Request createRequest(short floor, enum DirectionEnum dir)
{
	Request r;
	r.Floor = floor;
	r.Direction = dir;
}