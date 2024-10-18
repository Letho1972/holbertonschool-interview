#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted halves of an array
 * @array: The original array containing the two halves
 * @temp: Temporary array to store sorted elements
 * @start: The start index of the first half
 * @mid: The end index of the first half and start index of the second half
 * @end: The end index of the second half
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = start;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (i < mid && j < end)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < end)
		temp[k++] = array[j++];

	for (i = start; i < end; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_recursive - Recursively sorts an array using merge sort
 * @array: The array to be sorted
 * @temp: Temporary array to store sorted elements
 * @start: The start index of the array segment
 * @end: The end index of the array segment
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end)
{
	if (end - start < 2)
		return;

	size_t mid = start + (end - start) / 2;

	merge_sort_recursive(array, temp, start, mid);
	merge_sort_recursive(array, temp, mid, end);
	merge(array, temp, start, mid, end);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
