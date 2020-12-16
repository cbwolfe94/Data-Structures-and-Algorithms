#include "hash.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long hashFunction(char* str, HashTable* table) {
    unsigned long i = 0;

    //Adds up all the ASCII values of the string, then mods it with CAPACITY, defined above
    for (int j = 0; str[j]; j++) {
        i += str[j];
    }
    //Return the hash
    return i % table->size;
}

HashTableItem* createHashTableItem(char* key, char* value) {
    //allocate memory for hashTableItem
    HashTableItem* item = (HashTableItem*)malloc(sizeof(HashTableItem));
    //allocate memory for hashTableItem members
    item->key = (char*)malloc(sizeof(strlen(key) + 1));
    item->value = (char*)malloc(sizeof(strlen(value) + 1));
    //copy parameters into members of node
    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;   
}
HashTable* createHashTable(int size){
    //Allocate memory for hash table
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    //Create an array of HashTableItem pointers and initialize them to 0 with calloc
    table->items = (HashTableItem**)calloc(table->size, sizeof(HashTableItem*));
    for (int i = 0; i < table->size; i++) {
        table->items[i] = NULL;
    }
    return table;
}

void freeItem(HashTableItem* item) {
    //Deallocate the memory allocated earlier, deallocate HashTableItem members, then deallocate the address associated with HashTableItem
    free(item->key);
    free(item->value);
    free(item);
}

void freeHashTable(HashTable* table) {
    //Create a temporary item variable, to allow us to know the addrees of the item, so we can free the item
    for (int i = 0; i < table->size; i++) {
        HashTableItem* item = table->items[i];
        if (item != NULL) {
            freeItem(item);
        }
    }
    free(table->items);
    free(table);
}

void insertHashTable(HashTable* table, char* key, char* value) {
    //Create the item based on the function parameter
    HashTableItem* item = createHashTableItem(key, value);
    //Using the hash function, find where in the hash table the item is to be inserted
    int index = hashFunction(key, table);
    //Create variable that stores the address of an item in the hash table at index
    HashTableItem* currentItem = table->items[index];

    //If currentItem is NULL, then the key does not exist, and we can proceed
    if (currentItem == NULL) {
        //Edge case
        if (table->count == table->size) {
            printf("Can't insert. Hash Table is full.\n");
            freeItem(item);
            return;
        }
        
        //If the hash table isn't full, then insert item into the list of items in table, then
        //update the current count of items in the hash table
        table->items[index] = item;
        table->count++;
    }
    //
    else {
      //If the same item was already inserted before, then update the value
        if (strcmp(currentItem->key, key) == 0) {
            strcpy(table->items[index]->value, value);
        }

        /* else {
            handleCollision(table, item);
            return;
        } */
  }
}

//void handleCollision();

char* hashTableSearch(HashTable* table, char* key) {
    //Find the location of the item in the hash table
    int index = hashFunction(key, table);

    //Create a HashTableItem so we can look at it
    HashTableItem* item = table->items[index];

    //If something exists at items address, then we can proceed
    if (item != NULL) {
        //Make sure the key is the correct key, then return the value at associated with that key
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
    }
    //If there is nothing there then return NULL
    return NULL;
}

void printSearchValue(HashTable* table, char* key) {
    
    char* value = hashTableSearch(table, key);

    if (value == NULL) {
        printf("Key %s does not exist in the table\n", key);
    }
    else {
        printf("Key: %s, Value: %s", key, value);
    }
}

void printHashTable(HashTable* table) {
    printf("------HASH TABLE------"); 

    for (int i= 0; i < table->size; i++) {
        if (table->items[i]) {
            printf("Index: %d, Key: %s, Value: %s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }

    printf("----------------------\n\n");
}