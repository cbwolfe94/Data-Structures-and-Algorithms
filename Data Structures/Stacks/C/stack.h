#ifndef STACK_H
#define STACK_H

typedef struct {
	int data;
	Node_t *next;
} Node_t;

void push();

void pop();

void peek();

void displayStack();

#endif
