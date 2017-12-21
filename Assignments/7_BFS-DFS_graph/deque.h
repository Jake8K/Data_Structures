#ifndef DEQUE_H
#define DEQUE_H

/*
 * CS 261 Data Structures
 * Assignment 7
 * Author: Sean Moore
 * Date: 5/17/2016
 */

typedef void* Type;
typedef struct Link Link;
typedef struct Deque Deque;

struct Link {
    Type value;
    Link* next;
    Link* prev;
};

struct Deque {
    int size;
    Link* sentinel;
};

Deque* dequeNew();
void dequeDelete(Deque* deque);
void dequePushFront(Deque* deque, Type value); //push
void dequePushBack(Deque* deque, Type value);  //enqueue
Type dequeFront(Deque* deque);                  //top
Type dequeBack(Deque* deque);                   //peek?
void dequePopFront(Deque* deque);               //pop
void dequePopBack(Deque* deque);                //dequeue
int dequeIsEmpty(Deque* deque);
void dequeClear(Deque* deque);

#endif

