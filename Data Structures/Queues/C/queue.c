#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Node* topNode = NULL;
Node* bottomNode = NULL;
void queue() {
	int data;
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));

	printf("Enter data to add to the queue: ");
	scanf("%d", &data);

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
	bottomNode = bottomNode->previous;
	bottomNode->next = NULL;
	free(temp);
}

void peek(){
	printf("Data at the front of the queue is: %i\n", bottomNode->data);
}

void displayQueue(){
	Node* temp;
	temp = topNode;

	while (temp != NULL) {
		printf("%i\n", temp->data);
		temp = temp->next;
	}
}
