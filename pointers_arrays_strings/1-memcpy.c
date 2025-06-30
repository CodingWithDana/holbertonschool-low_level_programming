#include "main.h"
/**
 * _memcpy - copies memory area
 * @src: Pointer to the n bytes of the memory area src
 * @dest: Pointer to the memory area dest
 * @n: the number of bytes to fill
 * Return: Pointer to memory area dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;

	/* Loop through each byte up to n-1 (thats why i < n) */
	while (i < n)
	{
		/* Copy byte from source to destination */
		dest[i] = src[i];
		i++;
	}
	/* Return the pointer to the destianation memory */
	return (dest);
}
