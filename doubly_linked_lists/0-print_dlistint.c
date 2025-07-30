#include "lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * print_dlistint - prints all elements of a doubly linked list
 * @h: pointer to the head of the list
 * Return: number of nodes printed
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
