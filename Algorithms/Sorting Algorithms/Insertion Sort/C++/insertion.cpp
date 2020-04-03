#include <iostream> 
#include "insertion.h"

void sortArray(int* unsortedArray, long sizeOfArray){
	int decrement, element, index;

	for (index = 1; index < sizeOfArray; index++){
		element = unsortedArray[index];
		decrement = index - 1;

		while (decrement >= 0 && unsortedArray[decrement] > element){
			unsortedArray[decrement + 1] = unsortedArray[decrement];
			decrement--;
		}
		unsortedArray[decrement + 1] = element;
	}
	for (int index = 0; index < sizeOfArray; index++){
		std::cout << unsortedArray[index] << " ";
	}
}
