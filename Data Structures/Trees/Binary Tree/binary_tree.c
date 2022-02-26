#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"


struct binary_tree_t *bt_create(int value)
{
    struct binary_tree_t *new_tree = (struct binary_tree_t*)malloc(sizeof(struct binary_tree_t));
    struct node_t *new_node = (struct node_t*)malloc(sizeof(struct node_t)); 
    
    new_tree->head_node = new_node;
    new_tree->head_node->parent = NULL;
    new_tree->head_node->left_child = NULL;
    new_tree->head_node->right_child = NULL;
    new_tree->head_node->value = value;

    return new_tree;
}

void bt_insert(struct node_t *node, int value)
{
    struct node_t *current_node = node;

    //If value of new node is greater than current value of node
    if (value > current_node->value) {
        //If value does not exist at new node, then allocate memory of new node, then put new node as 
        //right child of current node. Parent of new node is current node.
        if (current_node->right_child == NULL) {
            struct node_t *new_node = (struct node_t*)malloc(sizeof(struct node_t));
            new_node->value = value;
            new_node->left_child = NULL;
            new_node->right_child = NULL;
            new_node->parent = current_node;
            current_node->right_child = new_node;
            return;
        }
        //If a value does exist 
        else {
            bt_insert(current_node, value);
        }
        
    }

    //If value of new node is less than current value of node
    if (value < current_node->value) {
        //If value does not exist at new node, then allocate memory of new node, then put new node as 
        //left child of current node. Parent of new node is current node.
        if (current_node->left_child == NULL) {
            struct node_t *new_node = (struct node_t*)malloc(sizeof(struct node_t));
            new_node->value = value;
            new_node->left_child = NULL;
            new_node->right_child = NULL;
            new_node->parent = current_node;
            current_node->left_child = new_node;
            return;
        }
        //If a value does exist 
        else {
            bt_insert(current_node, value);
        }
        
    }
    
    else {
        printf("Node already in tree\n");
        return;
    }
}

void bt_display(struct node_t *node)
{
    struct node_t *curent_node = node;

    printf("Node value: %d\n", curent_node->value);

    if (curent_node->left_child != NULL) {
        printf("Left child: %d\n", curent_node->left_child->value);
    }

    if (curent_node->right_child != NULL) {
        printf("Right child: %d\n", curent_node->right_child->value);
    }

    printf("\n\n");
}