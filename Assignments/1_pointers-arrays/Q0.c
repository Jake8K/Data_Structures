/* CS261- Assignment 1 - Q. 0*/
/* Name: Jacob Karcz
 * Date: 9.29.2016
 * Solution description: This program helps explain pointers by displaying pointer 
 *                       values and addresses within main and a function called by main.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    /*Print the value pointed to by iptr*/
    printf("\nThis is the value pointed to by iptr: %d\n", *iptr);
     
    /*Print the address pointed to by iptr*/
    printf("\nThis is the address pointed to by iptr: %p\n", iptr);
     
    /*Print the address of iptr itself*/
    printf("\nThis is the address of iptr: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 5;
    
    /*print the address of x*/
    printf ("\nThis is the addrss of x: %p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("\nThis is the value of x: %d\n", x);
    
    return 0;
}
