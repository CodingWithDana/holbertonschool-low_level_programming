/**
 * cap_string - Capitalizes all words of a string
 * @str: Pointer to the input string
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0, j;
	char separators[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		/* Capitalize first letter of the string if it's lowercase */
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;

		/* Check if the current character is a separator */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (str[i] == separators[j])
			{
				/* If next character is lowercase, capitalize it */
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
					str[i + 1] = str[i + 1] - 32;
				break;
			}
		}
		i++;
	}
	return (str);
}
