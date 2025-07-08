#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min: the minimum value (included)
 * @max: the maximum value (included)
 * Return: pointer to the newly created array, otherwise NULL if
 * min > max or the malloc fails
 */
int *array_range(int min, int max)
{
	/* pointer to hold the address of the allocated array */
	int *array;
	/* i for loop index */
	int i;
	/* size of the number of elements in the array */
	int size;

	/* If min > max, the array range is invalid, return NULL */
	if (min > max)
		return (NULL);

	/* Calc how many elements are needed (min and max are included) */
	size = max - min + 1;

	/* Allocate memory for the array (size of integers) */
	array = malloc(sizeof(int) * size);

       /* If malloc fails */
	if (array == NULL)
		return (NULL);

       /* Fill the array with values from min to max */
	for (i = 0; i < size; i++)
		array[i] = min + i;

       /* Return the pointer to the newly created and filled array */
	return (array);
}


