#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    /* create a new hash table */
    ht = hash_table_create(1024);
    /* print the address of the hash table */
    printf("%p\n", (void *)ht);
    return (EXIT_SUCCESS);
}
