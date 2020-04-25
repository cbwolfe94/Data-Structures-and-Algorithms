#include <iostream>
#include <cstddef>
#include <ostream>
#include "stack.h"

Node* topNode = NULL;

void push() {
	int data;
	Node* temp = new Node;

	std::cout << "Enter data to add to the stack: ";
	std::cin >> data;

	temp->data = data;
	temp->next = topNode;
	topNode = temp;
}

void pop() {
	Node* temp;
	temp = topNode;
	topNode = topNode->next;
	delete temp;
}

void peek() {
	std::cout << "Data at the top of the stack is: " << topNode->data << std::endl;
}

void displayStack() {
	Node* temp;
	temp = topNode;

	while (temp != NULL) {
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}
