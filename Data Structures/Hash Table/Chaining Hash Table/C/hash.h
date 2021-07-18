#ifndef HASH_H
#define HASH_H

typedef struct Hash_Table_Item_t Hash_Table_Item_t;
typedef struct Hash_Table_t Hash_Table_t;
typedef struct Node_t Node_t;

struct Hash_Table_Item_t{
    char* key;
    char* value;
};

struct Node_t{
    Hash_Table_Item_t *item;
    struct Node_t *next;
};

struct Hash_Table_t{
    Hash_Table_Item_t **items;
    //For collision handling
    Node_t **overflow_buckets;
    int size;
    int count;
};


Hash_Table_Item_t *item_create(char *key, char *value);

void item_free(Hash_Table_Item_t *item);

Hash_Table_t *hash_table_create(int size);

void hash_table_insert(Hash_Table_t *table, char *key, char *value);

char *hash_table_search(Hash_Table_t *table, char *key);

void hash_table_print(Hash_Table_t *table);

void hash_table_delete(Hash_Table_t *table, char *key);

void hash_table_free(Hash_Table_t *table);

unsigned long hash_function(char *str, Hash_Table_t *table);

void handle_collision(Hash_Table_t *table, unsigned long index, Hash_Table_Item_t *item);

void search_value_print(Hash_Table_t *table, char *key);

Node_t *node_create(void);

Node_t *linked_list_insert(Node_t *list, Hash_Table_Item_t *item);

Node_t **overflow_buckets_create(Hash_Table_t *table);

void overflow_buckets_free(Hash_Table_t *table);

void node_remove(Node_t *list);

void linked_list_free(Node_t *list);

#endif