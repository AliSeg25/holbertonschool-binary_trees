#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (!node->parent)
		return (NULL);
	if (!node->parent->left)
		return (NULL);
	if (!node->parent->right)
		return (NULL);
	if (node->parent->left->n == node->n)
		return (node->parent->right);
	else
		return (node->parent->left);
}
