#include "merge.h"

void merge_sort(int *unsorted_array, long start, long end){
	if (start < end){
		int middle = start + (end - start)/2;
		
		merge_sort(unsorted_array, start, middle);
		merge_sort(unsorted_array, middle + 1, end);
		merge(unsorted_array, start, middle, end);
	}
}

void merge(int* unsorted_array, long start, long middle, long end)
{
	int left_index, right_index, main_index;
	long left_array_size = middle - start + 1;
	long right_array_size = end - middle;
	int left_array[left_array_size], right_array[right_array_size];

	for (left_index = 0; left_index < left_array_size; left_index++){
		left_array[left_index] = unsorted_array[start + left_index];
	}
	for (int right_index = 0; right_index < right_array_size; right_index++){
		right_array[right_index] = unsorted_array[middle + right_index + 1];
	}
	
	left_index = 0;
	right_index = 0;
	main_index = start;

	while (left_index < left_array_size && right_index < right_array_size){
		if (left_array[left_index] <= right_array[right_index]){
			unsorted_array[main_index] = left_array[left_index];
			left_index++;
		}
		else {
			unsorted_array[main_index] = right_array[right_index];
			right_index++;
		}
		main_index++;
	}
	while (left_index < left_array_size){
		unsorted_array[main_index] = left_array[left_index];
		left_index++;
		main_index++;
	}
	while (right_index < right_array_size){
		unsorted_array[main_index] = right_array[right_index];
		right_index++;
		main_index++;
	}
}
