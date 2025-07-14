#include "function_pointers.h"
#include <stddef.h>
/**
 * array_iterator - executes a function on each element of an array
 * @array: the array of integers
 * @size: the number of elements in the array
 * @action: a pointer to a function that takes an int and returns void
 * Return: nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	/* Check if the  array or function pointer is NULL to avoid crashes */
	if (array == NULL || action == NULL)
		/* Stop the function early if either is NULL */
		return;

	/* Loop through each element of the array */
	for (i = 0; i < size; i++)
	{
		/* Call the action function with the current array element */
		action(array[i]);
	}
}
