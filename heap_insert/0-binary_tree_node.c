#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - A function
 * that creates a binary tree node.
 * @parent: A pointer to the parent
 * node of the node to create.
 * @value: The value to put in the new node.
 * Return: the created node of the tree.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_tree;

	new_tree = malloc(sizeof(*parent));

	if (new_tree == NULL)
	{
		return (NULL);
	}

	if (parent == NULL)
	{
		new_tree->n = value;
		new_tree->left = NULL;
		new_tree->right = NULL;
		new_tree->parent = NULL;

		return (new_tree);
	}
	new_tree->n = value;
	new_tree->left = NULL;
	new_tree->right = NULL;
	new_tree->parent = parent;

	return (new_tree);
}
