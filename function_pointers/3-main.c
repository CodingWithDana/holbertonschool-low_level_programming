#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point of the calculator program
 * @argc: number of arguments
 * @argv: array of strings representing the arguments
 * Return: 0 on success, otherwise error codes
 */
int main(int argc, char *argv[])
{
	/* Define operands */
	int num1;
	int num2;
	/* Function pointer to the correct operation */
	int (*operation)(int, int);

	/* If the number of arguments is incorrect, print error and exit with 98 */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* Choose the correct function for the operator, otherwise error code for invalid operator */
	operation = get_op_func(argv[2]);
	if (operation == NULL)
	{
		printf("Error\");
		exit(99);
	}

	/* Convert the operand strings to integers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3);

	/* Check for division or modulo by 0 */
	if ((argv[2][0] == '/' || argv[2][0] = '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	/* Perform the operation and print the result */
	printf("%d\n", operation(num1, num2));

	return (0);
}
