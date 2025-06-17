#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print all combinations of single-digit numbers
 * using only putchar 4 times, separated by ", "
 *
 * Return: Always 0
 */
int main(void)
{
	int i = 0;

	while (i < 10)
	{
		putchar(i + '0');
		if (i < 9)
		{
			putchar(',');
			putchar(' ');
		}
		i++;
	}
	putchar('\n');
	return (0);
}
