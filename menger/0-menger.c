#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* is_empty - Determine if a given position should be empty
* @row: the row
* @column: the column
*
* This function checks if a given position in a Menger Sponge at a certain
* level is empty or filled. It does so by iterating through each level
* and checking if the current position is in the middle third.
*
* Return: 1 if position is empty else 0
*
*/

int is_empty(int row, int column)

{
	while (row > 0 || column > 0)
	{
		/*Check if he current position at any level is in the middle third*/
		if (row % 3 == 1 && column % 3 == 1)
			return (1);
		/*Move to the next level*/
		row /= 3;
		column /= 3;
	}
	return (0);
}

/**
* menger - Draws a 2D Menger Sponge
* @level: The level of the Menger Sponge to draw
*
* This function prints a 2D representation of a Menger Sponge of given level.
* It calculates the size of the sponge, iterates over each position, and
* determines whether it should be empty or filled by calling
* the is_empty function.
*/
void menger(int level)
{
	int size, row, column;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			if (is_empty(row, column))
				printf(" "); /* empty position*/
			else
				printf("#"); /*filled position*/
		}
		printf("\n"); /*move to the next line*/
	}
}
