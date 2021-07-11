#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
	struct Node_t *head = NULL;
	struct Node_t *second = NULL;
	struct Node_t *third = NULL;
	struct Node_t *fourth = NULL;

	head = (struct Node_t*)malloc(sizeof(struct Node_t));
	second = (struct Node_t*)malloc(sizeof(struct Node_t));
	third = (struct Node_t*)malloc(sizeof(struct Node_t));
	fourth = (struct Node_t*)malloc(sizeof(struct Node_t));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 4;
	fourth->next = NULL;

	linked_list_traverse(head);

}
