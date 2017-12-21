//
//  compare.c
//  Assignment_4
//
//  Created by Jacob Karcz on 10/24/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//
/* CS261- Assignment 4 - bst.c */
/* Name: Jacob Karcz
 * Date: 10.24.2016
 * Solution description: binary search tree comapnion compare function implementation file
 */

#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.
 
 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

/*Define this function, type casting the value of void * to the desired type.
 The current definition of TYPE in bst.h is void*, which means that left and
 right are void pointers. To compare left and right, you should first cast
 left and right to the corresponding pointer type (struct data *), and then
 compare the values pointed by the casted pointers.
 
 DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
 which is really wrong.
 */
/*****************************************************************************************
 *Compare function for data stgruct holding a name and number
 *function: compare(TYPE left, TYPE right)
 *precondition: left and right are not null of TYPE void *
 *parameter(s): left and right bst pointers to void
 *postcondition:  if left < right return -1
                  if left > right return 1
                  if left = right return 0
 ****************************************************************************************/
int compare(TYPE left, TYPE right) {
    /*FIXME: write this*/
    assert (left != NULL);
    assert (right != NULL);
    
    //typeCast TYPE void * as TYPE data
    struct data *leftData;
    struct data *rightData;
    leftData = (struct data *) left;
    rightData = (struct data *) right;
    
    //compare the values of the data structs
    if (leftData->number < rightData->number)
        return -1;
    else if (leftData->number > rightData->number)
        return 1;
    else
        return 0;
    return 0;
    
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval) {
    /*FIXME: write this*/
    
    struct data *dataPtr;
    dataPtr = (struct data *) curval;
    
    printf("%s: %d\n", dataPtr->name, dataPtr->number);
}




