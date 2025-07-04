#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * is_positive_number - checks if the string is a positive integer
 * @s: string to value
 * Return: 0 on success, 1 on error
*/
int is_positive_number(const char *s)
{
	/* Condition: if the string is empty */
	if (s == NULL || s[0] == '\0')
	{
		return (1);
	}

	/* Check each argument to ensure it's a digit */
	while (*s != '\0')
	{
		if (isdigit(*s) != 0)
		{
			return (0);
		}
		s++;
	}
	return (1);
}

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: the sum, otherwise 0 if no number passed to the program,
 * 1 and prints Error if one of the numbers
 * contains symbols (= not a positive number)
 */
int main(int argc, char *argv[])
{
	/* Loop counter */
	int i;
	/* Place to store the sum */
	int sum = 0;

	/* Loop through each argument */
	for (i = 1; i < argc; i++)
	{
		/* If the argument is a digit */
		if (is_positive_number(argv[i]) != 0)
		{
			printf("Error");
			return (1);
		}
		sum = sum + atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
