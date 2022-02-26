#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct node_t {
    struct node_t *left_child;
    struct node_t *right_child;
    struct node_t *parent;
    int value;
};

struct binary_tree_t {
    struct node_t *head_node;
};

struct binary_tree_t *bt_create(int value);

void bt_insert(struct node_t *node, int value);

void bt_display(struct node_t *tree);

void bt_delete(struct binary_tree_t *tree);

#endif