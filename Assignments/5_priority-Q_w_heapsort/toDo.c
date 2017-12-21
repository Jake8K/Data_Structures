/*****************************************************************************************
 * CS 261 Assignment 5
 * Name: Jacob Karcz
 * Date: 11.07.2016
 ****************************************************************************************/

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @parameter heap
 * @parameter file
 */
void listLoad(DynamicArray* heap, FILE* file) {
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2) {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
    //correct for unsorted list loading (w/o access to adjustHeap or buildHeap)
    
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @parameter heap
 * @parameter file
 */
void listSave(DynamicArray* heap, FILE* file) {
    for (int i = 0; i < dySize(heap); i++) {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @parameter heap
 */
void listPrint(DynamicArray* heap) {
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0) {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @parameter list
 * @parameter command
 */
void handleCommand(DynamicArray* list, char command) {
    // FIXME: Implement <-----------------------------------------------------------------
    char fileName[128];
    char *newLine;
    char taskName[128];
    FILE *filePointer;
    Task* newTask;
    Task* firstTask;
    int priority;
    DynamicArray *toDoneList = list;


    switch (command) {
        case 'l': // load to-do list from a file
            printf("Enter a file name to create a To-Do list: ");
            //fgets(fileName, 128, stdin);
            //if ((filePointer = fopen(fileName, "r")) == NULL)
            //    printf("Error in fopen: Error #%i\n", errno);
            
            // get filename from user input (from keyboard)
            if (fgets(fileName, sizeof(fileName), stdin) != NULL)
            {
                // remove trailing newline character
                newLine = strchr(fileName, '\n');
                if (newLine)
                    *newLine = '\0';
            }
            // open the file
            filePointer = fopen(fileName, "r"); // "r" = read
            if (filePointer == NULL) {
                fprintf(stderr, "Cannot open %s\n", fileName);
                break;
            }
            // load the list from the file
            listLoad(toDoneList, filePointer);
            // close the file
            fclose(filePointer);
            
            //organize list
//            buildHeap(toDoneList, taskCompare);
            
            printf("To-Do list successfully loaded from file.\n\n");
            
            break;
            
        case 's': // save to-do list to a file
            if (dySize(toDoneList) > 0) {
                // get filename from user input (from keyboard)
                printf("Enter a filename to save to: ");
                if (fgets(fileName, sizeof(fileName), stdin) != NULL) {
                    // remove trailing newline character
                    newLine = strchr(fileName, '\n');
                    if (newLine)
                        *newLine = '\0';
                }
                // open the file
                filePointer = fopen(fileName, "w"); // "w" == write
                if (filePointer == NULL) {
                    fprintf(stderr, "Cannot open %s\n", fileName);
                    break;
                }
                // save the list to the file
                listSave(toDoneList, filePointer);
                // close the file
                fclose(filePointer);
                printf("To-Do list successfully saved to file.\n\n");
            }
            else
                printf("List cannot be saved, empty to-do list.\n\n");
            
            break;
            
        case 'a': // add a new task
            printf("Enter task name: ");
            // get task description from user input
            if (fgets(taskName, sizeof(taskName), stdin) != NULL) {
                // remove trailing newline character
                newLine = strchr(taskName, '\n');
                if (newLine)
                    *newLine = '\0';
            }
            do {// get task priority from user input
                printf("Enter task's priority level {0 (high) – 1000 (low)}: ");
                scanf("%d", &priority);
            } while(!(priority >= 0 && priority <= 1000));
            
            // clear the trailing newline character
            while (getchar() != '\n');
            
            // create task and add the task to the heap
            newTask = taskNew(priority, taskName);
            dyHeapAdd(toDoneList, newTask, taskCompare);
            printf("Added task: '%s'\n\n", taskName);
            
            break;
            
        case 'g': // get the first task
            if (dySize(toDoneList) > 0) {
                firstTask = (Task *)dyHeapGetMin(toDoneList);
                printf("First task is: %s\n\n", firstTask->name);
            }
            else
                printf("This list is empty.\n\n");
            
            break;
            
        case 'r': // remove the first task
            if (dySize(toDoneList) > 0) {
                firstTask = (Task *)dyHeapGetMin(toDoneList);

                //taskDelete(toDoneList->data[toDoneList->size]);
                printf("Removed first task: '%s,'\n\n", firstTask->name);
                taskDelete (dyHeapGetMin(list));
                dyHeapRemoveMin(toDoneList, taskCompare);
            }
            else
                printf("This list is already empty.\n\n");
            
            break;
            
        case 'p': //print the list
            if (dySize(toDoneList) > 0) {
                listPrint(toDoneList);
                printf("\n");
            }
            else
                printf("List is empty, nothing to print.\n\n");
            break;
            
        case 'e': //exit the program
            printf("To-do list program terminated\n\n");
            
            break;
    }
 
}

int main() {
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n\n"
               );
        
        command = getchar();
        printf("\n");
        
        // Eat newlines 
        while (getchar() != '\n');
        
        handleCommand(list, command);
        
    } while (command != 'e');
    
    while (dySize(list) > 0) {
        taskDelete (dyHeapGetMin(list));
        dyHeapRemoveMin(list, taskCompare);
    }
    
    dyDelete(list);
    
    return 0;
}
// valgrind --tool=memcheck --leak-check=yes toDo

