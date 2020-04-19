#include <iostream>
#include "linkedlist.h"

void traverse(Node* node) {
	while (node != NULL) {
		std::cout << node->data << " ";
		node = node->next;
	}
	return;
}
