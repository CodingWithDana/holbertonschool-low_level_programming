#include "dog.h"
#include <stdlib.h>
#include <string.h>
/**
 * _strcpy - copies a string to a newly allocated buffer
 * @str: string to copy
 * Return: pointer to the new string (or NULL on failure)
 */
char *_strcpy(char *str)
{
	char *copied_string;
	int i;
	int len = 0;

	/* Calc the length of the string to copy */
	while (str[len] != '\0')
		len++;

	/* Allocate memory (+1 for null terminator) */
	copied_string = malloc(len + 1);

	/*If malloc fails */
	if (copied_string == NULL)
		return (NULL);

	/* Copy each character */
	for (i = 0; i <= len; i++)
		copied_string[i] = str[i];
	return (copied_string);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to the new dog_t,
 * or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	/* Allocate memory for the dog struct */
	d = malloc(sizeof(dog_t));
	/* If malloc fails */
	if (d == NULL)
		return (NULL);

	/* Create copies of name and owner */
	d->name = _strcpy(name);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = _strcpy(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;
	return (d);
}
