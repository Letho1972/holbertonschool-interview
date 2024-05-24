#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_up - Ensures the max heap property by swapping nodes up
 * @node: Pointer to the node to heapify up
 * Return: Pointer to the node after heapify
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * find_insertion_point - Finds the insertion point for the new node
 * @root: Pointer to the root of the heap
 * Return: Pointer to the parent of the new node
 */
heap_t *find_insertion_point(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *node = queue[front++];

		if (!node->left || !node->right)
			return (node);

		queue[rear++] = node->left;
		queue[rear++] = node->right;
	}
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert into the heap
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *new_node;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_insertion_point(*root);

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}
