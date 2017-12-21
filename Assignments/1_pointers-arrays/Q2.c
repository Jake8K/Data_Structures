/* CS261- Assignment 1 - Q.2*/
/* Name: Jacob Karcz
 * Date: 9.29.2016
 * Solution description: This program demonstrates the pitfalls of passing by value. First
 *                       3 integers are generated, then they are passed to a function for
 *                       manipulation, however, the third (z/c) is passed by value, and 
 *                       not by reference as the first 2 (x, y/a, b). So the manipulated 
 *                       value of z/c is not saved by the program.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    
    /*Set b to half its original value*/
    *b/= 2;
    
    /*Assign a+b to c*/
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x, y, z;
    x = 5;
    y = 6;
    z = 7;
    
    /*Print the values of x, y and z*/
    printf("\nx = %d, y = %d, and z = %d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    //foo(&x, &y, z);
    int c = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    //printf("\nThe value returned by foo() is %d.\n", foo(&x, &y, z));
    printf("\nThe value returned by foo() is %d.\n", c);
    
    /*Print the values of x, y and z again*/
    printf("\nNow x = %d, y = %d, and z = %d\n\n", x, y, z);
    
 
    /*Is the return value different than the value of z?  Why?*/
    printf("\nThe value returned by foo is different than the final value of z because \n");
    printf("z was passed by value and not by reference, so it's modification within the \n");
    printf("foo function was lost once c went out of scope.\n\n");
    return 0;
}
    
    
