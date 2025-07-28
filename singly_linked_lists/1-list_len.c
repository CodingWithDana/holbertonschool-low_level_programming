#include "lists.h"
#include <stdio.h>
/**
 * list_len - prints the number of elements in the linked list
 * @h: pointer to the head of the list
 * Return: the number of elements in the linked list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str != NULL)
		{
			count++;
		}
		h = h->next;
	}
	return (count);
}
