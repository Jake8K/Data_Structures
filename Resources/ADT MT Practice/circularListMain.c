//
//  circularListMain.c
//  CS261 MT ADT Practice
//
//  Created by Jacob Karcz on 10/19/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include "circularList.h"
#include <stdio.h>


int main()
{
    struct CircularList *deque = circularListCreate();
    printf("deque exists\n");
    //circularListAddFront(deque, 1);
    circularListAddBack(deque, (TYPE)1);
    circularListAddBack(deque, (TYPE)2);
    circularListAddBack(deque, (TYPE)3);
    circularListAddFront(deque, (TYPE)4);
    circularListAddFront(deque, (TYPE)5);
    circularListAddFront(deque, (TYPE)6);
    circularListAddFront(deque, (TYPE)7);
    circularListAddFront(deque, (TYPE)8);
    circularListAddFront(deque, (TYPE)9);
    circularListAddFront(deque, (TYPE)10);
    
    
    circularListPrint(deque);
    printf("%g\n", circularListFront(deque));
    printf("%g\n", circularListBack(deque));
    
    circularListRemoveFront(deque);
    circularListRemoveBack(deque);
    circularListPrint(deque);
    
    circularListReverse(deque);
    circularListPrint(deque);
    
    circularListDestroy(deque);
    
    return 0;
}
