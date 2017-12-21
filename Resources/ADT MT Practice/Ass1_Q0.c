//
//  Ass1_Q0.c
//  CS261 MT ADT Practice
//
//  Created by Jacob Karcz on 10/19/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    /*Print the value pointed to by iptr*/
    printf("in fooA, the value pointed to by iptr is %d", *iptr);
    printf("\n");
    
    /*Print the address pointed to by iptr*/
    printf("in fooA, the address pointed to by iptr is %p", iptr);
    printf("\n");

    /*Print the address of iptr itself*/
    printf("in fooA, the address of iptr is %p", &iptr);
    printf("\n");

}

int main(){
    
    /*declare an integer x*/
    int x = 10;
    
    /*print the address of x*/
    printf("the address of x is %p", &x);
    printf("\n");

    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("the value of x is %d", x);
    printf("\n");
    
    return 0;
}

