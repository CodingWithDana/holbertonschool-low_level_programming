#include "main.h"
/**
 * swap_int - swap two integers
 * @a : pointer to integer a
 * @b:  pointer to integer b
 * Return: void
 */

void swap_int(int *a, int *b)
{
int temporary_variable;

temporary_variable = *a;
*a = *b;
*b = temporary_variable;
}
