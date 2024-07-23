#include "menger.h"
#include <math.h>

/**
 * draw_sponge - a function recursively draws the 2D Menger Sponge.
 * menger - a function that draws a 2D Menger Sponge.
 *
 * @level: The level of the Menger Sponge to draw.
 * @x: The x-coordinate of the top-left corner of the current sponge.
 * @y: The y-coordinate of the top-left corner of the current sponge.
 * @size: The size of the current sponge.
 *
 * This function uses recursion to draw a Menger Sponge by subdividing
 * the current level's sponge into smaller sponges, leaving the center empty.
 *
 */

void draw_sponge(int level, int x, int y, int size)
{
	int new_size;
	int i;
	int j;
	int k;

	if (level == 0)
	{
		putchar('#');
		return;
	}

	new_size = size / 3;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i == 1 && j == 1)
			{
				k = 0;
				while (k < new_size)
				{
					putchar(' ');
					k++;
				}
			}
			else
			{
				draw_sponge(level - 1, x + i * new_size, y + j * new_size, new_size);
			}
			j++;
		}
		if (i < 2)
		{
			putchar('\n');
		}
		i++;
	}
}

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: The level of the Menger Sponge to draw.
 *
 * This function calculates the size of the sponge and initiates
 * the drawing process by calling the draw_sponge function.
 */

void menger(int level)
{
	int size;

	if (level < 0)
	{
		return;
	}

	size = pow(3, level);

	draw_sponge(level, 0, 0, size);
}
