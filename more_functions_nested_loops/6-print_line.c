#include "main.h"
#include <stdio.h>
/**
 * print_line - Prints a straight line
 * of underscores without space 
 * @n : number of underscores to print
 * Return: void
 */

void print_line(int n)
{
  int i = 0;

  while (i < n)
    {
      _putchar('_');
      i++;
    }
  _putchar('\n');
}
  
