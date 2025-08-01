#include "lists.h"
/**
 * sum_dlistint - returns the sum of all the data(n) of doubly linked list
 * @head:  pointer pointing to the head of the list
 * Return: total of all node values, otherwise 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}
