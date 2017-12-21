//
//  main.c
//  Assignmnet 0
//
//  Created by Jacob Karcz on 9/29/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

/***************************************************************************************
 ** Program Filename:
 ** Author: Jacob Karcz
 ** Date: 09.29.2016
 ** Description: A program that converts inches to centimeters and vice-versa
 ** Input: numeric choice and measurement to convert
 ** Output: measure conversion
 ***************************************************************************************/

#include <stdio.h>
#include "main.h"

/*****************************************************************************************
 ** Function: main
 ** Description: prompt user for conversion from inches to centimeters or vice-versa until
 **              they choose to exit the program. Program is a switch statement nested in
 **              a do-while loop.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0 if no errors
 ****************************************************************************************/

int main() {
    
    float in, cm;
    int choice;
    int exit = 0;

    do {
        printf("Enter:\n\t1 to convert from inches to centimeters\n");
        printf("\t2 to convert centimeters to inches\n\t3 to exit the program\n\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        printf("\n\n");
        //printf("%d", choice); IT KNOWS THE DAMN CHOICE
        
        switch(choice) {
            case 1: // inches to centimeters
                printf("Enter a number in inches:\n");
                scanf("%f", &in);
                cm = in * 2.54;
                printf("\n%f inches is equal to %f centimeters.\n\n\n", in, cm);
                break;
                
            case 2: // centimeters to inches
                printf("Enter a number in centimeters:\n");
                scanf("%f", &cm);
                in = cm * 0.39;
                printf("\n%f centimeters is equal to %f inches.\n\n\n", cm, in);
                break;
                
            case 3: // exit
                exit = 1;
                break;
            default:
               // if (exit == 0)
               //     printf("\nPlease choose a valid option.\n");
                break;
        }
        getchar();
    } while (exit == 0);


/*prompt user for inches or centimeters*/

/*prompt user for number to convert*/

/*prompt user to convert more or quit*/
    
    return 0;
}
