#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void linked_list_traverse(struct Node_t *node) {
	if (node == NULL) {
		return;
	}

	else {
		printf("%i ", node->data);
		linked_list_traverse(node->next);
	}
}
