#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_set(ht, "betty", "cool");

    /* These pairs will cause collision under djb2 at size 1024 */
    hash_table_set(ht, "hetairas", "val1");
    hash_table_set(ht, "mentioner", "val2");

    hash_table_set(ht, "heliotropes", "val3");
    hash_table_set(ht, "neurospora", "val4");

    hash_table_set(ht, "depravement", "val5");
    hash_table_set(ht, "serafins", "val6");

    hash_table_set(ht, "stylist", "val7");
    hash_table_set(ht, "subgenera", "val8");

    hash_table_set(ht, "joyful", "val9");
    hash_table_set(ht, "synaphea", "val10");

    hash_table_set(ht, "redescribed", "val11");
    hash_table_set(ht, "urites", "val12");

    hash_table_set(ht, "dram", "val13");
    hash_table_set(ht, "vivency", "val14");

    return (EXIT_SUCCESS);
}
