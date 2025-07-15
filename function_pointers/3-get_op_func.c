#include "3-calc.h"
#include <stdlib.h>
/**
 * get_op_func - selects correct operation function
 * @s: operator string
 * Return: pointer to correct function, otherwise NULL
 */
int (*get_op_func(char *s))(int, int)
{
	/* Declare variables */
	int i;

	/* Create an array of structs to */
	/*	map operators to their corresponding functions */
	op_t ops[] = {
		/* sum */
		{"+", op_add},
		/* subtraction */
		{"-", op_sub},
		/* product */
		{"*", op_mul},
		/* quotient */
		{"/", op_div},
		/* remainder */
		{"%", op_mod},
		/* mark the end */
		{NULL, NULL}
	};

	/* Loop through the array until a match is found */
	while (ops[i].op)
	{
		/* Check if the operator matches and is a single character */
		if ((*ops[i].op) == *s && s[1] == '\0')
		{
			/* Return function pointer */
			return (ops[i].f);
		}
		i++;
	}

	/* If no match, then invalid operator, return NULL */
	return (NULL);
}
