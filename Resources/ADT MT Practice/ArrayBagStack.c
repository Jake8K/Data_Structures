//
//  ArrayBagStack.c
//  CS261 MT ADT Practice
//
//  Created by Jacob Karcz on 10/19/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include "ArrayBagStack.h"
#include <assert.h>


void initArray(struct arrayBagStack * b) {
    
    assert(b != 0);
    //malloc is only for initializing a pointer of something (ie dynamic array)
    b->count = 0;
    
}


void addArray (struct arrayBagStack * b, TYPE v) {
    
    assert(b != 0);
    
    b->data[b->count] = v;
    b->count++;
    
}

//returns 1 if item is in array, 0 if not
int containsArray (struct arrayBagStack * b, TYPE v) {
    
    assert (b != 0);
    
    int i;
    for(i = 0; i < b->count; i++) {
        if (b->data[i] == b->data[b->count]) {
            return 1;
        }
    }
    return 0;
    
}


void removeArray (struct arrayBagStack * b, TYPE v) {
    assert(b != 0);
    
    int i, j;
    for(i = 0; i < b->count; i++) {
        if (b->data[i] == b->data[b->count]) {
            for (j = i; j < b->count; j++) {
                //TYPE temp = b->data[j];
                b->data[j] = b->data[j+1];
            }
        }
    }
    b->count--;
    
}

int sizeArray (struct arrayBagStack * b) {
    
    assert(b != 0);
    
    return b->count;
    
}


//stack
void pushArray (struct arrayBagStack * b, TYPE v) {
    
    assert(b != 0);
    
    addArray(b, v);
    
}

TYPE topArray (struct arrayBagStack * b) {
    
    assert(b != 0);
    
    assert(! isEmptyArray(b));
    
    return b->data[b->count -1];

    
}

void popArray (struct arrayBagStack * b) {
    
    assert(b != 0);
    
    if (b->count != 0)
        removeArray(b, b->data[b->count-1]);
    
}

int isEmptyArray (struct arrayBagStack * b){
    
    assert(b != 0);
    
    if (b->count == 0)
        return 1;
    else
        return 0;

}
