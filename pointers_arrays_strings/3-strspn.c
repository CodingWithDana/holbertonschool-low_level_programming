#include "main.h"
/**
 * _strspn - get lengths of a prefix substring
 * @s: Pointer to the source string
 * @accept: Pointer to the string containing accepted characters
 * Return: number of bytes in the initial segment of s
 * consisting of only bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	/* Count how many characters in s that is matching accept consecutively */
	unsigned int count = 0;
	/* Pointer to iterate through the accept string */
	char *a;

	/* Iterate over each char in s string */
	while (*s)
	{
		/* Point pointer 'a' to the start of accept string to scan for a match */
		a = accept;
		/* Next, check if the current character in s string is in accept string */
		while (*a)
		{
			if (*s == *a)
				/* If match found, stop searching (this nest loop stops running) */
				break;
			/* Move to the next character in a */
			a++;
		}
		/* No match found in accept string for the current char in s string */
		if (*a == '\0')
			break;
		/* Increment count for the next matched char */
		count++;
		/* Move to next char in s */
		s++;
	}

	return (count);
}
