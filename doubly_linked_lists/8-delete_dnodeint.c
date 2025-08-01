#include "lists.h"
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - deletes the new node at a target index
 * @head: pointer pointing to the head pointer of the list
 * @index: index of the node to delete (starting at 0)
 * Return: 1 if successful or -1 if fail
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (*head == NULL || head == NULL)
		return (-1);
	/* Delete the head node */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Move through the list to reach the node at a given index */
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	/* Check if reach the end of list before the index (index is out of range) */
	if (current == NULL)
		return (-1);

	if (current->prev != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
