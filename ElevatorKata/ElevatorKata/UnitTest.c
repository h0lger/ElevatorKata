#include "Elevator.h"
#include <stdio.h>


void AddDeleteTest()
{
	ListNodePtr startPtr = NULL;
	Request r = createRequest(10, up, false);	
	
	insert(&startPtr, r);
	printList(startPtr);

	delete(&startPtr, r);
	printList(startPtr);
}