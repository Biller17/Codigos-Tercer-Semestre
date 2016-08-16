/*
Gilberto Echeverria

Merge sort algorithm using arrays
*/

#define _CRT_SECURE_NO_DEPRECATE	// Stop the complaining from MS VS
// http://www.cplusplus.com/forum/beginner/2300/

#include <stdio.h>
#include "random_array.h"

#define ARRAY_SIZE 20


/*
Function to copy a certain range from one array to another
*/
void array_copy(int origin[], int destination[], int start, int end)
{
	int i;
	printf("Merged: ");
	for (i = start; i < end; i++)
	{
		destination[i] = origin[i];
		printf("%d ", origin[i]);
	}
	printf("\n");
}

/*
Join two arrays into one
When copying to the new array, the elements are ordered
*/
void merge_sort_merge(int base_array[], int tmp_array[], int start, int middle, int end)
{
	int index1 = start;			// The index for the 1st sub-array
	int index2 = middle;		// The index for the 2nd sub-array
	int index_merge;			// Index for the final merged array

	for (index_merge = start; index_merge < end; index_merge++)
	{
		if (index1 < middle && (index2 >= end || base_array[index1] < base_array[index2]))
		{
			tmp_array[index_merge] = base_array[index1];
			index1++;
		}
		else
		{
			tmp_array[index_merge] = base_array[index2];
			index2++;
		}
	}
}

/*
Merge sort

Recursive method that splits the array in half until it gets to sub-arrays of size 1
Then merge those arrays while ordering them
Uses a second array as a temporary storage place
*/
void merge_sort_split(int base_array[], int tmp_array[], int start, int end)
{
	int middle;

	printf("Split called with limits %d -- %d\n", start, end);

	// Only subdivide if the length of the array is greater than 1
	if (end - start > 1)
	{
		// Split the array trough the middle
		middle = (start + end) / 2;
		// Recursive calls to continue splitting
		merge_sort_split(base_array, tmp_array, start, middle);
		merge_sort_split(base_array, tmp_array, middle, end);
		// Merge the two sorted arrays
		merge_sort_merge(base_array, tmp_array, start, middle, end);
		// Copy back from the temporary to the original array
		array_copy(tmp_array, base_array, start, end);
	}
}


int main(void)
{
	// Init array
	int base_array[ARRAY_SIZE];
	int tmp_array[ARRAY_SIZE];

	printf("MERGE SORT\n");
	printf("==========\n");

	// Uncomment this when the algorithm is working correctly
	//randomize();
	// Call the library function to fill the array
	fill_random_array(base_array, ARRAY_SIZE);

	print_array(base_array, ARRAY_SIZE, "Original array");

	merge_sort_split(base_array, tmp_array, 0, ARRAY_SIZE);

	print_array(base_array, ARRAY_SIZE, "Sorted array");

	return 0;
}