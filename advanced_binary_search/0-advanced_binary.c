#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the array or subarray
 * @array: The array to print
 * @low: Starting index
 * @high: Ending index
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Helper to perform the recursive binary search
 * @array: The array to search
 * @low: Starting index of the search range
 * @high: Ending index of the search range
 * @value: The value to search for
 *
 * Return: Index of the value, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);

	mid = low + (high - low) / 2;

	if (array[mid] == value && (mid == low || array[mid - 1] != value))
		return (mid);

	if (array[mid] >= value)
		return (advanced_binary_recursive(array, low, mid, value));

	return (advanced_binary_recursive(array, mid + 1, high, value));
}

/**
 * advanced_binary - Searches for a value in a sorted
 * array using advanced binary search
 * @array: A pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
