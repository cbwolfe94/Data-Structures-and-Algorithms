#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Node_t *top_node = NULL;

void push()
{
	int data;
	Node_t *temp;
	temp = (Node_t*)malloc(sizeof(Node_t));
	
	printf("Enter data to add to the stack: ");
	scanf("%d", &data);
	temp->data = data;
	temp->next = top_node;
	top_node = temp;
}

void pop()
{
	Node_t *temp;
	temp = top_node;
	top_node = top_node->next;
	free(temp);
}

void peek()
{
	printf("Data at the top of the stack is: %i\n", top_node->data);
}

void stack_display()
{
	Node_t *temp;
	temp = top_node;

	while (temp != NULL) {
		printf("%i\n", temp->data);
		temp = temp->next;
	}
}
