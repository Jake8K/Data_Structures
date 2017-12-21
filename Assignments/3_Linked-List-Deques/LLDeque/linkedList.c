/* CS261- Assignment 3 - linkedList.c */
/* Name: Jacob Karcz
 * Date: 10.12.2016
 * Solution description: Linked List function implementation file to use in
 *                       bag and deque ADTs
 */

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/*****************************************************************************************
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL as appropriate.
 ****************************************************************************************/
static void init(struct LinkedList* list) {
	// FIXME: you must write this
    assert(list != NULL);
    
    //malloc
    list->frontSentinel = malloc(sizeof(struct Link));
    assert(list->frontSentinel != NULL);
    list->backSentinel = malloc(sizeof(struct Link));
    assert(list->backSentinel != NULL);
    
    //members
    list->size = 0;
    list->frontSentinel->next = list->backSentinel;
    list->backSentinel->prev = list->frontSentinel;
}

/*****************************************************************************************
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 ****************************************************************************************/
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    assert(list != NULL);

    
    //malloc link
    struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
    assert(newLink != NULL);
    
    //update links
    newLink->value = value;
    newLink->next = link;
    newLink->prev = link->prev;
    link->prev->next = newLink;
    link->prev = newLink;
    
    list->size++;
    
    
}

/*****************************************************************************************
 * Removes the given link from the list and
 * decrements the list's size.
 ****************************************************************************************/
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
    assert(list != NULL);
    assert(link != list->frontSentinel);
    assert(link != list->backSentinel);

    
    //hold onto the link to erase
    assert(! linkedListIsEmpty(list));
    struct Link *temp;
    temp = link;
    
    //unlink and erase
    link->next->prev = link->prev;
    link->prev->next = link->next;
    free(temp);
    
    list->size--;
}

/*****************************************************************************************
 * Allocates and initializes a list.
 ****************************************************************************************/
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/*****************************************************************************************
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 ****************************************************************************************/
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}





/****************************************************************************************/
/*******************************DEQUE INTERFACE FUNCTIONS********************************/
/****************************************************************************************/

/*****************************************************************************************
 * Adds a new link with the given value to the front of the deque.
 ****************************************************************************************/
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    addLinkBefore(list, list->frontSentinel->next, value);
}

/*****************************************************************************************
 * Adds a new link with the given value to the back of the deque.
 ****************************************************************************************/
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    addLinkBefore(list, list->backSentinel, value);
}

/*****************************************************************************************
 * Returns the value of the link at the front of the deque.
 ****************************************************************************************/
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
    assert (! linkedListIsEmpty(list));
    return list->frontSentinel->next->value;
}

/*****************************************************************************************
 * Returns the value of the link at the back of the deque.
 ****************************************************************************************/
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
    
    assert (! linkedListIsEmpty(list));
    return list->backSentinel->prev->value;
}

/*****************************************************************************************
 * Removes the link at the front of the deque.
 ****************************************************************************************/
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
    
    assert(! linkedListIsEmpty(list));
    removeLink(list, list->frontSentinel->next);
}

/*****************************************************************************************
 * Removes the link at the back of the deque.
 ****************************************************************************************/
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
    
    assert(! linkedListIsEmpty(list));
    removeLink(list, list->backSentinel->prev);
}

/*****************************************************************************************
 * Returns 1 if the deque is empty and 0 otherwise.
 ****************************************************************************************/
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    if (list->frontSentinel->next == list->backSentinel)
        return 1;
    else
        return 0;
}

/*****************************************************************************************
 * Prints the values of the links in the deque from front to back.
 ****************************************************************************************/
void linkedListPrint(struct LinkedList* list)
{
    assert(list != NULL);
    
    int i;
    struct Link *link;
    link = list->frontSentinel->next;
    
    for (i = 0; i < list->size; i++) {
        printf("value %d = %d\n", i+1, link->value);
        link = link->next;
    }
    printf("\n");
    
    /*while (link != backSentinel) {
        printf("%d ", link->value)
        link = link->next;
    }*/
    
}
           
/****************************************************************************************/
/****************************BAG INTERFACE FUNCTIONS*************************************/
/****************************************************************************************/

           
/*****************************************************************************************
 * Adds a link with the given value to the bag.
 ****************************************************************************************/
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    //malloc link
    struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
    assert(newLink != NULL);
    
    //update links
    newLink->value = value;
    newLink->next = list->backSentinel;
    newLink->prev = list->backSentinel->prev;
    list->backSentinel->prev->next = newLink;
    list->backSentinel->prev = newLink;
    
    list->size++;
    
    //printf("I added a link\n");

    
    
        
}

/*****************************************************************************************
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 ****************************************************************************************/
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    int i;
    struct Link *link;
    link = list->frontSentinel->next;
    
    for(i = 0; i < list->size; i++) {
        if(link->value == value)
            return 1;
        link = link->next;
    }
    return 0;

}

/*****************************************************************************************
 * Removes the first occurrence of a link with the given value.
 ****************************************************************************************/
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != NULL);
    
    int i;
    struct Link *link;
    link = list->frontSentinel->next;
    
    for(i = 0; i < list->size; i++) {
        if(link->value == value) {
            struct Link *temp;
            temp = link;
            
            //unlink and erase
            link->next->prev = link->prev;
            link->prev->next = link->next;
            free(temp);
            
            list->size--;
            
            return;
        }
        link = link->next;
    }

    
}
