#include <stdio.h>

/**
 * _isdigit - Check for a digit
 * @c: The digit to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
