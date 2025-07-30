#include "lists.h"
#include <stdio.h>
/**
 * dlistint_len - prints the number of elements in the linked list
 * @h: pointer to the head of the list
 * Return: the number of elements in the linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
