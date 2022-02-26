#include "binary_search_tree.h"


int main(void)
{

    struct binary_search_tree_t *tree = bst_create(10);
    bst_insert(tree->head_node, 9);
    bst_insert(tree->head_node, 11);
    bst_display(tree->head_node);
    return 0;
}