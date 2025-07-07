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
	char *concatenated_string;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* If n is more than the length of s2, just use entire s2 */
	if (n >= len2)
		n = len2;

	/* Allocate memory for the concatenated_string: */
	/* len1 from s1 + n from s2 + 1 for the \0 ) */
	concatenated_string = malloc(len1 + n + 1);
	/* Check for when malloc fails */
	if (concatenated_string == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concatenated_string[i] = s1[i];

	for (j = 0; j < n; j++)
		concatenated_string[i + j] = s2[j];

	concatenated_string[i + j] = '\0';

	return (concatenated_string);
}

