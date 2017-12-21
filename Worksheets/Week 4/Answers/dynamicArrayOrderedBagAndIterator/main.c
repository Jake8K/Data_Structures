#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"

int main (int argc, const char * argv[]) {

#ifdef TESTITER
    struct DynArr *myStack;

	myStack =  createDynArr(4);

	pushDynArr(myStack, 0);
	//pushDynArr(myStack, 1);
	//pushDynArr(myStack, 2);
	//pushDynArr(myStack, 3);

	struct DynArrIter *myIter;
	myIter = createDynArrIter(myStack);

	while(hasNextDynArrIter(myIter))
		{
			TYPE val = nextDynArrIter(myIter);
			if(val != 0)
				printf("The next value in the stack is: %d\n", val);
			else {
				printf("The next value in the stack is: %d\n", val);
				removeDynArrIter(myIter);
			}
		}

	printf("After removing 0 \n");
	initDynArrIter(myStack, myIter);

	while(hasNextDynArrIter(myIter))
		printf("The next value in the stack is: %d\n", nextDynArrIter(myIter));
#endif

	struct DynArr *myBag;
	myBag = createDynArr(5);

	addODynArr(myBag, 10);
	addODynArr(myBag, 3);
	addODynArr(myBag,44);
	addODynArr(myBag, 1);

	struct DynArrIter *myIter;
	myIter = createDynArrIter(myBag);
	initDynArrIter(myBag, myIter);

	while(hasNextDynArrIter(myIter))
		printf("The next value in the stack is: %d\n", nextDynArrIter(myIter));


	if(containsODynArr(myBag, 3))
		printf("Contained 3\n");

	removeODynArr(myBag, 3);

	if(containsODynArr(myBag, 3))
		printf("After removed contained 3\n");
	else printf("After remove, does not contain 3\n");


	return(0);

}
