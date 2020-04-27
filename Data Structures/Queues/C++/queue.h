#ifndef QUEUE_H
#define QUEUE_H


class Node {
	public:
		int data;
		Node* next;
		Node* previous;
};

void queue();

void dequeue();

void peek();

void displayQueue();

#endif
