#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"

int main(int argc, char* argv[]){
	long sizeOfArray = atol(argv[1]);
	int unsortedArray[sizeOfArray];
	srand(time(NULL));

	for (int index = 0; index < sizeOfArray; index++){
		unsortedArray[index] = rand() % 100;
	}
	for (int index = 0; index < sizeOfArray; index++){
		printf("%i ", unsortedArray[index]);
	}
	mergeSort(unsortedArray, 0, sizeOfArray - 1);
	printf("\n");
	for (int index = 0; index < sizeOfArray; index++){
		printf("%i ", unsortedArray[index]);
	}
}
