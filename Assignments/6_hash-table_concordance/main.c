/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
 * CS 261 Data Structures
 * Assignment 6
 * Name: Jacob Karcz
 * Date: 11.18.2016
 *\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|*/

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);
    
    clock_t timer = clock();
    
    //FILE* file = fopen("dictionary.txt", "r");
    
    HashMap* map = hashMapNew(10);
    
    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here. <--------------------------------------
    
    FILE *filePtr;
    filePtr = fopen(fileName, "r"); //"r" == read
    if (filePtr == NULL) {
        printf("could not open file\n\n");
        return 0;
    }
    

    char *word;
    int count;

    //tally up the words
    word = nextWord(filePtr);
    while (word != NULL) {
        if (hashMapContainsKey(map, word)) {
            count = *(hashMapGet(map, word)) + 1;
            hashMapPut(map, word, count);
        }
        else {
            hashMapPut(map, word, 1);
        }
        free(word);
        word = nextWord(filePtr);
    }
    fclose(filePtr);
    
    //print occurrences
    HashLink *travLink;
    for (int i = 0; i < map->capacity; i++) {
        travLink = map->table[i];
        if (travLink != NULL) {
            while (travLink != NULL) {
                printf ("%s: %d \n", travLink->key, travLink->value);
                travLink = travLink->next;
            }
        }
    }
    
    
    // --- Concordance code ends here ---
    
    hashMapPrint(map);
    
    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
    hashMapDelete(map);
    return 0;
}
