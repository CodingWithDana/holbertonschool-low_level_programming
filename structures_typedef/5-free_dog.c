#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees dogs
 * @d: pointer to the dog to free
 * Return: nothing
 */
void free_dog(dog_t *d)
{
	/* If pointer d is not NULL */
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
