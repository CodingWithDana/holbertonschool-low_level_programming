#include "main.h"
#include <string.h>
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings,
 * which contains s1, followed by the first n bytes of s2
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to include from s2
 * Return: pointer to allocated memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	unsigned int j;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	char *new_string;

	/* If NULL is passed, treat as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calc the length of each string */
	len1 = strlen(s1);
	len2 = strlen(s2);

	/* If n is more than the length of s2, just use entire s2 */
	if (n >= len2)
		n = len2;

	/* Allocate memory for the new_string: */
	/* len1 from s1 + n from s2 + 1 for the \0 ) */
	new_string = malloc(len1 + n + 1);
	/* Check for if memory allocation fails */
	if (new_string == NULL)
		return (NULL);

	/* Copy s1 into the new_string */
	for (i = 0; i < len1; i++)
		new_string[i] = s1[i];

	/* Copy the first n bytes of s2 into the new_string after s1 */
	for (j = 0; j < n; j++)
		new_string[i + j] = s2[j];

	/* Null terminate the new_string */
	new_string[i + j] = '\0';

	return (new_string);
}

