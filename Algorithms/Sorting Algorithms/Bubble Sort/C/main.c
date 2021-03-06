#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "bubble.h"

int main(int argc, char *argv[])
{
	long size_of_array = atol(argv[1]);
	int unsorted_array[size_of_array];
	srand(time(NULL));	

	for(int i = 0; i < size_of_array; i++){
		unsorted_array[i] = (random() % 100);
	}
	for(int i = 0; i < size_of_array; i++){
		printf("%i ", unsorted_array[i]);
	}
	
	printf("\n");
	bubble_sort(unsorted_array, size_of_array);
	for(int i = 0; i < size_of_array; i++) {
		printf("%i ", unsorted_array[i]);
	}
}
