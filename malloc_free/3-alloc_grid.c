#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - returns a 2D array of integers
 * @width: number of columns
 * @height: number of rows
 * Return: pointer to a 2D array of integers
 * otherwise NULL if program on failure,
 * or NULL if the width or height <= 0
 */
int **alloc_grid(int width, int height)
{
	int i;
	int j;
	int **grid;

	/* Check for invalid input */
	if (width <= 0 || height <= 0)
		return (NULL);

	/* Allocate memory for array of row pointers */
	grid = malloc(sizeof(int *) * height);
	/* Check for when memory allocation fails */
	if (grid == NULL)
		return (NULL);

	/* Allocate memory for each row and initialize to 0 */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			/* Free already allocated rows if one row fails */
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}

		/* Initialize each elemnent to 0 */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
