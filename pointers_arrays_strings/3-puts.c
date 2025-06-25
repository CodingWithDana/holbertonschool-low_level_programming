#include "main.h"
#include <stdio.h>
/**
 * _puts - prints a string followed by a new line
 * to stdout
 * @str: the string to be printed 
 * Description: this function prints each character of the input string
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
