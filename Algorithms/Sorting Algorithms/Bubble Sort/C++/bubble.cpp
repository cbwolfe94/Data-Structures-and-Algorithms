#include <iostream>
#include "bubble.h"

void sortArray(int* unsortedArray, long sizeOfArray){

	
	for(int index = 0; index < sizeOfArray; index++){
		for(int index = 0; index < sizeOfArray; index++){
		       if (unsortedArray[index] > unsortedArray[index + 1]){
			      int  temp = unsortedArray[index];
			       unsortedArray[index] = unsortedArray[index + 1];
			       unsortedArray[index + 1] = temp;
		       }
		}
	}
	for(int index = 0; index < sizeOfArray; index++){
		std::cout << unsortedArray[index] << " ";
	}
}
