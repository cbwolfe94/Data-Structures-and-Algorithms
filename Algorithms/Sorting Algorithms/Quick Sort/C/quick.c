#include "quick.h"


void swap(int* firstNumber, int* secondNumber) {
	int temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}

int partition(int* unsortedArray, long low, long high) {
	int pivot = unsortedArray[high];
	int smallerElementIndex = low - 1;

	for (int index = low; index <= high - 1; index++) {
		if (unsortedArray[index] < pivot) {
			smallerElementIndex++;
			swap(&unsortedArray[smallerElementIndex], &unsortedArray[index]);
		}
	}
	swap(&unsortedArray[smallerElementIndex + 1], &unsortedArray[high]);
	return smallerElementIndex + 1;
		
}

void quickSort(int* unsortedArray, long low, long high) {
	if(low < high){
		int partitionIndex = partition(unsortedArray, low, high);
		quickSort(unsortedArray, low, partitionIndex - 1);
		quickSort(unsortedArray, partitionIndex + 1, high);
	}
}

