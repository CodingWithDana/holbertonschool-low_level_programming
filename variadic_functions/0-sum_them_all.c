#include <stdarg.h>
#include <stdio.h>
/**
 * sum_them_all - returns the sum of all parameters
 * @n: the number of parameters to sum
 * @...: the integers to sum
 * Return: the sum otherwise 0 if n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum;
	/* Declare a variable to hold the arguments */
	/* Remember to declare all new variables before statements */
	/* ISO C90 does not allow mixed declaration and code */
	va_list args;

	/* Initialise variable sum (the first statement in the code) */
	sum = 0;
	/* Check if n is 0 */
	if (n == 0)
	{
		return (0);
	}

	/* Initialise the variable arguments list */
	va_start(args, n);

	/* Access each argument (assume it's integer) */
	for (i = 0; i < n; i++)
	{
	sum = sum + va_arg(args, int);
	}

	/* Clean up the variable arguments list */
	va_end(args);

	return (sum);
}
