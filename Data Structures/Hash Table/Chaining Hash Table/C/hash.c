#include "hash.h"
#include <stddef.h>


unsigned long hashFunction(char* str) {
    unsigned long i = 0;

    for (int j = 0; j )
}
HashTableItem* createHashTableItem(char* key, char* value) {
    //allocate memory for node and node members
    HashTableItem* item = (char*)malloc(sizeof(HashTableItem));
    item->key = (char*)malloc(sizeof(strlen(key) + 1));
    item->value = (char*)malloc(sizeof(strlen(value) + 1));
    //copy parameters into members of node
    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;   
}
HashTable* createHashTable(int size){
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    //Create an array of node pointers and initialize them to 0 with calloc
    table->items = (HashTableItem**)calloc(sizeof(HashTableItem*));
    for (int i = 0; i < table->size; i++) {
        table->items[i] = NULL;
    }
    return table;
}

void freeItem(HashTableItem* item) {
    //Deallocate the memory allocated earlier, deallocate Node members, then deallocate the address associated with Node
    free(item->key);
    free(item->value);
    free(item);
}

void freeHashTable(HashTable* table) {
    //Create a temporary item variable, to allow the 
    for (int i = 0; i < table->size; i++) {
        HashTableItem* item = table->items[i];
        if (item != NULL) {
            free(item);
        }
    }
    free(table->items);
    free(table);
}

void insertHashTable(HashTable* table, char* key, char* value) {
    HashTableItem* item = createHashTableItem(key, value);


}