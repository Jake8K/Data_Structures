/* CS261- Assignment 1 - Q.4*/
/* Name: Jacob Karcz
 * Date: 9.29.2016
 * Solution description: Program creates a dynamic array of n sudent type structs,
 *                       generates random and unique IDs for each along with a test score,
 *                       and sorts the array in increasing order of test score. It 
 *                       displays the list before and after sorting.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int j, k;
    for (int j = (n-1); j >= 0; j--) {
        for (int k = 1; k <= j; k++) {
            if (students[k-1].score > students[k].score) {
                struct student temp = students[k-1];
                students[k-1] = students[k];
                students[k] = temp;
            }
        }
    }
    
}


int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 18;
    
    /*Allocate memory for n students using malloc.*/
    struct student *students;
    students = (struct student *) malloc (sizeof(struct student) * n);
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    int i, k;
    for(i = 0; i < n; i++) {
        students[i].id = (rand() % n) + 1;
        for (k = 0; k < i; k++) //check for unique ID
            if (students[i].id == students[k].id)
                i--; //redo student because ID was not unique
        students[i].score = (rand() % 100) + 1;
    }
    
    /*Print the contents of the array of n students.*/
    printf("\nStudent Info: \n\tID\tScore\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t%d\n", students[i].id, students[i].score);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    printf("\nStudent Info: \n\tID\tScore\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t%d\n", students[i].id, students[i].score);
    }
    printf("\n\n");
    
    return 0;
}
