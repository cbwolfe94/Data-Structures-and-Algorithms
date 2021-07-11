#include "quick.h"

void quick_sort(int *unsorted_array, long low, long high)
{
	if(low < high){
		int partition_index = partition(unsorted_array, low, high);
		
		quick_sort(unsorted_array, low, partition_index - 1);
		quick_sort(unsorted_array, partition_index + 1, high);
	}
}

void swap(int *first_num, int *second_num)
{
	int temp = *first_num;
	*first_num = *second_num;
	*second_num = temp;
}

int partition(int *unsorted_array, long low, long high)
{
	int pivot = unsorted_array[high];
	int smaller_element_index = low - 1;

	for (int i = low; i <= high - 1; i++) {
		if (unsorted_array[i] < pivot) {
			smaller_element_index++;
			swap(&unsorted_array[smaller_element_index], &unsorted_array[i]);
		}
	}
	swap(&unsorted_array[smaller_element_index + 1], &unsorted_array[high]);
	return smaller_element_index + 1;
		
}