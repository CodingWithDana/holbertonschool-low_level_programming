#include <stdio.h>
#include "dog.h"
/**
 * print_dog - prints a struct dog
 * @d: pointer to the struct dog to print
 * Return: prints the name, age, and owner of the dog
 * if the element is NULL, return (nil)
 */
void print_dog(struct dog *d)
{
	/* If d is NULL, prints nothing */
	if (d == NULL)
		return;

	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %.6f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
