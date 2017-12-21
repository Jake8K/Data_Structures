//
//  circularList.c
//  CS261 MT ADT Practice
//
//  Created by Jacob Karcz on 10/19/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
    TYPE value;
    struct Link * next;
    struct Link * prev;
};

struct CircularList
{
    int size;
    struct Link* sentinel;
};

/*****************************************************************************************
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 ****************************************************************************************/
static void init(struct CircularList* list)
{
    // FIXME: you must write this
    
    //malloc
    list->sentinel = malloc(sizeof(struct Link));
    assert(list->sentninel != null);
    
    //members
    list->size = 0;
    list->sentinel->next = list->sentinel->prev;
    list->sentinel->prev = list->sentinel->next;
}

/*****************************************************************************************
 * Creates a link with the given value and NULL next and prev pointers.
 ****************************************************************************************/
static struct Link* createLink(TYPE value)
{
    // FIXME: you must write this
    
    //create
    struct Link *link;
    link = (struct link*) malloc(sizeof(struct link));
    assert(link != null);
    
    //initialize
    link->next = NULL;
    link->prev = NULL;
    link->value = value;
    
    //return
    return link;
}

/*****************************************************************************************
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 ****************************************************************************************/
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
    // FIXME: you must write this
    
    //create
    struct Link newLink;
    newLink = createLink(value);
    assert(newlink != null);
    
    //set pointers
    newLink->next = link->next;
    link->next->prev = newLink;
    newLink->prev = link;
    link->next = newLink;
    
    //++ size
    list->size++;
    
}

/*****************************************************************************************
 * Removes the given link from the list and
 * decrements the list's size.
 ****************************************************************************************/
static void removeLink(struct CircularList* list, struct Link* link)
{
    // FIXME: you must write this
    
    //hold the link *
    struct Link temp;
    temp = link;
    
    //set pointers
    link->next->prev = link->prev;
    link->prev->next = link->next;
    
    //deallocate
    free(temp);
    
    //-- size
    list->size--;
    
}

/*****************************************************************************************
 * Allocates and initializes a list.
 ****************************************************************************************/
struct CircularList* circularListCreate()
{
    struct CircularList* list = malloc(sizeof(struct CircularList));
    init(list);
    return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
    // FIXME: you must write this
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
    // FIXME: you must write this
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
    // FIXME: you must write this
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
    // FIXME: you must write this
    return 0;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
    // FIXME: you must write this
    return 0;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
    // FIXME: you must write this
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
    // FIXME: you must write this
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
    // FIXME: you must write this
    return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
    // FIXME: you must write this
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
    // FIXME: you must write this
}

