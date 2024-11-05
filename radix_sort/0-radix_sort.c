#include "sort.h"

/**
 * radix_sort - sorts an array of ints in ascending order
 * using least significant digit radix sorting algorithm
 *
 * @array: array of ints to sort
 * @size: size of the array of ints
 *
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i = 0;
	int *holder = NULL;
	int digit_count = 0, current_digit = 0, divisor = 0;

	/* Check if inputs are valid or if there is enough info to sort */
	if (array == NULL || size < 2)
		return;
	/* allocate memory for temp array, same size as input array */
	holder = malloc(sizeof(int) * size);
	if (holder == NULL)
		return;
	/* set digit count as the max amount of digits in int in array */
	digit_count = digit_counting(array, size);
	/* while our current digit count is not the max digit count, continue */
	while (current_digit < digit_count)
	{
		/* loop through each int */
		for (i = 0; i < size; i++)
		{
			/* get single digit by dividing by power of 10 */
			divisor = get_divisor(current_digit);
			/* sorts & inserts value from array into holder */
			insert_into_holder(array[i], divisor, holder, i);
		}
		/* copy holder into array, print, & move to next digit*/
		for (i = 0; i < size; i++)
			array[i] = holder[i];
		print_array(array, size);
		current_digit++;
	}
	/* free temporary holder array when finished moving */
	free(holder);
}

/**
 * digit_counting - counts the max number of digits in array of ints
 *
 * @array: input array of ints to count digits of
 * @size: size of the array of ints
 *
 * Return: largest digit count of all ints in array
 */
int digit_counting(int *array, size_t size)
{
	unsigned int i = 0;
	int current_count = 0, max_count = 0, n = 0;

	/* loops through all ints in array */
	for (i = 0; i < size; i++)
	{
		/* gets the int value and sets counter to start at 1 */
		n = array[i];
		current_count = 1;
		/* while number is divisible, count increases and */
		/*   the last digit is cut off by dividing by 10 */
		while (n / 10 != 0)
		{
			current_count++;
			n /= 10;
		}
		/* resets max digit count if just calculated count is larger */
		if (current_count > max_count)
			max_count = current_count;
	}
	/* returns the largest digit count found */
	return (max_count);
}

/**
 * get_divisor - sets the divisor to get the current digit of a number
 *
 * @current_digit: current digit count to set divisor for
 *
 * Return: divisor for corresponding digit
 */
int get_divisor(int current_digit)
{
	int i = 0, divisor = 1;

	/* to get specific digit, divisor needs to be set to power of ten */
	/* divisor represents ones place, tens place, hundreds place, etc */
	for (i = 0; i < current_digit; i++)
		divisor *= 10;
	return (divisor);
}

/**
 * insert_into_holder - inserts current value from array into holder,
 * sorted by current digit
 *
 * @value: the current int value from array
 * @divisor: the current divisor to get the digit
 * @holder: the temp array to store values sorted by current digit
 * @i: the current index value of array and holder
 */
void insert_into_holder(int value, int divisor, int *holder, unsigned int i)
{
	unsigned int j = 0, k = 0;
	int n = 0, m = 0;

	/* gets the current digit of the value */
	n = (value / divisor) % 10;
	/* if first value, input directly into holder */
	if (i == 0)
		holder[i] = value;
	else
	{
		/* compare n to same digits stored in holder */
		for (j = 0; j < i; j++)
		{
			m = (holder[j] / divisor) % 10;
			/* break if need to insert before end */
			if (m > n)
				break;
		}
		/* if place to insert is not the last spot, */
		/*   shift cuurent holder values over 1 spot */
		if (j != i)
		{
			for (k = i; k > j; k--)
				holder[k] = holder[k - 1];
		}
		/* insert the new value into holder, sorted by current digit */
		holder[j] = value;
	}
}
