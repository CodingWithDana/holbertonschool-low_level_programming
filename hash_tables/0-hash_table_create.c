#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - create a hash table
 * @size: size of the array
 * Return: pointer to the newly created hash table, or NULL if fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	/* Allocate memory for the hash table structure */
	/*	(store size and pointer to array */
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		/* If malloc fails, return NULL to indicate error */
		return (NULL);
	/* Set the size of the hash table */
	ht->size = size;

	/* Allocate memory for the array (buckets) that */
	/*		 holds pointers to hash_node_s */
	/* Initialise to NULL an array of hash_node_t* */
	ht->array = calloc(size, sizeof(hash_node_t *));
	/* If allocation fails */
	if (ht->array == NULL)
	{
		/* Free the previously allocated structure */
		free(ht);
		/* Return NULL to indicate failure */
		return (NULL);
	}
	/* Return pointer to the newly created hash table */
	return (ht);
}
