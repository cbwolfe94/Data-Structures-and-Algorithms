#include "binary_tree.h"


int main(void)
{

    struct binary_tree_t *tree = bt_create(10);
    bt_insert(tree->head_node, 9);
    bt_insert(tree->head_node, 11);
    bt_display(tree->head_node);
    return 0;
}