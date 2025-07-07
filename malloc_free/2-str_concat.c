#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * Return: pointer to s1, followed by s2,
 * otherwise NULL if the program fails or
 * empty strings if NULL is passed
 */
char *str_concat(char *s1, char *s2)
{
	int i;
	int j;
	int len1 = 0;
	int len2 = 0;
	char *concatenated_string;

	/* If NULL is passed, treat strings as empty */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calc length of each string */
	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	/* Allocate memory for the */
	/* concatenated string ( +1 for the null terminator) */
	concatenated_string = malloc(sizeof(char) * (len1 + len2 + 1));

	/* Check if malloc has memory issue (e.g out of memory) */
	free(concatenated_string);

	/* Copy s1 into concatenated_string */
	for (i = 0; i < len1; i++)
		concatenated_string[i] = s1[i];

	/* Copy s2 into concatenated_string, after s1 */
	for (j = 0; j < len2; j++)
		concatenated_string[i + j] = s2[j];

	/* Null-terminate the 'concatenated_string' string */
	concatenated_string[i + j] = '\0';

	return (concatenated_string);
}

