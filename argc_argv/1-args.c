#include <stdio.h>
/**
 * main - prints the number of arguments, followed by a new line
 * @argc: argument count
 * @argv: argument vector,
 * Return: nothing
*/
int main(int argc, char *argv[])
{
	(void)argv;

	/* Minus 1 from argc to get the number of arguments */
	printf("%d\n", argc - 1);
	return (0);
}
