#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_strings - prints strings, follwed by a new line
 * @separator: pointer to the separator between strings
 * @n: the number of strings passed to function
 * Return: nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	/* Declare a variable to access the variadic arguments */
	va_list args;
	/* Declare a variable for loop coounter */
	unsigned int i;
	/* Declare a pointer to hold each string argument */
	char *str;

	/* Initialise args to retrieve argumetns after n */
	va_start(args, n);

	/* Loop through each argument */
	for (i = 0; i < n; i++)
	{
		/* To retrieve the next argument as a string */
		str = va_arg(args, char *);

		/* if string is NULL, print (nil) */
		if (str == NULL)
		{
			printf("(nil)");
		/* otherwise print the string */
		}
		else
		{
			printf("%s", str);
		}

		/* Print the separator if it's not the last string*/
		/*	and the separator is not the NULL terminator */
		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

		/* New line after all strings */
		printf("\n");

		/* Clean up after yourself */
		va_end(args);
}

