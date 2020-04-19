#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	Node* fourth = NULL;

	head = (Node*)malloc(sizeof(Node));
	second = (Node*)malloc(sizeof(Node));
	third = (Node*)malloc(sizeof(Node));
	fourth = (Node*)malloc(sizeof(Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 4;
	fourth->next = NULL;

	traverseLinkedList(head);

}
