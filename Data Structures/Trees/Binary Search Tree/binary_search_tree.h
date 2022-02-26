#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct node_t {
    struct node_t *left_child;
    struct node_t *right_child;
    struct node_t *parent;
    int value;
};

struct binary_search_tree_t {
    struct node_t *head_node;
};

struct binary_search_tree_t *bst_create(int value);

void bst_insert(struct node_t *node, int value);

void bst_display(struct node_t *tree);

void bst_delete(struct binary_search_tree_t *tree);

#endif