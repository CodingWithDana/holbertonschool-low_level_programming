#include "main.h"
/**
 * _print_rev_recursion - prints a string in reverse
 * @s: pointer to the first element of string to reverse
 * Return: nothing
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
