#ifndef HASH_H
#define HASH_H

typedef struct {
    char* key;
    char* value;
} Hash_Table_Item_t;

typedef struct {
    struct HashTableItem **items;
    //For collision handling
    struct Node **overflowBuckets;
    int size;
    int count;
} Hash_Table_t;

typedef struct {
    struct HashTableItem *item;
    struct Node *next;
} Node_t;

Hash_Table_Item_t *item_create(char *key, char *value);

void item_free(Hash_Table_Item_t *item);

Hash_Table_t *hash_table_create(int size);

void hash_table_insert(Hash_Table_t *table, char *key, char *value);

char *hash_table_search(Hash_Table_t *table, char *key);

void hash_table_print(Hash_Table_t *table);

void hash_table_free(Hash_Table_t *table);

unsigned long hash_function(char *str, Hash_Table_t *table);

//void handleCollision();

void search_value_print(Hash_Table_t *table, char *key);

Node_t *node_create();

Node_t *linked_list_insert(Node_t *list, Hash_Table_Item_t *item);

void node_remove(Node_t *list);

void linked_list_free(Node_t *list);

#endif