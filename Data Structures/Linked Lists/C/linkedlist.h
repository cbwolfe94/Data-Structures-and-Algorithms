#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node_t {
	int data;
	struct Node* next;
};

void linked_list_traverse(struct Node_t *node);

#endif
