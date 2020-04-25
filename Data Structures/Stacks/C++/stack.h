#ifndef STACK_H
#define STACK_H

class Node {
public:
	int data;
	Node* next;
};

void push();

void pop();

void peek();

void displayStack();

#endif
