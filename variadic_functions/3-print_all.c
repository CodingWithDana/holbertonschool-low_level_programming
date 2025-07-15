#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - prints anything
 * @format: a string of format specifiers ('c', 'i', 'f', 's')
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i;
	char *str;
	char *sepa = "";

	i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		(format[i] == 'c') &&
			(printf("%s%c", sepa, va_arg(args, int)),
			 (sepa = ", "),
			 0);

		(format[i] == 'i') &&
			(printf("%s%d", sepa, va_arg(args, int)),
			 (sepa = ", "),
			 0);

		(format[i] == 'f') &&
			(printf("%s%f", sepa, va_arg(args, double)),
			 (sepa = ", "),
			 0);

		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", sepa, str);
			sepa = ", ";
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
