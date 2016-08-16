/*
Gilberto Echeverria

Headers for a library to generate a random array of integers
*/

#include <stdlib.h>
#include <time.h>

/*
Function to produce pseudo-random numbers
*/
void randomize(void);

/*
Function to fill an array with non-repeating random integers
*/
void fill_random_array(int base_array[], int array_size);

/*
Helper function to show the contents of an array
*/
void print_array(int base_array[], int array_size, char* header);