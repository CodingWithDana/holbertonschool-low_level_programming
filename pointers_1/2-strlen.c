#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * _strlen - Returns the length of a string
 * @s: Pointer to the string
 *
 * Description: This function counts the number of characters in a
 * null-terminated string, not including the terminating '\0' character.
 *
 * Return: The length of the string as an integer.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
