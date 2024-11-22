#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: binary tree
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *tmp = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    if (tmp == NULL)
        return (NULL);

    tmp->n = value;
    tmp->left = tmp->right = NULL;
    tmp->parent = parent;
    return (tmp);
}
/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
size_t height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + height(tree->left) : 0;
	height_r = tree->right ? 1 + height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 *         If tree is NULL, return 0
 **/

int binary_tree_is_avl(const binary_tree_t *tree)
{
    int h_l = 0, h_r = 0, diff = 0;
    if(!tree)
            return (1);
    if (tree->left && tree->right)
    {
        h_l = height(tree->left);
        h_r = height(tree->right);
        diff = h_l > h_r ? h_l - h_r : h_r - h_l;
    }

    if(diff < 1)
        return (binary_tree_is_avl(tree->left) & binary_tree_is_avl(tree->right));

    return 0;
}
