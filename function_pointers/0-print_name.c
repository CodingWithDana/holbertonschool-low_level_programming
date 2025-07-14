#include "function_pointers.h"
#include <stdlib.h>
/**
 * print_name - calls this function to print a name
 * @name: the name to print
 * @f: pointer to a function that prints a name
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	/* Condition: both name and function pointer are not NULL */
	if (name != NULL && f != NULL)
	{
		/* Call the function "f" and pass the name to it */
		f(name);
	}
}
