#include <stdio.h>

/**
 * main - prints the alphabet in lowercase followed by a new line
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
	putchar('\n');

	return (0);
}
