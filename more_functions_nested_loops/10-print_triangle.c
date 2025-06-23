#include "main.h"

/**
 * print_triangle - Prints a triangle of hashtags
 * @size: Size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int row;
	int column;
	int space;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		for (space = size - row; space > 0; space--)
		{
			_putchar(' ');
		}
		for (column = 1; column <= row; column++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
