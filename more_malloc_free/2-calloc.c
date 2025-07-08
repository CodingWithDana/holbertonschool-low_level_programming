#include "main.h"
#include <stdlib.h>
/**
 * _calloc - allocate memory for an array and sets it to zero
 * @nmemb: number of elements in the array
 * @size: size of each element
 * Return: pointer to the allocated memory, otherwise NULL if
 * program fails or if size or nmemb is 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *array;

	/* If nmemb or size is 0, return NULL */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Allocate memory to each element */
	array = malloc(nmemb * size);

	/* If malloc fails */
	if (array == NULL)
		return (NULL);

	/* Set the allocated memory to zero */
	for (i = 0; i < (nmemb * size); i++)
		array[i] = 0;

	return ((void *)array);
}

