#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: The level of the Menger Sponge to draw.
 *
 * This function calculates the size of the sponge and initiates
 * the drawing process by calling the draw_sponge function.
 */

void menger(int level);

/**
 * draw_sponge - Recursively draws the 2D Menger Sponge.
 * @level: The level of the Menger Sponge to draw.
 * @x: The x-coordinate of the top-left corner of the current sponge.
 * @y: The y-coordinate of the top-left corner of the current sponge.
 * @size: The size of the current sponge.
 *
 * This function uses recursion to draw a Menger Sponge by subdividing
 * the current level's sponge into smaller sponges, leaving the center empty.
 */

void draw_sponge(int level, int x, int y, int size);

#endif
