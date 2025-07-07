#include "main.h"
#include <stdlib.h>
/**
 * free_grid - frees the 2D grid created by alloc_grid function
 * @grid: pointer to the 2D grid
 * @height: number of rows
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	/* Check for invalid grid before freeing */
	if (grid == NULL || height <= 0)
		return;

	/* Free each row */
	for (i = 0; i < height; i++)
		free(grid[i]);

	/* Free the array of row pointers */
	free(grid);

}
