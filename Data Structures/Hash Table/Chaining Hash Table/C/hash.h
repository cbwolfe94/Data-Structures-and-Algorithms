#ifndef HASH_H
#define HASH_H


typedef struct HashTableItem {
    char* key;
    char* value;
} HashTableItem;

typedef struct HashTable {
    HashTableItem** items;
    int size;
    int count;
} HashTable;


unsigned long hashFunction(char* str);

HashTableItem* createHashTableItem(char* key, char* value);

HashTable* createHashTable(int size);

void freeItem(HashTableItem* item);

void freeHashTable(HashTable** table);

void insertHashTable(HashTable* table, char* key, char* value);


#endif