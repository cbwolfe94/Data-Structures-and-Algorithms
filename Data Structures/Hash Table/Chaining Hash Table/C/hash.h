#ifndef HASH_H
#define HASH_H


typedef struct HashTableItem HashTableItem;

typedef struct HashTable HashTable;

typedef struct Node Node;

unsigned long hashFunction(char* str, HashTable* table);

HashTableItem* createHashTableItem(char* key, char* value);

HashTable* createHashTable(int size);

void freeItem(HashTableItem* item);

void freeHashTable(HashTable* table);

void insertHashTable(HashTable* table, char* key, char* value);

//void handleCollision();

char* hashTableSearch(HashTable* table, char* key);

void printSearchValue(HashTable* table, char* key);

void printHashTable(HashTable* table);

Node* createNode();

#endif