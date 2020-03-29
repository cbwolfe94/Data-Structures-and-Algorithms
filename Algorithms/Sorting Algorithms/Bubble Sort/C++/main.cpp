#include <iostream>
#include <stdlib.h>
#include "bubble.h"

int main(int argc, char* argv[]){
	long sizeOfArray = atol(argv[1]);
	int unsortedArray[sizeOfArray];
	srand(time(NULL));
	
	for(int index = 0; index < sizeOfArray; index++){
		unsortedArray[index] = rand() % 100;
	}
	for(int index = 0; index < sizeOfArray; index++){
		std::cout << unsortedArray[index] << " "; 
	}
	std::cout << "\n";

	sortArray(unsortedArray, sizeOfArray);
	return 0;
}	
