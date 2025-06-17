#include "main.h"
/**
 * main - Entry point
 *
 * Description: prints _putchar, followed by a new line
 *
 * Return: Always 0
 */
int main(void)
{
	int i = 0;
	char *str = "_putchar";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
