#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sum of two diagonals of a square matrix
 * @a: Pointer to the first element of the matrix
 * @size: size of the square matrix (number of rows/columns)
 * Return: 0 on success
 */
void print_diagsums(int *a, int size)
{
	/* The loop index used to iterate through matrix rows for diagonal sums */
	int i;
	/* Sum of the main diagonal */
	int sum1 = 0;
	/* Sum of the anti diagonal */
	int sum2 = 0;

	for (i = 0; i < size; i++)
	{
		/* Main diagonal element */
		sum1 += a[i * size + i];
		/* Anti diagonal element */
		sum2 += a[i * size + (size - 1 - i)];
	}
	printf("%d, %d\n", sum1, sum2);
}
