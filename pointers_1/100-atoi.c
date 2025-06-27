#include <stdio.h>
#include <limits.h>
/**
 * _atoi - Converts a string to an integer.
 * @s: The input string to convert.
 *
 * Description: This function scans the string for digits and converts
 * them into an integer. It accounts for all preceding '-' and '+'
 * signs before the number. If there are no digits in the string,
 * the function returns 0.
 *
 * Return: The integer value represented by the string.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num_started = 0;
	int result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			num_started = 1;

			if (result > (INT_MAX - (s[i] - '0')) / 10)
			{
				if (sign == 1)
					return (INT_MAX);
				else
					return (INT_MIN);
			}

			result = result * 10 + (s[i] - '0');
		}
		else if (num_started)
		{
			break;
		}
		i++;
	}
	return (sign * result);
}
