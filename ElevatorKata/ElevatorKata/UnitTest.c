#include "Elevator.h"
#include <stdio.h>
#include <assert.h>

void printElevatorInfo()
{
	printf_s("Elevator@%d", getCurrentFloor());
	printf_s(" going %s\n\n", getDirection(getCurrentDirection()));
}

void printOrder(short * order)
{
	puts("Order:");
	short array_size = (sizeof(order) / sizeof(short));
	for (size_t i = 0; i < array_size; i++)
	{
		if (i > 0)
			printf(", %d", order[i]);
		else
			printf_s("%d", order[i]);
	}
	puts("");
}

//Simple add, deletion test
void addDeleteTest()
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

//Advanced tests
//3: Elevator @ 10 → 1(up) Q: 5(down) Ex: 5, 1
void advTestOutside3()
{
	short order[MAX_ARRAY_SIZE];
	//Initialize queue
	ListNodePtr startPtr = NULL;
	//Insert 1
	Request r = createRequest(1, up, true);
	insert(&startPtr, r);
	r = createRequest(5, down, true);
	insert(&startPtr, r);
	//Init position
	setCurrentFloor(10);	
	setCurrentDirection(down);
	
	printElevatorInfo();
	printList(startPtr);
	nextRequest(startPtr, &order);

	//Validate
	assert(order[0] == 5);
	assert(order[1] == 1);

	printOrder(&order);
}

//4: Elevator @ 10 →  5(up)Q:1(up)Ex : 1, 5
void advTestOutside4()
{
	short order[2];
	//Initialize queue
	ListNodePtr startPtr = NULL;
	//Insert 1
	Request r = createRequest(5, up, true);
	insert(&startPtr, r);
	r = createRequest(1, up, true);
	insert(&startPtr, r);
	//Init position
	setCurrentFloor(10);
	setCurrentDirection(down);

	printElevatorInfo();
	printList(startPtr);
	nextRequest(startPtr, &order);

	//Validate
	assert(order[0] == 1);
	assert(order[1] == 5);

	printOrder(&order);
}
