#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - Prints the elements of an array between two indices
 * @array: The array to be printed
 * @left: The starting index
 * @right: The ending index
 *
 * Description: This function prints the elements of the array
 * from index `left` to `right` inclusive, separated by commas.
 */
void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	for (size_t i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search - Recursively performs binary search for a value
 * @array: The array to search in
 * @left: The starting index of the search range
 * @right: The ending index of the search range
 * @value: The value to search for
 *
 * Return: The index where the value is found, or -1 if not found.
 *
 * Description: This function performs a binary search recursively
 * and returns the index of the first occurrence of the value.
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	/* Base case: if left index exceeds right index, value is not present */
	if (left > right)
		return (-1);

	/* Print the current subarray */
	print_array(array, left, right);

	mid = left + (right - left) / 2;

	/* If the middle element is the target value, return its index */
	if (array[mid] == value)
	{
		/* Check if this is the first occurrence */
		if (mid == left || array[mid - 1] != value)
			return (mid);
		/* Continue searching on the left side for first occurrence */
		return (binary_search(array, left, mid - 1, value));
	}
	/* If the target value is smaller, search in the left half */
	else if (array[mid] > value)
		return (binary_search(array, left, mid - 1, value));
	/* If the target value is larger, search in the right half */
	else
		return (binary_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - Initiates an advanced binary search
 * @array: The array to search in
 * @size: The size of the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found.
 *
 * Description: This function initiates a binary search on a sorted array
 * and returns the index of the first occurrence of the value.
 * If the array is NULL or the size is 0, it returns -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}
