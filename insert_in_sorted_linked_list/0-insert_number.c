#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - a function that insert a node in
 * a linked list.
 * @head: a pointer to the head of a list.
 * @number: an int variable to assign to the node.
 * Return: the created node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *currentNode = *head;
	listint_t *prevNode = NULL;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = number;
	newNode->next = NULL;

	if (*head == NULL || number < (*head)->n)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	while (currentNode != NULL && currentNode->n < number)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
	}

	prevNode->next = newNode;
	newNode->next = currentNode;
	return (newNode);
}
