#include "main.h"
#include <stdio.h>
/**
 * _strstr - locates a substring
 * @haystack: the source string containing the substring needle
 * @needle: the substring
 * Return: Pointer to the beginning of the located substring
 * or NULL if the substring not found
 */
char *_strstr(char *haystack, char *needle)
{
	/* if needle substring is empty, return haystack */
	if (*needle == '\0')
		return (haystack);

	while (*haystack)
	{
		/* Declare pointer *h to iterate thru haystack from current position */
		char *h = haystack;
		/* Declare pointer *n to iterate thru needle (substring to find) */
		char *n = needle;

		/* Loop through haystack to find a match */
		while (*h != '\0' && *n != '\0' && (*h == *n))
		{
			h++;
			n++;
		}

		/* When reaching the end of needle */
		if (*n == '\0')
			return (haystack);

		/* Move to the next character in haystack */
		haystack++;
	}

	/* Loops are done and no match is found */
	return (NULL);
}
