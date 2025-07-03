#include <stdio.h>
/**
 * main - prints all arguments, one argument each line
 * then the next argument in a new line
 * @argc: argument count
 * @argv: argument vector
 * Return: nothing
*/
int main(int argc, char *argv[])
{
	(void)argc;

	while (*argv != NULL)
	{
		printf("%s\n", *argv);
		argv++;
	}
	return (0);
}
