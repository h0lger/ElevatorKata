#include "Elevator.h"
#include <stdio.h>


//Simple add, deletion test
void AddDeleteTest()
{
	ListNodePtr startPtr = NULL;
	Request r = createRequest(10, up, false);	
	
	insert(&startPtr, r);	
	r = createRequest(7, down, false);
	insert(&startPtr, r);
	printList(startPtr);
	printf("After delete:\n");
	delete(&startPtr, r);
	printList(startPtr);
}