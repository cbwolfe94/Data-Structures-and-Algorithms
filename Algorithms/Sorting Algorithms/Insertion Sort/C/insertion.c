#include <stdio.h>
#include "insertion.h"

void insertion_sort(int *unsorted_array, long size_of_array)
{
	int decrement, element;

	for (int i = 1; i < size_of_array; i++){
		element = unsorted_array[i];
		decrement = i - 1;
		while (decrement >= 0 && unsorted_array[decrement] > element){
			unsorted_array[decrement + 1] = unsorted_array[decrement];
			decrement--;
		}
		unsorted_array[decrement + 1] = element;
	}

	for (int i = 0; i < size_of_array; i++){
		printf("%i ", unsorted_array[i]);
	}
}

