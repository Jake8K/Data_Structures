/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
 * CS 261 Data Structures
 * Assignment 6
 * Name: Jacob Karcz
 * Date: 11.18.2016
 *\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|/|\|/\|*/

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*****************************************************************************************
 * HashFunction2, takes a word (string) and retuns an int hash value of the word (key)
 * param string
 * returns int
 ****************************************************************************************/
int hashFunctionz(const char* key) {
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        r += (i + 1) * key[i];
    }
    return r;
}

/*****************************************************************************************
 * Loads the contents of the file into the hash map.
 * param file
 * param map
 ****************************************************************************************/
void loadDictionary(FILE* file, HashMap* map) {
    // FIXME: implement <-------------------------------------------------------------------------------

    char * word = nextWord(file);
    int hash;
    
    while (word != NULL) {
        
        //compute hash value
        hash = hashFunctionz(word);
        
        if (hashMapContainsKey(map, word)) {
            //word is already in hashMap "dictionary"
        }
        else {
            //add word to hashMap
            hashMapPut(map, word, hash);
        }
        free(word);
        word = nextWord(file);
    }
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
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here.. <----------------------------------------------------
        if (hashMapContainsKey(map, inputBuffer)) {
            printf("%s is spelled correctly\n\n", inputBuffer);
        }
        else if (! hashMapContainsKey(map, inputBuffer)) {
            printf("%s is either incorrect or not in the dictionary.\n\n", inputBuffer);
        }
        
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
    }
    
    hashMapDelete(map);
    return 0;
}
