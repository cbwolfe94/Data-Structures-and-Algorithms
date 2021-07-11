#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


int main(){	
	int  choice; 
	while (1) {
		
		printf("Enter 1 for push, 2 for pop, 3 for peek, 4 for traverse and display stack, or 5 for exit. ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				push();
				break;

			case 2:
				pop();
				break;

			case 3:
				peek();
				break;

			case 4:
				displayStack();
				break;

			case 5:
				exit(0);
		}
	}
	return 0;	
}
