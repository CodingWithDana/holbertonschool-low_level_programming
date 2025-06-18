#include <stdio.h>

/**
 * times_table - Prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int row, col, product;

	for (row = 0; row <= 9; row++)
	{
		for (col = 0; col <= 9; col++)
		{
			product = row * col;

			if (col == 0)
			{
				printf("%d", product);
			}
			else
			{
				if (product < 10)
					printf(",  %d", product);
				else
					printf(", %d", product);
			}
		}
		printf("\n");
	}
}
