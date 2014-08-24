/*
* Test.c
*
*  Created on: Aug 20, 2014
*      Author: david
*/
#include "Elevator.h"
#include <stdio.h>


void AddDeleteTest()
{
	ListNodePtr startPtr = NULL;
	Request r;
	r.ElevatorFloor = 3;
	r.Floor = 1;	
	insert(&startPtr, r);
	printList(startPtr);

}