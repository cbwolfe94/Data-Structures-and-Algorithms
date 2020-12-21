#include <stdio.h>
#include "hash.h"
#define CAPACITY 50000


int main() {
    HashTable* table = createHashTable(CAPACITY);
    insertHashTable(table, "Conner", "300-96-4190");
    insertHashTable(table, "2", "Second Address");
    insertHashTable(table, "3", "Third Address");
    insertHashTable(table, "4", "Fourth Address");



    printSearchValue(table, "Conner");

    printf("\n");
    printHashTable(table);
    //Make sure to free memory allocated above
    freeHashTable(table);

    return 0;  
}
