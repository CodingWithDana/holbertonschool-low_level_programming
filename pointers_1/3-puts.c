#include "main.h"
#include <stdio.h>

/**
 * _puts - Prints a string followed by a new line to stdout
 * @str: The string to be printed
 *
 * Description: This function prints each character of the input string
 * using _putchar, then prints a newline.
 *
 * Return: void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
