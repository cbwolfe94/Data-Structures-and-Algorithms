#include <stdio.h>
#include "hash.h"
#define CAPACITY 50000


int main() {
    Hash_Table_t *table = hash_table_create(CAPACITY);
    hash_table_insert(table, "Conner", "300-96-4190");
    hash_table_insert(table, "2", "Second Address");
    hash_table_insert(table, "3", "Third Address");
    hash_table_insert(table, "4", "Fourth Address");
    search_value_print(table, "Conner");
    printf("\n");
    hash_table_print(table);
    //Make sure to free memory allocated above
    hash_table_free(table);

    return 0;  
}
