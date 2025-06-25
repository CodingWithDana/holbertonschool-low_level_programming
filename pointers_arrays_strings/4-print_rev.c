#include "main.h"
/**
 * print_rev - prints a string in reverse, 
 * followed by a new line
 * @s: pointer to a string to print
 * Description: This function prints each character of the input string
 * in reverse using _putchar, then prints a newline
 * Return: void
 */

void print_rev(char *s)
{
	char *to_the_end_then_backward = s;

	while (*to_the_end_then_backward != '\0')
	{
		to_the_end_then_backward++;
	}

	to_the_end_then_backward--;
	while (to_the_end_then_backward >= s)
	{
		_putchar(*to_the_end_then_backward);

		to_the_end_then_backward--;
	}

	_putchar('\n');
}		
