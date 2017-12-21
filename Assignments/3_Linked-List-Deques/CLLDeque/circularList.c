/* CS261- Assignment 3 - circularList.c */
/* Name: Jacob Karcz
 * Date: 10.12.2016
 * Solution description: Circular linked List function implementation file to use in
 *                       bag and deque ADTs
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link *next;
	struct Link *prev;
};

struct CircularList
{
	int size;
	struct Link *sentinel;
};

/*****************************************************************************************
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 ****************************************************************************************/
static void init(struct CircularList *list)
{
    // FIXME: you must write this
    assert(list != NULL);

    //malloc
    list->sentinel = malloc(sizeof(struct Link));
    assert(list->sentinel != NULL);
    
    //members
    list->size = 0;
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
}

/*****************************************************************************************
 * Creates a link with the given value and NULL next and prev pointers.
 ****************************************************************************************/
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
    
    //create
    struct Link *link;
    link = malloc(sizeof(struct Link));
    assert(link != NULL);
    
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
    assert(list != NULL);
    
    //create
    struct Link *newLink;
    newLink = createLink(value);
    assert(newLink != NULL);
    
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
    
    assert (! circularListIsEmpty(list));
    
    //hold the link *
    struct Link *temp;
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
	struct CircularList *list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/*****************************************************************************************
 * Deallocates every link in the list and frees the list pointer.
 ****************************************************************************************/
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
    
    while (!circularListIsEmpty(list))
    {
        removeLink(list, list->sentinel->next);
    }
    free(list->sentinel);
    free(list);
}

/*****************************************************************************************
 * Adds a new link with the given value to the front of the deque.
 ****************************************************************************************/
void circularListAddFront(struct CircularList *list, TYPE value)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    addLinkAfter(list, list->sentinel, value);
}

/*****************************************************************************************
 * Adds a new link with the given value to the back of the deque.
 ****************************************************************************************/
void circularListAddBack(struct CircularList *list, TYPE value)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    //if (circularListIsEmpty(list))
    //    addLinkAfter(list, list->sentinel, value);
   // else
        addLinkAfter(list, list->sentinel->prev, value);
    
}

/*****************************************************************************************
 * Returns the value of the link at the front of the deque.
 ****************************************************************************************/
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
    
    assert(! circularListIsEmpty(list));
    return list->sentinel->next->value;
}

/*****************************************************************************************
 * Returns the value of the link at the back of the deque.
 ****************************************************************************************/
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this

    assert(! circularListIsEmpty(list));
    return list->sentinel->prev->value;
}

/*****************************************************************************************
 * Removes the link at the front of the deque.
 ****************************************************************************************/
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
    
    assert (! circularListIsEmpty(list));
    removeLink(list, list->sentinel->next);
}

/*****************************************************************************************
 * Removes the link at the back of the deque.
 ****************************************************************************************/
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
    
    assert (! circularListIsEmpty(list));
    removeLink(list, list->sentinel->prev);
}

/*****************************************************************************************
 * Returns 1 if the deque is empty and 0 otherwise.
 ****************************************************************************************/
int circularListIsEmpty(struct CircularList* list)
{
    assert(list != NULL);
    
    if (list->sentinel->next == list->sentinel) {
        //printf("I'm inside the isEmpty IF statement\n");
        return 1;
    }
    else
        return 0;
}

/*****************************************************************************************
 * Prints the values of the links in the deque from front to back.
 ****************************************************************************************/
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    int l = 0;
    struct Link *link;
    link = list->sentinel->next;
    
    while (link != list->sentinel) {
        printf("%f ", link->value);
        link = link->next;
        l++;
        if (l >= 8) {
            printf("\n");
            l = 0;
        }
    }
    printf("\n");
    
    /*
     int i;
     for (i = 0; i < list->size; i++) {
        printf("value %d = %d\n", i+1, link->value);
        link = link->next;
    }
    printf("\n"); 
     */

}

/*****************************************************************************************
 * Reverses the deque.
 ****************************************************************************************/
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    /* THREE WAYS:
    1: access the datamembers and switch them, then move on to the middle (until size/2?)
    */
        int i;
        struct Link *front;
        struct Link *back;
        TYPE temp;
        int s = list->size/2;
        front = list->sentinel->next;
        back = list->sentinel->prev;
        for (i = 0; i < s; i++) {
            temp = front->value;
            front->value = back->value;
            back->value = temp;
            front = front->next;
            back = back->prev;
        }
    /*
     2: call removefront and addback size # of times? DIDN'T WORK
        int i;
        for(i = 0; i <list->size; i++) {
            circularListAddFront(list, list->sentinel->prev->value);
            circularListRemoveBack(list);
        
        }
    *//*
    3: mess with the sentinel??:  WHAT A MESS
        struct Link *newSentinel = malloc(sizeof(struct Link));
        newSentinel->next = list->sentinel->prev;
        newSentinel->prev = list->sentinel->next;
        list->sentinel->next->prev = newSentinel;
        list->sentinel->prev->next = newSentinel;
        free(list->sentinel);
        list->sentinel = newSentinel;
    */
}









