#include <stdio.h>

/**
 * main - Prints numbers from 1 to 100 with FizzBuzz rules
 *        for multiples of three, print Fizz
 *        for multiples of five, print Buzz
 *        for multiples of both, print FizzBuzz
 *
 * Return: 0 on success
 */
int main(void)
{
	int number;

	for (number = 1; number <= 100; number++)
	{
		if (number % 3 == 0 && number % 5 == 0)
			printf("FizzBuzz");
		else if (number % 3 == 0)
			printf("Fizz");
		else if (number % 5 == 0)
			printf("Buzz");
		else
			printf("%d", number);

		if (number != 100)
			printf(" ");
	}
	printf("\n");

	return (0);
}
