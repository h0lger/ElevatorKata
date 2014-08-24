/*
* Elevator.h
*
*  Created on: Aug 20, 2014
*      Author: david
*/

#ifndef ELEVATOR_H_
#define ELEVATOR_H_

enum DirectionEnum
{
	down,
	up
};

typedef struct
{
	short Floor; //requested floor	
	short ElevatorFloor; //the current position when the request was made
	enum DirectionEnum Direction;
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