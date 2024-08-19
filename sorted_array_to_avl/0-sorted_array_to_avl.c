#include <stdlib.h>
#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size);

/**
 * create_avl - Aide à créer un arbre AVL à partir d'un tableau trié
 * @array: Pointeur vers le tableau trié
 * @start: Indice de début du sous-tableau
 * @end: Indice de fin du sous-tableau
 * @parent: Pointeur vers le parent du nœud courant
 *
 * Return: Pointeur vers le nœud créé
 */
avl_t *create_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;
	node->left = create_avl(array, start, mid - 1, node);
	node->right = create_avl(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Convertit un tableau trié en un arbre AVL
 * @array: Pointeur vers le premier élément du tableau
 * @size: Nombre d'éléments dans le tableau
 *
 * Return: Pointeur vers la racine de l'arbre AVL créé
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (create_avl(array, 0, size - 1, NULL));
}
