#include "main.h"
/**
 * rev_string - reverses a string,
 *
 * @s: pointer to a string to print
 * Description: This function reverses a string
 * Return: void
 */

void rev_string(char *s)
{
	char *start = s;
	char *end = s;
	char temp;

	while (*end != '\0')
	{
		end++;
	}

	end--;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
