#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: the original string to duplicate
 * Return: pointer to the duplicate string
 * or NULL if str is NULL or if memory allocation fails
 */
char *_strdup(char *str)
{
	int i;
	int len = 0;
	char *dup_str;

	/* Check if string is NULL */
	if (str == NULL)
		return (NULL);

	/* Calculate the length of the input string */
	while (str[len] != '\0')
		len++;

	/* Allocate memory for the duplicate string */
	/* +1 for the null terminator */
	dup_str = malloc(sizeof(char) * (len + 1));

	/* If memory allocation fails */
	if (dup_str == NULL)
		return (NULL);

	/* Copy characters one by one */
	for (i = 0; i < len; i++)
		dup_str[i] = str[i];

	/* Null-terminate the 'dup_str' string */
	dup_str[i] = '\0';

	return (dup_str);
}
