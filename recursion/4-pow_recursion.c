#include "main.h"
/**
 * _pow_recursion - returns the value of x to the power of y
 * @x: the base integer
 * @y: the exponent (must be positive)
 * Return: value of x to the power of y
 */
int _pow_recursion(int x, int y)
{
	/* If y is negative, then return -1 to indicate error case */
	if (y < 0)
	{
		return (-1);
	}

	/* When y is 0 => Base case: any number to the power of 0 is 1 */
	if (y == 0)
	{
		return (1);
	}

       /* Recursive calls */
	return (x * _pow_recursion(x, y - 1));
}
