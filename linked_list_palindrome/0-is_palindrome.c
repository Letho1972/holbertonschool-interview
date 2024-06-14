#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 *
 * Return: 1 if the list is a palindrome, and 0 otherwise
 */



int is_palindrome(listint_t **head)

{

	if (head == NULL || *head == NULL)
		return (1);
	return (is_palindrome_util(head, *head));
}

/**
 * is_palindrome_util - utility function to check if linked list is palindrome
 * @left: pointer to left node in the list
 * @right: pointer to right node in the list
 *
 * Return: 1 if the list is a palindrome, and 0 otherwise
 */

int is_palindrome_util(listint_t **left, listint_t *right)
{
	int is_pal;

	if (right == NULL)
		return (1);


if (right == NULL)
	{
	return (1);
	}

	is_pal = is_palindrome_util(left, right->next) && ((*left)->n == right->n);

	*left = (*left)->next;

	return (is_pal);
}
