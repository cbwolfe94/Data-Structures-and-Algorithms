#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void traverseLinkedList(Node* node) {
	if (node == NULL) {
		return;
	}

	else {
		printf("%i ", node->data);
		traverseLinkedList(node->next);
	}
}
