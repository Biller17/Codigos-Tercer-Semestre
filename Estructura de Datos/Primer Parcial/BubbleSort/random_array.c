/*
Gilberto Echeverria

Headers for a library to generate a random array of integers
*/

#include "random_array.h"

/*
Function to produce pseudo-random numbers
*/
void randomize(void)
{
	// Init random number generator
	srand(time(NULL));
}

void fill_random_array(int base_array[], int array_size)
{
	int i, j;
	int num;
	int ok;

	// Fill the array
	for (i = 0; i < array_size; i++)
	{
		num = rand() % 100 + 1;
		ok = 1;
		// Validate that the new number is not already in the array
		for (j = 0; j < i; j++)
		{
			if (num == base_array[j])
			{
				ok = 0;
				printf("%d is already in the array at position %d\n", num, j);
				break;
			}
		}
		if (ok)
		{
			base_array[i] = num;
		}
		else
		{
			// Try again to fill this item
			i--;
		}
	}
}


/*
Helper function to show the contents of an array
*/
void print_array(int base_array[], int array_size, char* header)
{
	int i;

	printf("%s:\n", header);
	for (i = 0; i < array_size; i++)
	{
		printf("%d ", base_array[i]);
	}
	printf("\n");
}