#include "hash_tables.h"
/**
 * key_index - gives the indx of a key in the hash table array
 * @key: the key to hash
 * @size: the size of the array in the hash table
 * Return: the index at which the key should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
