#include "hash.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Hash_Table_Item_t *item_create(char *key, char *value)
{
    //allocate memory for hashTableItem
    Hash_Table_Item_t *item = malloc(sizeof(Hash_Table_Item_t));
    //allocate memory for hashTableItem members
    item->key = (char*)malloc(strlen(key) + 1);
    item->value = (char*)malloc(strlen(value) + 1);
    //copy parameters into members of node
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;   
}

void item_free(Hash_Table_Item_t *item)
{
    //Deallocate the memory allocated earlier, deallocate HashTableItem members, then deallocate the address associated with HashTableItem
    free(item->key);
    free(item->value);
    free(item);
}

Hash_Table_t *hash_table_create(int size)
{
    //Allocate memory for hash table
    Hash_Table_t *table = malloc(sizeof(Hash_Table_t));
    table->size = size;
    table->count = 0;
    //Create an array of HashTableItem pointers and initialize them to 0 with calloc
    table->items = (Hash_Table_Item_t**)calloc(table->size, sizeof(Hash_Table_Item_t*));
    for (int i = 0; i < table->size; i++) {
        table->items[i] = NULL;
    }
    table->overflow_buckets = overflow_buckets_create(table);
    return table;
}

void hash_table_insert(Hash_Table_t *table, char *key, char *value)
{
    //Create the item based on the function parameter
    Hash_Table_Item_t *item = item_create(key, value);
    //Using the hash function, find where in the hash table the item is to be inserted
    int index = hash_function(key, table);
    //Create variable that stores the address of an item in the hash table at index
    Hash_Table_Item_t *current_item = table->items[index];

    //If currentItem is NULL, then the key does not exist, and we can proceed
    if (current_item == NULL) {
        //Edge case
        if (table->count == table->size) {
            printf("Can't insert. Hash Table is full.\n");
            item_free(item);
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
        if (strcmp(current_item->key, key) == 0) {
            strcpy(table->items[index]->value, value);
        }

        else {
            handle_collision(table, index, item);
            return;
        }
  }
}

char *hash_table_search(Hash_Table_t *table, char *key)
{
    //Find the location of the item in the hash table
    int index = hash_function(key, table);

    //Create a HashTableItem so we can look at it
    Hash_Table_Item_t *item = table->items[index];
    Node_t *head = table->overflow_buckets[index];

    //If something exists at items address, then we can proceed
    while(item != NULL) {
        //Make sure the key is the correct key, then return the value at associated with that key
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        if (head == NULL) {
            return NULL;
        }
        item = head->item;
        head = head->next;
    }
    //If there is nothing there then return NULL
    return NULL;
}

void hash_table_print(Hash_Table_t *table)
{
    printf("------HASH TABLE------\n"); 

    for (int i= 0; i < table->size; i++) {
        if (table->items[i]) {
            printf("Index: %d, Key: %s, Value: %s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }

    printf("----------------------\n");
}

void hash_table_delete(Hash_Table_t *table, char *key)
{
    int index = hash_function(key, table);

    Hash_Table_Item_t *item = table->items[index];
    Node_t *head = table->overflow_buckets[index];

    if (item == NULL) {
        return;
    }

    else {
        if (head == NULL && strcmp(item->key, key) == 0) {
            table->items[index] = NULL;
            item_free(item);
            table->count--;
            return;
        }
        else if (head != NULL) {
            if (strcmp(item->key, key) == 0) {
                item_free(item);
                Node_t *node = head;
                head = head->next;
                node->next = NULL;
                table->items[index] = item_create(node->item->key, node->item->value);
                linked_list_free(node);
                table->overflow_buckets[index] = head;
                return;
            }

            Node_t *curr = head;
            Node_t *prev = NULL;

            while (curr) {
                if (strcmp(item->key, key) == 0) {
                    if (prev == NULL) {
                        linked_list_free(head);
                        table->overflow_buckets[index] = NULL;
                        return;
                        }
                    else {
                    prev->next = curr->next;
                    curr->next = NULL;
                    linked_list_free(curr);
                    table->overflow_buckets[index] = head;
                    return;
                    }
                }
            curr = curr->next;
            prev = curr;
            }
        }
    }
}

void hash_table_free(Hash_Table_t *table)
{
    //Create a temporary item variable, to allow us to know the addrees of the item, so we can free the item
    for (int i = 0; i < table->size; i++) {
        Hash_Table_Item_t *item = table->items[i];
        if (item != NULL) {
            item_free(item);
        }
    }
    overflow_buckets_free(table);
    free(table->items);
    free(table);
    
}

unsigned long hash_function(char *str, Hash_Table_t *table)
{
    unsigned long i = 0;

    //Adds up all the ASCII values of the string, then mods it with CAPACITY, defined above
    for (int j = 0; str[j]; j++) {
        i += str[j];
    }
    //Return the hash
    return i % table->size;
}

void handle_collision(Hash_Table_t *table, unsigned long index, Hash_Table_Item_t *item)
{
    Node_t *head = table->overflow_buckets[index];

    if (head == NULL) {
        head = node_create();
        head->item = item;
        table->overflow_buckets[index] = head;
    }

    else {
        table->overflow_buckets[index] = linked_list_insert(head, item);
        return;
    }
}

void search_value_print(Hash_Table_t *table, char *key)
{
    
    char *value = hash_table_search(table, key);

    if (value == NULL) {
        printf("Key %s does not exist in the table\n", key);
    }
    else {
        printf("Key: %s, Value: %s\n", key, value);
    }
}

Node_t *node_create(void)
{
    Node_t *node = (Node_t*)malloc(sizeof(Node_t));
    return node;
}

Node_t *linked_list_insert(Node_t *list, Hash_Table_Item_t *item)
{

    //Create a list if list has not been created yet
    if(!list) {
        Node_t *head_node = node_create();
        head_node->item = item;
        head_node->next = NULL;
        list = head_node;
        return list;
    }

    //If a list exists, and only a single node exists, then add a new node
    else if (list->next == NULL) {
        Node_t *node = node_create();
        node->item = item;
        node->next = NULL;
        list->next = node;
        return list;
    }

    Node_t *temp_node = list;
    
    //Traverse the linked list until the address of the next node is NULL
    while(temp_node->next->next) {
        temp_node = temp_node->next;
    }

    //Add new node to the end of the linked list
    Node_t *node = node_create();
    node->item = item;
    node->next = NULL;
    temp_node->next = node;
    return list;
}

void node_remove(Node_t *list)
{
    //If list does not exist, return NULL
   if (!list) {
        return;
    }
    //If the next node in the list is NULL, return NULL
    if (!list->next) {
        return;
    }

    Node_t *node = list->next;
    Node_t *temp = list;
    temp->next = NULL;

    list = node;

    free(temp->item->key);
    free(temp->item->value);
    free(temp->item);
    free(temp);
}

void linked_list_free(Node_t *list)
{
    Node_t *temp = list;
    //Traverse the linked list and free the memory
    while(list) {
        temp = list;
        list = list->next;
        free(temp->item->key);
        free(temp->item->value);
        free(temp->next);
        free(temp);
    }
}

Node_t **overflow_buckets_create(Hash_Table_t *table)
{
    Node_t **overflow_bucket = (Node_t**)calloc(table->size, sizeof(Node_t*));
    for (int i = 0; i < table->size; i++) {
        overflow_bucket[i] = NULL;
    }
    return overflow_bucket;
}

void overflow_buckets_free(Hash_Table_t *table)
{
    Node_t** buckets = table->overflow_buckets;   
    for (int i = 0; i < table->size; i++) {
        linked_list_free(buckets[i]);
    }
    free(buckets);
}