#include "main.h"

/**
 * _sqrt_checker - recursively checks for the natural square root of n
 * @n: the number to find the square root of
 * @current_number: the current number to be checked (starting from 0)
 * Return: the natural square root
 */
int _sqrt_checker(int n, int current_number)
{
	/* If n has a natural square root number, return that number */
	if (current_number * current_number == n)
	{
		return (current_number);
	}

	/* If the multiplication passed n, return -1 (case error) */
	if (current_number * current_number > n)
	{
		return (-1);
	}

	return (_sqrt_checker(n, current_number + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root
 * Return: the natural square root of a number
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_sqrt_checker(n, 0));
}
