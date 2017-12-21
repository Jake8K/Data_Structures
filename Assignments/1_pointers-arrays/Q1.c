/* CS261- Assignment 1 - Q.1*/
/* Name: Jacob Karcz
 * Date: 9.29.2016
 * Solution description: Program creates a dynamic array of 10 sudent type structs,
 *                       generates random and unique IDs for each along with a test score.
 *                       It then prints out the student list to the screen.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *s;
    s =(struct student *) malloc (sizeof(struct student) * 10);

     /*return the pointer*/
    return s;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, 
      ID being between 1 and 10, scores between 0 and 100*/
    int i, k;
    for(i = 0; i < 10; i++) {
        students[i].id = (rand() % 10) + 1;
        for (k = 0; k < i; k++)
            if (students[i].id == students[k].id)
                i--;
        students[i].score = (rand() % 100) + 1;
    }
    
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;
    printf("\nStudent Info: \n\tID\tScore\n");
    for (i = 0; i < 10; i++) {
        printf("\t%d\t%d\n", students[i].id, students[i].score);
    }
    printf("\n");
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i, min, max, avg, sum;
    max = sum = 0;
    min = 100;
    for (int i = 0; i < 10; i++) {
        sum += students[i].score;
        if (students[i].score < min)
            min = students[i].score;
        if (students[i].score > max)
            max = students[i].score;
    }
    avg = sum / 10;
    
    printf("The minimum student score is %d\n", min);
    printf("The maximum student score is %d\n", max);
    printf("The average student score is %d\n", avg);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free (stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
