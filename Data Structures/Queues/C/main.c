#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main() {
	int choice;
	while (1) {
		printf("Enter 1 for queue, 2 for dequeue, 3 for peek, 4 for traverse and dsiplay queue, or 5 for exit. ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				queue();
				break;

			case 2:
				dequeue();
				break;

			case 3:
				peek();
				break;

			case 4:
				displayQueue();
				break;

			case 5:
				exit(0);
		}
	}
}
