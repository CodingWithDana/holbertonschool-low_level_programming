#include "main.h"
/**
 * _memset - fills memory with a constant byte
 * @s: Pointer to the n bytes of the memory area
 * @n: the number of bytes to fill
 * @b: a constant byte to fill the memory with
 * Return: Pointer s to the memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

    /* Loop through the first n bytes */
	for (i = 0; i < n; i++)
	{
	    /* Set each byte to the constant value b */
		s[i] = b;
	}

    /* Return the memory pointer */
	return (s);
}
