#include <stdio.h>

/**
 * main - prints alphabets in lowercase except e and q,
 *        followed by a new line
 *
 * Return: 0 on success
 */
int main(void)
{
    char c;

    for (c = 'a'; c <= 'z'; c++)
    {
        if (c != 'e' && c != 'q')
            putchar(c);
    }
    putchar('\n');

    return (0);
}
