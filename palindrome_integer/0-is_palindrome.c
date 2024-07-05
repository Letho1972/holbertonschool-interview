#include <stdio.h>

/**
 * is_palindrome - checks whether
 * or not a given unsigned integer is a palindrome
 * @n: unsigned long
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long original = n;
	unsigned long reversed = 0;
	unsigned long remainder;

	/* Inverser le nombre */
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	/* Comparer le nombre original avec l'inverse */
	if (original == reversed)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
