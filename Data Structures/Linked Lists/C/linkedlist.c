#include <stdio.h>
#include "linkedlist.h"



void traverse(Node* node) {
	if (node == NULL) {
		return;
	}
	else {
		printf("%i->", node->data);
		traverse(node->next);		
}
}
