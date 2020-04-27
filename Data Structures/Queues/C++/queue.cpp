#include <iostream>
#include <cstddef>
#include <ostream>
#include "queue.h"

Node* topNode = NULL;
Node* bottomNode = NULL;

void queue() {
	int data;
	Node* temp = new Node;
	
	std::cout << "Enter data to add to the queue: ";
	std::cin >> data;
	
	temp->data = data;
	temp->next = topNode;

	if (topNode == NULL) {
		bottomNode = temp;
		topNode = temp;
		temp->previous = NULL;
	}
	else {
		topNode = temp;
		temp->next->previous = topNode;
	}

}

void dequeue() {
	Node* temp;
	temp = bottomNode;
	if (topNode != bottomNode) {
		bottomNode = bottomNode->previous;
		bottomNode->next = NULL;
		delete temp;
	}
	else {
		bottomNode = NULL;
		topNode = NULL;
		delete temp;
	}
}

void peek() {
	std::cout << "Data at the front of the queue is: " << bottomNode->data << std::endl;
}

void displayQueue() {
	Node* temp;
	temp = topNode;

	while (temp != NULL) {
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}


