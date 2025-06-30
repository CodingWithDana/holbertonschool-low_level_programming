#include "main.h"
/**
 * print_chessboard - print chessboard
 * @a: A pointer to an array of 8 characters representing the chessboard
 * Return: 0 on success
 */
void print_chessboard(char (*a)[8])
{
	int row;
	int col;

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			_putchar(a[row][col]);
		}
		_putchar('\n');
	}
}
