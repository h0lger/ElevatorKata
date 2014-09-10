#ifndef ELEVATOR_H_
#define ELEVATOR_H_

enum DirectionEnum
{
	down = 0,
	up = 1
};

typedef enum
{
	false = 0,
	true = 1
} bool;

typedef struct
{
	short Floor; //requested floor		
	enum DirectionEnum Direction;
	bool IsOutsideCall;
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

//Linked list
void insert(ListNodePtr *sPtr, Request value);
short delete(ListNodePtr *sPtr, Request value);
int isEmpty(ListNodePtr currentPtr);
void printList(ListNodePtr currentPtr);

//Elevator
const char* getDirection(enum DirectionEnum dir);
const char* getOutsideCall(bool isOutsideCall);
Request createRequest(short floor, enum DirectionEnum dir, bool isOutsideCall);
bool areEqual(Request req1, Request req2);


#endif /* ELEVATOR_H_ */