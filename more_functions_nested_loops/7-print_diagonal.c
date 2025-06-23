#include "main.h"
#include <stdio.h>

/**
 * print_diagonal - Prints a diagonal line of backslashes
 * @n: Number of backslashes to print
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int i = 0;
	int j;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			_putchar(' ');
			j++;
		}
		_putchar('\\');
		_putchar('\n');
		i++;
	}
}
