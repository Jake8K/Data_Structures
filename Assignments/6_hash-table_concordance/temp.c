/*
 * CS 261 Data Structures
 * Assignment 6
 * Name:
 * Date:
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


/*****************************************************************************************
 * HashString
 * receives a string
 * returns a numeric hash value for string
 * HashFunction Credit:
 * http://stackoverflow.com/questions/7700400/whats-a-good-hash-function-for-english-words
 ***************************************************************************************
 unsigned long hashstring(unsigned char *str) {
 unsigned long hash = 5381;
 int c;
 
 while (c = *str++) {
 hash = ((hash << 5) + hash) + c;
 }
 return hash;
 }
 //unsigned long hash = hashstring(word);
 */







/*****************************************************************************************
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * param map
 ****************************************************************************************/
void hashMapCleanUp(HashMap* map) {
    // FIXME: implement <-----------------------------------------------------------------<<<<<<<<<<<<<
    HashLink *current,
    *temp;
    for (int i = 0; i < map->capacity; i++) {
        current  = temp = map->table[i];
        while (current != NULL) {
            hashLinkDelete(temp);
            current = current->next;
            temp = current;
        }
        free(map->table[i]);
    }
    free(map->table);
}

/*****************************************************************************************
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 *
 * param map
 * param key
 * return Link value or NULL if no matching link.
 ****************************************************************************************/
int* hashMapGet(HashMap* map, const char* key) {
    // FIXME: implement  <----------------------------------------------------------------<<<<<<<<<<<<<
    assert (map != NULL);
    struct HashLink *link;
    int index = HASH_FUNCTION(key) % map->capacity;
    
    link = map->table[index];
    while (link != NULL) {
        if (strcmp(link->key, key) == 0)
            return &link->value;
        link = link->next;
    }
    return NULL;
}

/*****************************************************************************************
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 *
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 *
 * param map
 * param capacity The new number of buckets.
 ****************************************************************************************/
void resizeTable(HashMap* map, int capacity) {
    // FIXME: implement  <----------------------------------------------------------------~~~~~~~~~~~~~
    
    // Save old table
    int oldCap = map->capacity;
    HashLink ** oldTable = map->table;
    
    //create a new table
    hashMapInit(map, capacity);
    
    // Rehash old map key/value pairs to new map
    for (int i = 0; i < oldCap; i++) {
        HashLink * link = oldTable[i];
        
        while (link != NULL) {
            hashMapPut(map, link->key, link->value);
            link = link->next;
        }
    }
    
    // Free allocated data in old table
    for (int i = 0; i < oldCap; i++) {
        HashLink* link = oldTable[i];
        oldTable[i] = NULL;
        
        while (link != NULL)
        {
            HashLink* temp = link;
            link = link->next;
            hashLinkDelete(temp);
        }
        
        free(oldTable[i]);
        
    }
    free(oldTable);
    
    /*
     assert (map != NULL);
     int i,
     idx,
     newCap = capacity; //map->capacity * 2;
     
     //malloc new dynamic array of pointers to links
     HashLink **newTable = (HashLink **) malloc((newCap) * sizeof(HashLink *));
     assert(newTable != 0);
     
     for (i = 0; i < newCap; i++)
     newTable[i] = NULL;
     // or replace with: initHashTable(newTable, newSize);
     
     //copy and rehash elements
     HashLink *currentLink,
     *tempLink;
     for (i = 0; i < map->capacity; i++) {
     currentLink = map->table[i];
     while (currentLink != NULL) {
     //get new index
     idx = HASH_FUNCTION(currentLink->key) % newCap;
     if (idx < 0)
     idx += newCap;
     // add the value to new hash
     tempLink = currentLink;
     currentLink->next = newTable[idx];
     newTable[idx] = currentLink;
     
     currentLink = tempLink->next;
     }
     }
     
     //free old table, set new table, set size
     free(map->table);
     map->table = newTable;
     map->capacity = newCap;
     */
}

/*****************************************************************************************
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 *
 * param map
 * param key
 * param value
 ****************************************************************************************/
void hashMapPut(HashMap* map, const char* key, int value) {
    // FIXME: implement  <-----------------------------------------------------------------------------
    
    //resize if close to capacity
    if (hashMapTableLoad(map) > MAX_TABLE_LOAD)
        resizeTable(map, (map->capacity * 2));
    
    //index
    int index = HASH_FUNCTION(key) % map->capacity;
    if (index < 0)
        index += map->capacity;
    
    //add to hashmap
    HashLink *newLink,
    *curLink = map->table[index];
    
    if (curLink == NULL) {
        //1st link @ array[index[
        newLink = hashLinkNew(key, value, NULL);
        map->table[index] = newLink;
        map->size++;
    }
    else if (hashMapContainsKey(map, key)) {
        //add to list @array[element]
        while (curLink != NULL) {
            if (strcmp(curLink->key, key) == 0) {
                curLink->value = value;
                curLink = NULL;
            }
            curLink = curLink->next;
        }
    }
    else {
        newLink = hashLinkNew(key, value, NULL);
        map->table[index] = newLink;
        map->size++;
    }
    
    /*
     int index = HASH_FUNCTION(key) % map->capacity;
     if (index < 0)
     index += map->capacity;
     struct HashLink * newLink = map->table[index];
     
     
     if (hashMapContainsKey(map, key)) {
     while (newLink != NULL) {
     if (newLink->key == key) {
     newLink->value = value;
     newLink = NULL;
     }
     newLink = newLink->next;
     }
     }
     else {
     newLink = hashLinkNew(key, value, NULL); //...map->table[index]);
     map->table[index] = newLink;
     map->size++;
     }
     
     //CHECK FOR RESIZE with MAX_TABLE_LOAD *(or do this b4 add? <********
     if (hashMapTableLoad(map) > MAX_TABLE_LOAD)
     resizeTable(map, (map->capacity * 2));
     */
}

/*****************************************************************************************
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * param map
 * param key
 ****************************************************************************************/
void hashMapRemove(HashMap* map, const char* key) {
    // FIXME: implement  <----------------------------------------------------------------+<<<<<<<<<<<<<
    
    
    if (!hashMapContainsKey(map, key)) {
        //printf("Not in map\n");
        return;
    }
    
    int idx = HASH_FUNCTION(key) % (map->capacity);
    
    HashLink* cur = map->table[idx];
    HashLink* last = map->table[idx];
    
    if (cur == NULL) {
        //printf("No links in bucket to remove\n");
    }
    
    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            //printf("Found key/link to remove\n");
            
            if (cur == map->table[idx]) {
                //printf("Link to remove is first link\n");
                map->table[idx] = cur->next;
                hashLinkDelete(cur);
                map->size--;
                cur = 0;
            }
            else {
                last->next = cur->next;
                hashLinkDelete(cur);
                map->size--;
                cur = 0;
            }
        }
        
        else {
            last = cur;
            cur = cur->next;
        }
    }
    
    /*
     int index = HASH_FUNCTION(key) % map->capacity;
     if (index < 0)
     index += map->capacity;
     
     struct HashLink *currentLink,
     *lastLink;
     
     if (hashMapContainsKey(map, key)) {
     currentLink = map->table[index];
     lastLink = map->table[index];
     while (currentLink != NULL) {
     if (currentLink->key == key) {
     //if (strcmp(currentLink->key, key) == 0) {
     lastLink->next = currentLink->next; //unlink
     hashLinkDelete(currentLink);		//free
     currentLink = NULL;					//exitLoop
     }
     else {
     lastLink = currentLink;
     currentLink = currentLink->next;
     }
     }
     map->size--;
     }
     */
    
    /*
     if (hashMapContainsKey(map, key)) {
     currentLink = map->table[index];
     lastLink = map->table[index];
     while ((currentLink != NULL) && (currentLink->next)) {
     if (currentLink->next->key == key) {          //if (strcmp(currentLink->key, key) == 0)
     lastLink = currentLink->next;       //unlink
     currentLink->next = currentLink->next->next;
     hashLinkDelete(lastLink);		//free
     currentLink = NULL;					//exitLoop
     }
     else {
     lastLink = currentLink;
     currentLink = currentLink->next;
     }
     }
     map->size--;
     }
     */
}

/*****************************************************************************************
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 *
 * param map
 * param key
 * return 1 if the key is found, 0 otherwise.
 ****************************************************************************************/
int hashMapContainsKey(HashMap* map, const char* key) {
    // FIXME: implement  <----------------------------------------------------------------<<<<<<<<<<<<<<

     // compute hash value to find the correct bucket
     int index = HASH_FUNCTION(key) % map->capacity;
     struct HashLink *currentLink;
     
     if (index < 0)
     index += map->capacity;
     
     //traverse list and seek testE
     currentLink = map->table[index];
     while (currentLink != NULL) {
     //if (strcmp(currentLink->key, key) == 0)
     if (currentLink->key == key)
     return 1;
     currentLink = currentLink->next;
     }
     return 0;
    
}


/*****************************************************************************************
 * Returns the number of table buckets without any links.
 * param map
 * return Number of empty buckets.
 ****************************************************************************************/
int hashMapEmptyBuckets(HashMap* map) {
    // FIXME: implement  <----------------------------------------------------------------<<<<<<<<<<<<
    int i,
    count = 0;
    for (i = 0; i < map->capacity; i++) {
        if (map->table[i] == NULL)
            count++;
    }
    return count;
}

/*****************************************************************************************
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * param map
 * return Table load.
 ****************************************************************************************/
float hashMapTableLoad(HashMap* map) {
    // FIXME: implement  <----------------------------------------------------------------<<<<<<<<<<<<
    
    float size = map->size;
    float cap = map->capacity;
    
    float load = size/cap;
    return load;
}
