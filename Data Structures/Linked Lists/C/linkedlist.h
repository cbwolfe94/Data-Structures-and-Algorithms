#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct Node{
	int data;
	struct Node* next;
} Node;

void traverse(Node*);

#endif
