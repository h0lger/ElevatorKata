#include <stdio.h>
#include "Elevator.h"
#include <stdlib.h>

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

short delete(ListNodePtr *sPtr, Request value)
{
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tmpPtr;
	short deleted = 0;

	//Delete first node
	//TODO: Create hash instead of looking att only floor
	if (value.Floor == (*sPtr)->data.Floor)
	{
		tmpPtr = *sPtr; //save it temporary
		*sPtr = (*sPtr)->nextPtr; //de-thread the node
		free(tmpPtr);
		deleted++;
	}
	else
	{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;

		//Loop to find the correct location in the list
		//TODO: Create hash instead of looking att only floor
		while (currentPtr != NULL && currentPtr->data.Floor != value.Floor)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr != NULL)
		{
			tmpPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tmpPtr);
			deleted++;
		}
	}

	return deleted; //0 if none is deleted
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
			printf_s("[%d - %s - outside call: %s]",
				currentPtr->data.Floor,
				getDirection(currentPtr->data.Direction), 
				getOutsideCall(currentPtr->data.IsOutsideCall)
				);
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

const char* getOutsideCall(bool isOutsideCall)
{	
	
	if (isOutsideCall)
		return "yes";
	else
		return "no";
}

//Create request
Request createRequest(short floor, enum DirectionEnum dir, bool isOutsideCall)
{
	Request r;
	r.Floor = floor;
	r.Direction = dir;
	r.IsOutsideCall = isOutsideCall;

	return r;
}