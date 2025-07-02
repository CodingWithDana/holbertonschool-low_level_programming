#include "main.h"
/**
 * factorial - returns the factorial of a given number
 * @n: a positive number whose factorial is computed
 * Return: the factorial of the number
 */
int factorial(int n)
{
	/* If n < 0, return -1 (to indiate error) */
	if (n < 0)
	{
		return (-1);
	}

	/* If n is 0, return 1 */
	if (n == 0)
	{
		return (1);
	}

	/* Recursive calls */
	return (n * factorial(n - 1));
}
