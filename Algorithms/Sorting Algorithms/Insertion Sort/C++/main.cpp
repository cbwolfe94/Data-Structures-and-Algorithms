#include <iostream> 
#include <ostream>
#include <stdlib.h>
#include "insertion.h"

int main(int argc, char* argv[]){
	long sizeOfArray = atol(argv[1]);
	int unsortedArray[sizeOfArray];
	srand(time(NULL));

	for (int index = 0; index < sizeOfArray; index++){
		unsortedArray[index] = random() % 100;
	}
	for (int index = 0; index < sizeOfArray; index++){
		std::cout << unsortedArray[index] << " ";
	}
	std::cout << std::endl;

	sortArray(unsortedArray, sizeOfArray);
}
