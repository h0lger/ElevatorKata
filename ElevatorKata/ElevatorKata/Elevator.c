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

		while (currentPtr != NULL && !areEqual(value, currentPtr->data))
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
	if (areEqual(value,(*sPtr)->data))
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
		while (currentPtr != NULL && !areEqual(currentPtr->data, value))
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

//Print contents of the list
void printList(ListNodePtr currentPtr)
{
	short counter = 0;
	if (isEmpty(currentPtr))
	{
		puts("List is empty\n");
	}
	else
	{
		puts("Requested floors:");
		while (currentPtr != NULL)
		{
			counter++;
			printf_s("%d. [%d - %s - outside call: %s]\n",
				counter,
				currentPtr->data.Floor,
				getDirection(currentPtr->data.Direction), 
				getOutsideCall(currentPtr->data.IsOutsideCall)
				);
			currentPtr = currentPtr->nextPtr;
		}
		puts("\n");
	}
}

//Returns first request in list
Request getFirst(ListNodePtr currentPtr)
{
	if (isEmpty(currentPtr))
		puts("Error null value passed");

	return currentPtr->data;
}

//Get first by floor
Request getFirstByFloor(ListNodePtr currentPtr, short floor)
{
	Request req;

	if (isEmpty(currentPtr))
		puts("Error null value passed");

	while (currentPtr != NULL)
	{
		if (currentPtr->data.Floor == floor)
			return req = currentPtr->data;
		currentPtr = currentPtr->nextPtr;
	}
	//Return NULL if not found
	return req;
}

//Get direction as text
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

//Get isOutsideCall as text
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

//Compare 2 request structs to check if they are equal
bool areEqual(Request req1, Request req2)
{
	if (req1.Direction != req2.Direction)
		return false;
	else if (req1.Floor != req2.Floor)
		return false;
	else if (req1.IsOutsideCall != req2.IsOutsideCall)
		return false;
	else
		return true;
}