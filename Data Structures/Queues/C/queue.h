#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* previous;
} Node;

void queue();

void dequeue();

void peek();

void displayQueue();

#endif
