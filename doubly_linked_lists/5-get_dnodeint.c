#include "lists.h"
#include <stdlib.h>
/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t list
 * @head: pointer to the head of the list
 * @index: index of the node to return (starting from 0)
 * Return: pointer to the nth node, or NULL if failed
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int index_counter = 0;

	while (head != NULL)
	{
		if (index_counter == index)
			return (head);
		head = head->next;
		index_counter++;
	}

	return (NULL);

}
