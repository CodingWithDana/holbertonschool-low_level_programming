#include "main.h"

/**
 * print_square - Prints a square of hashtags
 * @size: Size of the square
 *
 * Return: void
 */
void print_square(int size)
{
	int row = 0;
	int column;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	while (row < size)
	{
		column = 0;
		while (column < size)
		{
			_putchar('#');
			column++;
		}
		_putchar('\n');
		row++;
	}
}
