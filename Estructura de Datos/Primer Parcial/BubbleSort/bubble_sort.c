/*
Gilberto Echeverria

Simple example of Bubble sort
*/

#define _CRT_SECURE_NO_DEPRECATE	// Stop the complaining from MS VS
// http://www.cplusplus.com/forum/beginner/2300/

#include <stdio.h>
#include "random_array.h"

#define ARRAY_SIZE 20

/*
Place first the largest numbers to the right
*/
void bubble_sort_rl(int base_array[], int array_size)
{
	int i, j;
	int tmp;

	for (i = array_size; i > 0; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (base_array[j - 1] > base_array[j])
			{
				tmp = base_array[j];
				base_array[j] = base_array[j - 1];
				base_array[j - 1] = tmp;
			}
		}
		//print_array(base_array, array_size, "After 1 pass");
	}
}

/*
Place first the smallest numbers to the left
*/
void bubble_sort_lr(int base_array[], int array_size)
{
	int i, j;
	int tmp;

	for (i = 0; i < array_size; i++)
	{
		for (j = array_size-1; j > i; j--)
		{
			if (base_array[j - 1] > base_array[j])
			{
				tmp = base_array[j];
				base_array[j] = base_array[j - 1];
				base_array[j - 1] = tmp;
			}
		}
		//print_array(base_array, array_size, "After 1 pass");
	}
}

int main(void)
{
	int i;

	// Init array
	int base_array[ARRAY_SIZE];

	// Uncomment this when the algorithm is working correctly
	//randomize();
	// Call the library function to fill the array
	fill_random_array(base_array, ARRAY_SIZE);

	print_array(base_array, ARRAY_SIZE, "Original array");

	bubble_sort_lr(base_array, ARRAY_SIZE);

	print_array(base_array, ARRAY_SIZE, "Sorted array");

	return 0;
}