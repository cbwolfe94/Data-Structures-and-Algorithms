#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
	int data;
	Node_t *next;
	Node_t *previous;
} Node_t;

void queue();

void dequeue();

void peek();

void queue_display();

#endif
