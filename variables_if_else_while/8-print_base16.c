#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints all hexadecimal numbers (base 16) in lowercase
 * using only putchar 3 times
 *
 * Return: Always 0
 */
int main(void)
{
	char c = '0';

	while (c <= '9')
		putchar(c++);

	c = 'a';
	while (c <= 'f')
		putchar(c++);

	putchar('\n');
	return (0);
}
