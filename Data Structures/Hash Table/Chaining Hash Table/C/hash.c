#include "hash.h"


Node* createHashTableNode(char* key, char* value) {
    //allocate memory for node and node members
    Node* node = (char*)malloc(sizeof(Node));
    node->key = (char*)malloc(sizeof(strlen(key) + 1));
    node->value = (char*)malloc(sizeof(strlen(value) + 1));
    //copy parameters into members of node
    strcpy(node->key, key);
    strcpy(node->value, value);

    return node;   
}
HashTable* createHashTable(int size){
    HashTable* table = (HashTable*)(malloc(sizeof(HashTable));
    return table;
}
