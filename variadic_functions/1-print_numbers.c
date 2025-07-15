#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - prints numbers, follwed by a new line
 * @separator: pointer to the separator between numbers
 * @n: the number of integers passed to function
 * Return: nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	/* Declare new variables */
	va_list args;
	unsigned int i;

	/* Initialise the argument list */
	va_start(args, n);

	/* Loop through to get the next int argument */
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		/* Print separator if it's not NULL and not the last element */
		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	/* Clean up */
	va_end(args);
	/* New line */
	printf("\n");
}
