#include "binary_trees.h"

/**
 * tree_is_perfect - Helper function to check if a binary tree is perfect
 * @tree: Pointer to the root node
 * @d: Depth of the tree
 * @level: Current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int tree_is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (tree_is_perfect(tree->left, d, level + 1) &&
		tree_is_perfect(tree->right, d, level + 1));
}

/**
 * get_depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Depth of the tree
 */
int get_depth(const binary_tree_t *tree)
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
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, otherwise 0. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = get_depth(tree);
	return (tree_is_perfect(tree, d, 0));
}
