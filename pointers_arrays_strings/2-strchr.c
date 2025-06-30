#include "main.h"
#include <stdio.h>
/**
 * _strchr - locates a character of a string
 * @s: Pointer to the string
 * @c: Pointer to the character c of the string
 * Return: Pointer c or null if character not found
 */
char *_strchr(char *s, char c)
{
	/* Loop through the string until reaching null terminator */
	while (*s != '\0')
	{
		/* If the current character matches 'c', have the pointer pointing to it */
		if (*s == c)
			return (s);
		/* Move s to the next character */
		s++;
	}

	/* If 'c' is null terminator, have the pointer pointing to it */
	if (c == '\0')
		return (s);
	/* If 'c' was not found, return NULL */
		return (NULL);
}
