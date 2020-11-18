#ifndef HASH_H
#define HASH_H


typedef struct Node {
    char* key;
    char* value;
} Node;

typedef struct HashTable {
    Node** Node;
    int size;
    int count;
} HashTable;

#endif