#include <stdio.h>

/**
 * regex_match - Checks whether a given pattern matches a given string.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */

int regex_match(const char *str, const char *pattern);

int regex_match(const char *str, const char *pattern)
/*function regex_match */
{
	/*Base case: if the pattern is empty,the string be empty */
	if (*pattern == '\0')
	{
		return (*str == '\0');
	}

int first_match = (*str != '\0') && (*str == *pattern || *pattern == '.');

	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
				(first_match && regex_match(str + 1, pattern)));
	} else
	{
		return (first_match && regex_match(str + 1, pattern + 1));
	}
}
