#include "main.h"
#include <stdio.h>
/**
 * _strpbrk - search a string for any of a set of bytes
 * @s: Pointer to the search string
 * @accept: Pointer to the string containing bytes to match
 * Return: Pointer to the first matching byte in s
 * or NULL if no matched byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *pointer_to_s = s;

	/* Go through each character in s that is not null */
	while (*pointer_to_s != '\0')
	{
		/* Declare new pointer inside this loop to point to the start of accept string */
		char *pointer_to_accept = accept;

		/* Check current character in s string against each character in accept string */
		while (*pointer_to_accept != '\0')
		{
			/* If a match is found */
			if (*pointer_to_s == *pointer_to_accept)
				/* Point the pointer s to the matched character in s string */
				return pointer_to_s;
			
			/* Move to next character in pointer_to_accept */
			pointer_to_accept++;
		}

		pointer_to_s++;
	}
	
	/* No match found in the entire string */
	return (NULL);
}
