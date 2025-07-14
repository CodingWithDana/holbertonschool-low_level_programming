#include "function_pointers.h"
/**
 * int_index - searches for an integer
 * @array: the array to search through
 * @size: the number of elements in the array
 * @cmp: a pointer to the function used to compare values
 * Return: the index of the first element for which the cmp
 * function does not return 0, or
 * return -1 if no match or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	/* Loop counter */
	int i;

	/* Safety check to avoid crashes */
	if (array == NULL || cmp == NULL || size <= 0)
	{
		return (-1);
	}

	/* Loop through each element of the array */
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}

	/* Ensures all paths return a value */
	return (-1);
}
