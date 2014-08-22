/*
* Elevator.h
*
*  Created on: Aug 20, 2014
*      Author: david
*/

#ifndef ELEVATOR_H_
#define ELEVATOR_H_

typedef struct
{
	short floor; //requested floor
	short elevatorFloor; //the current position when the request was made
}
Request;

//Linked list for the Request struct
typedef struct
{
	Request data;
	struct listNode *nextPtr; //Pointer to the next node
}
listNode;

//Synonym
typedef listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, Request value);
void delete(ListNodePtr *sPtr, Request value);
int isEmpty(ListNodePtr currentPtr);
void printList(ListNodePtr currentPtr);


#endif /* ELEVATOR_H_ */