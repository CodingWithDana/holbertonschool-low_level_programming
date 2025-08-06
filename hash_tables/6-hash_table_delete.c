#include "hash_tables.h"
#include <stdlib.h>
/**
 * hash_table_delete - frees a hash table and all its contents
 * @ht: the hash table to free
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	/* Loop counter to iterate through the array index of the hash table */
	unsigned long int i;
	/* The node traverses each linked list */
	hash_node_t *node;
	/* A place to temporarily store the next node during deletion */
	hash_node_t *temp;

	/* If the hash table is empty, do nothing */
	if (ht == NULL)
		return;
	/* Loop through each index of the hash table array */
	for (i = 0; i < ht->size; i++)
	{
		/* Get the head node at this index */
		node = ht->array[i];

		/* Traverse and free the linked list at this index */
		while (node != NULL)
		{
			/* Save the next node */
			temp = node->next;
			/* Free the duplicate key */
			free(node->key);
			/* Free the duplicate value */
			free(node->value);
			/* Free the node itself */
			free(node);

			/* Move to the next node in the list */
			node = temp;
		}
	}
	/* Free the array of pointers */
	free(ht->array);
	/* Free the hash  table structure itself */
	free(ht);
}

