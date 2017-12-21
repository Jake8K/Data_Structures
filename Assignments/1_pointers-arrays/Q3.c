/* CS261- Assignment 1 - Q.3*/
/* Name: Jacob Karcz
 * Date: 9.29.2016
 * Solution description: This program generates a dynamic array, populates it with n (20) 
 *                       randomly generated integers, and then uses the bubblesort 
 *                       algorithm to organize the array in ascending order. It prints 
 *                       the unsorted and sorted versions of the array to screen.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int j, k;
    /* bubbleSort algorithm from CS162 */
    for (int j = (n-1); j >= 0; j--) {
        for (int k = 1; k <= j; k++) {
            if (number[k-1] > number[k]) {
                int temp = number[k-1];
                number[k-1] = number[k];
                number[k] = temp;
            }
        }
    }
    
}


int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *intArray;
    intArray = (int *) malloc(sizeof(int) * n);

    
    /*Fill this array with random numbers, using rand().*/
    int i;
    for (int i = 0; i < n; i++) {
        intArray[i] = (rand() % 180) + 1;
    }
    
    /*Print the contents of the array.*/
    printf("\nThe [unsorted] array contents are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", intArray[i]);
    }
    printf("\n\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(intArray, n);
    
    /*Print the contents of the array.*/
    printf("\nThe [sorted] array contents are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", intArray[i]);
    }
    printf("\n\n");
    
    return 0;
}
