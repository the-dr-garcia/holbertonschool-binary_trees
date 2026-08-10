#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures the height of a binary tree for balance
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
	right_h = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;

	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h = 0;
	int right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_h = (int)binary_tree_height_b(tree->left);
	else
		left_h = 0;

	if (tree->right != NULL)
		right_h = (int)binary_tree_height_b(tree->right);
	else
		right_h = 0;

	return (left_h - right_h);
}
