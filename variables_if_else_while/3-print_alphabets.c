#include <stdio.h>

/**
 * main - prints the alphabet in lowercase then uppercase
 *        followed by a new line
 *
 * Return: 0 on success
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c++);
	}

	c = 'A';

	while (c <= 'Z')
	{
		putchar(c++);
	}

	putchar('\n');

	return (0);
}
