#include <stdio.h>
/**
 * main - prints single digit numbers,
 *        followed by a new line
 *
 * Return: 0 on success
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d", i);
	}

	printf("\n");

	return (0);
}
