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
	Request r = createRequest(10, up);	
	
	insert(&startPtr, r);
	printList(startPtr);

}