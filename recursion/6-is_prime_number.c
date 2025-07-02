#include "main.h"
/**
 * _prime_checker - recursively checks for a prime number
 * @n: the input integer
 * @current_number: the current number to be checked
 * Return: the input integer if it is a prime number
 */
int _prime_checker(int n, int current_number)
{
	/* Check if n has any divisor which is a smaller number than n */
	/* if not, n is a prime */
	if (current_number * current_number > n)
	{
		return (1);
	}

	/* Check if n can be divided by i, then not a prime number */
	if (n % current_number == 0)
	{
		return (0);
	}
	return (_prime_checker(n, current_number + 1));
}

/**
 * is_prime_number - returns the input integer if it is a prime number
 * @n: the input integer
 * Return: the input integer if it is a prime number, otherwise 0
 */
int is_prime_number(int n)
{
	/* 0 and 1 are not prime numbers */
	if (n <= 1)
	{
		return (0);
	}
	/* Start checking for prime number from current_number = 2 */
	return (_prime_checker(n, 2));
}
