#ifndef STACK_H
#define STACK_H

typedef struct Node {
	int data;
	struct Node* next;
} Node;


void push();

void pop();

void peek();

void displayStack();

#endif
