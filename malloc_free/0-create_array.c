#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars and initializes it with a specific char
 * @size: size of the array
 * @c: the specific char to initialize the array with
 * Return: pointer to the array, or NULL if the program fails or size is 0
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	/* If size is 0, return NULL */
	if (size == 0)
	{
		return (NULL);
	}

	/* Allocate memory for characters in the array */
	array = (char *)malloc(size * sizeof(char));

	/* Check if malloc has memory issue (e.g out of memory) */
	if (array == NULL)
	{
		return (NULL);
	}

	/* Fill each element of the array with the specific character 'c' */
	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}

	/* Return the pointer to the array */
	return (array);
}

