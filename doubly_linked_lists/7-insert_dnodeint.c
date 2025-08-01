#include "lists.h"
#include <stdlib.h>
/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer pointing to the head pointer of the doubly linked list
 * @idx: index where the new node should be inserted (starting at 0)
 * @n: data to store in the new node
 * Return: the address of the new node, otherwise NULL if insertion fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current = *h;
	unsigned int i = 0;

	/* Insert at the beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Move through the list to reach the node just before the target index */
	while (current != NULL && i < (idx - 1))
	{
		current = current->next;
		i++;
	}
	/* Check if reach the end of list before idx - 1 */
	if (current == NULL)
		return (NULL);

	/* Insert at the end */
	if (current->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = current;
	new_node->next = current->next;

	current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}
