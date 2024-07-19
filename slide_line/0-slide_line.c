#include <stddef.h>
#include <stdint.h>
#include "slide_line.h"

/**
 * slide_line - A function that slides and merges an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 *
 */

static void slide_left(int *line, size_t size);
static void slide_right(int *line, size_t size);
static void merge_left(int *line, size_t size);
static void merge_right(int *line, size_t size);

/**
 * slide_line - Prints out an array of integer, followed by a new line
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * @direction: The direction we slide to
 * Return: 0 ou 1
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	{
		return (0);
	}

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		merge_left(line, size);
		slide_left(line, size);
	}
	else
	{
		slide_right(line, size);
		merge_right(line, size);
		slide_right(line, size);
	}

	return (1);
}

/**
 * slide_left - slide to the left of the array
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void slide_left(int *line, size_t size)
{
	size_t pos = 0;
	size_t i = 0;

	while (i < size)
	{
		if (line[i] != 0)
		{
			line[pos++] = line[i];
		}
		i++;
	}
	while (pos < size)
	{
		line[pos++] = 0;
	}
}
/**
 * slide_right - slide to the left of the array
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void slide_right(int *line, size_t size)
{
	size_t pos = size - 1;
	int i = size - 1;

	while (i >= 0)
	{
		if (line[i] != 0)
		{
			line[pos--] = line[i];
		}
		i--;
	}
	while (pos != SIZE_MAX)
	{
		line[pos--] = 0;
	}
}
/**
 * merge_left - slide to the left of the array
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void merge_left(int *line, size_t size)
{
	size_t i = 0;

	while (i < size - 1)
	{
		if (line[i] == line[i + 1] && line[i] != 0)
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
		i++;
	}
}
/**
 * merge_right - slide to the left of the array
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void merge_right(int *line, size_t size)
{
	size_t i = size - 1;

	while (i > 0)
	{
		if (line[i] == line[i - 1] && line[i] != 0)
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
		i--;
	}
}
