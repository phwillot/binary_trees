#include "binary_trees.h"
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree
 * @value: the value to remove in the tree
 *
 * Return: pointer to the new root node of the
 * tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *temp;

	node = bst_search(root, value);
	if (root == NULL || node == NULL)
		return (NULL);
	if (node->left == NULL && node->right == NULL)
		free(node);
	else if (node->left && node->right == NULL)
	{
		node->left->parent = node->parent;
		if (node->parent->left->n == node->n)
			node->parent->left = node->left;
		else
			node->parent->right = node->left;
		free(node);
	}
	else if (node->left == NULL && node->right)
	{
		node->right->parent = node->parent;
		if (node->parent->right->n == node->n)
			node->parent->right = node->right;
		else
			node->parent->left = node->right;
		free(node);
	}
	else
	{
		temp = node, temp = temp->right;
		while (temp->left)
			temp = temp->left;
		temp->left = node->left, temp->right = node->right;
		node->left->parent = temp, node->right->parent = temp;
		if (node->parent)
		{
			temp->parent->left = NULL, temp->parent = node->parent;
			if (node->parent->left->n == node->n)
				node->parent->left = temp;
			else
				node->parent->right = temp;
			free(node);
			return (root);
		}
		temp->parent->left = NULL, temp->parent = NULL;
		free(node), root = temp;
	}
	return (root);
}

/**
 * bst_search - Searches for a value in a BST
 * @tree: pointer to the root node of the BST
 * @value: value to search in the tree
 * Return: pointer to the containing the value or NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);

		if (value < tree->n)
			tree = tree->left;

		else
			tree = tree->right;
	}
	return (NULL);
}