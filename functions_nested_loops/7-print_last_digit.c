#include "main.h"
#include <stdio.h>

/**
 * print_last_digit - Print the last digit of a number
 * @n: The integer to check
 *
 * Return: The last digit of the number
 */
int print_last_digit(int n)
{
    int last_digit = n % 10;

    if (last_digit < 0)
        last_digit = -last_digit;

    _putchar( '0' + last_digit);
    
    return last_digit;
}
