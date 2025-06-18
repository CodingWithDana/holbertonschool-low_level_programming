#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int row, col, product;
	int tens, ones;

	for (row = 0; row <= 9; row++)
	{
		for (col = 0; col <= 9; col++)
		{
			product = row * col;
			tens = product / 10;
			ones = product % 10;

			if (col == 0)
			{
				if (product < 10)
					_putchar('0');
				else
				{
					_putchar('0' + tens);
					_putchar('0' + ones);
				}
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (product < 10)
				{
					_putchar(' ');
					_putchar('0' + product);
				}
				else
				{
					_putchar('0' + tens);
					_putchar('0' + ones);
				}
			}
		}
		_putchar('\n');
	}
}
