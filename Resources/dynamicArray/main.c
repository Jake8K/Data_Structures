#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"

int main (int argc, const char * argv[]) {

    struct DynArr *myBag;


	myBag =  createDynArr(10);


	addDynArr(myBag, 1);
	addDynArr(myBag, 3);
	removeDynArr(myBag, 3);

	int res = containsDynArr(myBag,1);

	if(res > 0)
		printf("Contained 1 \n");
	else printf("Did not contain 1\n");

	res = containsDynArr(myBag, 3);

	if(res > 0)
		printf("Contained 3\n");
	else printf("Did not contain 3\n");
	return(0);

}
