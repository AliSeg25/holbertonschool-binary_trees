#include "binary_trees.h"

/**
 * depth - depth of the binary tree
 * @tree: pointer
 * Return: d
 */

int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect - check if the binary tree is perfect or not
 * @tree: pointer
 * @d: int
 * @level: level of the tree
 * Return: recursive and 0 on failure
*/

int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (d == level + 1);
	if (!tree->left || !tree->right)
		return (0);
	return (is_perfect(tree->left, d, level + 1) &&
		is_perfect(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If node is NULL, return 0
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = depth(tree);

	if (!tree)
		return (0);
	return (is_perfect(tree, d, 0));
}
