#include <stddef.h>
#include "linkedlist.h"

int main() {
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	Node* fourth = NULL;

	head = new Node;
	second = new Node;
	third = new Node;
	fourth = new Node;

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 4;
	fourth->next = NULL;
	
	traverse(head);

	return 0;
}
