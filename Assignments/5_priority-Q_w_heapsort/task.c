/*****************************************************************************************
 * CS 261 Assignment 5
 * Name: Jacob Karcz
 * Date: 11.07.2016
 ****************************************************************************************/

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


/**
 * Creates a new task with the given priority and name.
 * @parameter priority
 * @parameter name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name) {
    // FIXME: implement <-----------------------------------------------------------------
    struct Task *newTask;
    newTask = malloc(sizeof(struct Task));
    assert (newTask != NULL);

    newTask->priority = priority;
    strcpy(newTask->name, name);
    /*
    int i;
    int j = strlen(name);
    for (i = 0; i < j; i++)
        newTask->name[i] = name[i];
    for(int k = i; k < 128; k++)
        newTask->name[k] = ' ';
    */
    
    return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @parameter task
 */
void taskDelete(Task* task) {
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @returning
 */
int taskCompare(void *left, void *right) {
    // FIXME: implement <-----------------------------------------------------------------
    
    /*
    assert (left != NULL);
    assert (right != NULL);
    */
    if (left == NULL && right != NULL)
        return -1;
    if (left != NULL && right == NULL)
        return 1;
    if (left == NULL && right == NULL)
        return 0;
    
    //typeCast TYPE void * as TYPE data
    struct Task *taskLeft;
    struct Task *taskRight;
    taskLeft = (struct Task *) left;
    taskRight = (struct Task *) right;
    
    //compare the values of the data structs
    if (taskLeft->priority < taskRight->priority)
        return -1;
    else if (taskLeft->priority > taskRight->priority)
        return 1;
    else
        return 0;

}



/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value) {
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
