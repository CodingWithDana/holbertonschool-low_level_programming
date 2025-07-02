#include "main.h"
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: a positive number to be checked if it has a natural square root
 * Return: the natural square root of a number
 */
int _sqrt_recursion(int n)
{
	static int natural_square_root_number;

	/* If n doesn't have a natural square root number, return -1 (case error) */
	if (n < 0)
	{
		return (-1);
	}

	/* If n has a natural square root number, return that number */
	if (natural_square_root_number * natural_square_root_number == n)
	{
		/* Save the correct value to the variable */
		int result = natural_square_root_number;
		/* Reset for future recursive calls */
		natural_square_root_number = 0;
		return (result);
	}

	/* If passed n, return -1 (case error) */
	if (natural_square_root_number * natural_square_root_number > n)
	{
		/* Reset for future recursive calls */
		natural_square_root_number = 0;
		return (-1);
	}

	natural_square_root_number++;

	/* Recursive calls */
	return (_sqrt_recursion(n));
}
