#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet 10 times, in lowercase,
 * each followed by a new line
 * Return: 0 on success
 */
void print_alphabet_x10(void)
{
	int line;
	char letter;

	for (line = 0; line < 10; line++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
		_putchar('\n');
	}
}
