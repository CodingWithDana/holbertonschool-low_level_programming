#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints multiplication of two numbers, followed by a new line
 * @argc: argument count
 * @argv: argument vector, argv[0] is program name
 * Return: 0 on success, 1 on error
*/
int main(int argc, char *argv[])
{
	/* Declare variable */
	int first_argument_into_number;
	/* Declare variable */
	int second_argument_into_number;
	/* Declare variable */
	int result;

	/* Condition: when argv does not have 3 arguments, prints Error */
	/* 3 arguments include the program name & 2 numbers */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	/* Convert first argument into int */
	first_argument_into_number = atoi(argv[1]);
	/* Convert second argument into int */
	second_argument_into_number = atoi(argv[2]);
	/* Multiply the numbers */
	result = first_argument_into_number * second_argument_into_number;

	/* Print the result */
	printf("%d\n", result);
	return (0);
}
