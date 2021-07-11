#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Node_t *top_node = NULL;
Node_t *bottom_node = NULL;

void queue()
{
	int data;
	Node_t *temp;
	temp = (Node_t*)malloc(sizeof(Node_t));

	printf("Enter data to add to the queue: ");
	scanf("%d", &data);

	temp->data = data;
	temp->next = top_node;

	if (top_node == NULL) {
		bottom_node = temp;
		top_node = temp;
		temp->previous = NULL;
	}
	else {
		top_node = temp;
		temp->next->previous = top_node;	
	}
}

void dequeue()
{
	Node_t *temp;
	temp = bottom_node;

	if (top_node != bottom_node) {
		bottom_node = bottom_node->previous;
		bottom_node->next = NULL;
		free(temp);
	}
	else {
		bottom_node = NULL;
		top_node = NULL;
		free(temp);
	}
}

void peek()
{
	printf("Data at the front of the queue is: %i\n", bottom_node->data);
}

void queue_display()
{
	Node_t *temp;
	temp = top_node;

	while (temp != NULL) {
		printf("%i\n", temp->data);
		temp = temp->next;
	}
}
