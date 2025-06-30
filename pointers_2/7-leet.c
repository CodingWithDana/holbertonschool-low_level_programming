#include "main.h"

/**
 * leet - Encodes a string into 1337 by replacing certain letters.
 * @str: The input string to be encoded (modified in place).
 *
 * Return: Pointer to the encoded string.
 */
char *leet(char *str)
{
	int i = 0, j;
	char letters[] = {'a', 'e', 'o', 't', 'l'};
	char replacements[] = {'4', '3', '0', '7', '1'};

	while (str[i] != '\0')
	{
		j = 0;
		while (j < 5)
		{
			if (str[i] == letters[j] || str[i] == letters[j] - 32)
				str[i] = replacements[j];
			j++;
		}
		i++;
	}
	return (str);
}
