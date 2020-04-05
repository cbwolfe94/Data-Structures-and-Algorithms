#include "merge.h"

void mergeSort(int* unsortedArray, long start, long end){
	if (start < end){
		int middle = start + (end - start)/2;
		mergeSort(unsortedArray, start, middle);
		mergeSort(unsortedArray, middle + 1, end);
		merge(unsortedArray, start, middle, end);
	}
}

void merge(int* unsortedArray, long start, long middle, long end){
	int leftIndex, rightIndex, mainIndex;
	long leftArraySize = middle - start + 1;
	long rightArraySize = end - middle;

	int leftArray[leftArraySize], rightArray[rightArraySize];
	for (leftIndex = 0; leftIndex < leftArraySize; leftIndex++){
		leftArray[leftIndex] = unsortedArray[start + leftIndex];
	}
	for (rightIndex = 0; rightIndex < rightArraySize; rightIndex++){
		rightArray[rightIndex] = unsortedArray[middle + rightIndex + 1];
	}

	leftIndex = 0;
	rightIndex = 0;
	mainIndex = start;

	while (leftIndex < leftArraySize && rightIndex < rightArraySize){
		if (leftArray[leftIndex] <= rightArray[rightIndex]){
			unsortedArray[mainIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else {
			unsortedArray[mainIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		mainIndex++;
	}
	while (leftIndex < leftArraySize){
		unsortedArray[mainIndex] = leftArray[leftIndex];
		leftIndex++;
		mainIndex++;
	}
	while (rightIndex < rightArraySize){
		unsortedArray[mainIndex] = rightArray[rightIndex];
		rightIndex++;
		mainIndex++;
	}
}
