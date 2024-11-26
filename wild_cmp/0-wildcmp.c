#include <stdio.h>

/**
 * compare - compares two strings
 * @first: first string
 * @second: second string
 * Return: 1 if the strings can be considered identical, otherwise return 0
**/

int compare(char *first, char *second)
{

	if (*first == '\0' && *second == '\0')
		return (1);

	if (*first == '*' && *(first + 1) != '\0' && *second == '\0')
		return (0);

	if (*first == *second)
		return (compare(first + 1, second + 1));

	if (*first == '*')
		return (compare(first + 1, second) || compare(first, second + 1));
	return (0);
}


/**
 * wildcmp - returns the results
 * @s1: first string
 * @s2: second string
 * s2 can contain the special character *.
 * The special char * can replace any string (including an empty string)
 * Return: 1 if the strings can be considered identical, otherwise return 0
**/

int wildcmp(char *s1, char *s2)
{
	return (compare(s2, s1));
}
