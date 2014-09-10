#include "Elevator.h"
#include <stdio.h>


//Simple add, deletion test
void AddDeleteTest()
{	
	ListNodePtr startPtr = NULL;
	//Insert 1
	Request r = createRequest(10, up, false);		
	insert(&startPtr, r);	
	//Insert 2
	r = createRequest(7, down, false);
	insert(&startPtr, r);
	
	printList(startPtr);

	//Try delete
	printf("After delete:\n");
	r = getFirst(startPtr);
	delete(&startPtr, r); //Delete floor 10
	printList(startPtr);

	r = createRequest(11, down, false);
	insert(&startPtr, r);
	r = createRequest(15, down, false);
	insert(&startPtr, r);
	printList(startPtr); //3 requests floor 7, 11, 15
	r = getFirstByFloor(startPtr, 11);
	delete(&startPtr, r); //Delete floor 11
	printList(startPtr); //3 requests floor 7, 15

}
