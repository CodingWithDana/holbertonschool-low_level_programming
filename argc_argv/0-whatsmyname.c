#include "main.h"
/**
 * main - prints program name, followed by a new line
 * @argc: argument count
 * @argv: argument vector, argv[0] is program name
 * Return: nothing
*/
int main(int argc, char *argv[])
{
	char *name;

	/* avoid unused parameter argc warning */
	(void)argc;

	name = argv[0];

	while (*name)
	{
		_putchar(*name);
		name++;
	}
	_putchar('\n');
	return (0);
}
