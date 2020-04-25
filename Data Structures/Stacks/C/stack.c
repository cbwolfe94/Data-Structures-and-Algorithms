#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Node* topNode = NULL;


void push() {
	int data;
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	
	printf("Enter data to add to the stack: ");
	scanf("%d", &data);

	temp->data = data;
	temp->next = topNode;
	topNode = temp;
}

void pop() {
	Node* temp;
	temp = topNode;
	topNode = topNode->next;
	free(temp);
}

void peek() {
	printf("Data at the top of the stack is: %i\n", topNode->data);
}

void displayStack() {
	Node* temp;
	temp = topNode;

	while (temp != NULL) {
		printf("%i\n", temp->data);
		temp = temp->next;
	}

}
