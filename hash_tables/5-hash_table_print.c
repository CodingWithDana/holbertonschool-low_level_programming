#include "hash_tables.h"
#include <stdio.h>
/**
 * hash_table_print - print the hash table
 * @ht: the hash table to print
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	/* flag to check if we already printed a pair (to handle commas) */
	int printed_pair = 0;
	/* If hash table is empty, don't do anything */
	if (ht == NULL)
		return;

	/* Begin printing the hash table */
	printf("{");
	/* Loop through each index of the array */
	for (i = 0; i < ht->size; i++)
	{
		/* Get the head node at this index (could be NULL or a linked list) */
		node = ht->array[i];
		/* Traverse the linked list at this index */
		while (node != NULL)
		{
			if (printed_pair != '\0')
				/* Print comma before printing next pair (if it's not the first) */
				printf(", ");
				
			/* Print the key and value in the required format */
			printf("'%s': '%s'", node->key, node->value);
			/* Set flag to true after printing the first key-value pair */
			printed_pair = 1;
			/* Move to the next node in the linked list */
			node = node->next;
		}
	}
	/* End printing the hash table */
	printf("}\n");
}
