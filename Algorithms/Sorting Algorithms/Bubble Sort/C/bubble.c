#include <stdio.h> 
#include "bubble.h"

void sortArray(int* unsortedArray, long sizeOfArray){

	//int max = *unsortedArray;
	for(int index = 0; index < sizeOfArray; index++){
		for(int index = 0; index < sizeOfArray - 1; index++){
			if(unsortedArray[index] > unsortedArray[index + 1]){
				int temp = unsortedArray[index];
				unsortedArray[index] = unsortedArray[index + 1];
				unsortedArray[index + 1] = temp;
			}
		}
	}
	printf("\n");
	for(int index= 0; index < sizeOfArray; index++){
		printf("%i ", unsortedArray[index]);
		}
}
