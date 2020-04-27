#include <iostream>
#include "queue.h"

int main() {
	int choice;
	while (1) {
		std::cout << "Enter 1 for queue, 2 for dequeue, 3 for peek, 4 for traverse and display queue, of 5 for exit. ";
		std::cin >> choice;	
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
