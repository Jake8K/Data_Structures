//
//  ArrayBagStack.h
//  CS261 MT ADT Practice
//  WorkSheet 0
//
//  Created by Jacob Karcz on 10/19/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#ifndef ArrayBagStack_h
#define ArrayBagStack_h

# define TYPE int
# define EQ(a, b) (a == b)

struct arrayBagStack {
    TYPE data [100];
    int count;
};

void initArray(struct arrayBagStack * b);
void addArray (struct arrayBagStack * b, TYPE v);
int containsArray (struct arrayBagStack * b, TYPE v);
void removeArray (struct arrayBagStack * b, TYPE v);
int sizeArray (struct arrayBagStack * b);

void pushArray (struct arrayBagStack * b, TYPE v);
TYPE topArray (struct arrayBagStack * b);
void popArray (struct arrayBagStack * b);
int isEmptyArray (struct arrayBagStack * b);


#endif /* ArrayBagStack_h */
