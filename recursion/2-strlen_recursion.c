#include "main.h"
/**
 * _strlen_recursion - returns length of a string
 * @s: Pointer to the first element of string
 * Return: the length of string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		/* if the string is empty, return 0 */
		return (0);
	}

	/* Otherwise print the length of the rest of the string */
	return (1 + _strlen_recursion(s + 1));
}
