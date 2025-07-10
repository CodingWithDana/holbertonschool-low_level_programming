#include "dog.h"
#include <stdlib.h>
/**
 * init_dog - initialise a variable of type struct dog
 * @d: pointer to struc
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the owner of the dog
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
