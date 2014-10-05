#include "Elevator.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void printHeader(char *text)
{
	printf_s("-- %s ----------------------------------------------\n", text);
}

void printElevatorInfo()
{
	printf_s("Elevator@%d", getCurrentFloor());
	printf_s(" going %s\n\n", getDirection(getCurrentDirection()));
}

void printOrder(short * order, short arrSize)
{
	puts("Order:");	
	for (size_t i = 0; i < arrSize; i++)
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
	printHeader("AddDeleteTest");

	//Init
	ListNodePtr startPtr = NULL;
	Request r;

	//Insert 1
	r = createRequest(10, up, false);		
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

	free(startPtr);
}

//Advanced tests
//3: Elevator @ 10 → 1(up) Q: 5(down) Ex: 5, 1
void advTestOutside3()
{
	printHeader("AdvTest3");
	static const int arrSize = 2;
	short order[2];
	//Initialize queue
	ListNodePtr startPtr = NULL;
	Request r;

	//Create requests
	r = createRequest(1, up, true);
	insert(&startPtr, r);
	r = createRequest(5, down, true);
	insert(&startPtr, r);

	//Init position
	setCurrentFloor(10);	
	setCurrentDirection(down);
	
	printElevatorInfo();
	printList(startPtr);
	nextRequest(startPtr, &order, arrSize);

	//Validate
	assert(order[0] == 5);
	assert(order[1] == 1);

	printOrder(order, arrSize);
	free(startPtr);	
}

//4: Elevator @ 10 →  5(up)Q:1(up)Ex : 1, 5
void advTestOutside4()
{
	printHeader("AdvTest4");
	static const int arrSize = 2;
	short order[2];
	//Initialize queue
	ListNodePtr startPtr = NULL;
	Request r;

	//Create requests
	r = createRequest(5, up, true);
	insert(&startPtr, r);
	r = createRequest(1, up, true);
	insert(&startPtr, r);
	
	//Init position
	setCurrentFloor(10);
	setCurrentDirection(down);

	printElevatorInfo();
	printList(startPtr);
	nextRequest(startPtr, &order, arrSize);

	//Validate
	assert(order[0] == 1);
	assert(order[1] == 5);

	printOrder(order, arrSize);
	free(startPtr);
}

//5: Elevator @ 10 → 1(up)Q: 3(down), 5(down)Ex : 5, 3, 1
void advTestOutside5()
{
	printHeader("AdvTest5");
	static const int arrSize = 3;
	short* order; //pointer to dynamic array
	order = calloc(arrSize, sizeof(short));
	//Initialize queue
	ListNodePtr startPtr = NULL;
	Request r;

	//Create requests
	r = createRequest(3, down, true);
	insert(&startPtr, r);
	r = createRequest(5, down, true);
	insert(&startPtr, r);
	r = createRequest(1, up, true);
	insert(&startPtr, r);

	//Init position
	setCurrentFloor(10);
	setCurrentDirection(down);

	printElevatorInfo();
	printList(startPtr);
	nextRequest(startPtr, order, arrSize);

	////Validate
	assert(order[0] == 5);
	assert(order[1] == 3);
	assert(order[2] == 1);

	printOrder(order, arrSize);
	free(startPtr);
}

//6: Elevator @ 10 → 5(up) Q: 3(up), 1(up) Ex: 3, 1, 5
void advTestOutside6()
{
	printHeader("AdvTest6");
	static const int arrSize = 3;
	short* order; //pointer to dynamic array
	order = calloc(arrSize, sizeof(short));
	//Initialize queue
	ListNodePtr startPtr = NULL;
	Request r;

	//Create requests
	r = createRequest(3, up, true);
	insert(&startPtr, r);
	r = createRequest(1, up, true);
	insert(&startPtr, r);
	r = createRequest(5, up, true);
	insert(&startPtr, r);

	//Init position
	setCurrentFloor(10);
	setCurrentDirection(down);

	printElevatorInfo();
	printList(startPtr);
	nextRequest(startPtr, order, arrSize);

	////Validate
	//Should be 1,3,5?
	assert(order[0] == 1);
	assert(order[1] == 3);
	assert(order[2] == 5);

	printOrder(order, arrSize);
	free(startPtr);
}

//6.1: Elevator @ 3 → 8 Q: 1(up), 5(up)Ex : 5, 8, 1
void advTestOutside6_1()
{
	printHeader("AdvTest6.1");
	static const int arrSize = 3;
	short* order; //pointer to dynamic array
	order = calloc(arrSize, sizeof(short));
	//Initialize queue
	ListNodePtr startPtr = NULL;
	Request r;

	//Create requests
	r = createRequest(1, up, true);
	insert(&startPtr, r);
	r = createRequest(5, up, true);
	insert(&startPtr, r);
	r = createRequest(8, up, true);
	insert(&startPtr, r);

	//Init position
	setCurrentFloor(3);
	setCurrentDirection(up);

	printElevatorInfo();
	printList(startPtr);
	nextRequest(startPtr, order, arrSize);

	////Validate	
	assert(order[0] == 5);
	assert(order[1] == 8);
	assert(order[2] == 1);

	printOrder(order, arrSize);
	free(startPtr);
}

//7: Elevator @ 19 → 18(up) Q:1(down) Ex: 1, 18
void advTestOutside7()
{
	printHeader("AdvTest7");
	static const int arrSize = 2;
	short* order; //pointer to dynamic array
	order = calloc(arrSize, sizeof(short));
	//Initialize queue
	ListNodePtr startPtr = NULL;
	Request r;

	//Create requests
	r = createRequest(18, up, true);
	insert(&startPtr, r);
	r = createRequest(1, down, true);
	insert(&startPtr, r);	

	//Init position
	setCurrentFloor(19);
	setCurrentDirection(down);

	printElevatorInfo();
	printList(startPtr);
	nextRequest(startPtr, order, arrSize);

	////Validate	
	assert(order[0] == 1);
	assert(order[1] == 18);	

	printOrder(order, arrSize);
	free(startPtr);
}
