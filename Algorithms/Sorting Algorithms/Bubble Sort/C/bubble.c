#include <stdio.h> 
#include "bubble.h"

void bubble_sort(int *unsorted_array, long size_of_array)
{
	int temp;
	//int max = *unsortedArray;
	for(int i = 0; i < size_of_array; i++) {
		for(int i = 0; i < size_of_array - 1; i++) {
			if(unsorted_array[i] > unsorted_array[i + 1]) {
				temp = unsorted_array[i];
				unsorted_array[i] = unsorted_array[i + 1];
				unsorted_array[i + 1] = temp;
			}
		}
	}
}
