#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>
/**
 * hash_table_get - retrieve the value associated with a given key
 * @ht: the hash table 
 * @key: the key you are looking for
 * Return: the value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	/* Validate input: hash table and key must not be empty */
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	/* Get the index where the key should be located */
	index = key_index((const unsigned char *)key, ht->size);
	/* Start at the first node in the chain at this index */
	current = ht->array[index];
	/* Traverse the linked list (chain) to find the key */
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			/* Key found, return the value */
			return (current->value);
		/* Move to the next node */
		current = current->next;
	}
	/* If key isn't found */
	return (NULL);
}

