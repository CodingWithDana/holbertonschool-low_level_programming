#include "lists.h"
#include <stdlib.h>
#include <string.h>
/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to store in the new node (will be duplicated)
 * Return: the address of the new element, or NULL if failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *dup_str;
	/* length of the duplicated string */
	int count = 0;
	int dup_str_len = 0;

	if (str == NULL)
		return (NULL);

	dup_str = strdup(str);
	if (dup_str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		free(dup_str);
		return (NULL);
	}

	while (dup_str[count] != '\0')
	{
		count++;
	}
	dup_str_len = count;

	new_node->str = dup_str;
	new_node->len = dup_str_len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
