#include "../includes/binary_tree.h"

static void	traverse_left(tree_node **parent, tree_node **current)
{
	*parent = *current;
	*current = (*current)->left;
}

static void	traverse_right(tree_node **parent, tree_node **current)
{
	*parent = *current;
	*current = (*current)->right;
}

static int	remove_leaf_node(binarytree *tree, \
	tree_node *parent, tree_node *current)
{
	if (parent == NULL)
		tree->root = NULL;
	else if (parent->left == current)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(current->data);
	free(current);
	return (0);
}

static int	remove_node_with_right_child(binarytree *tree, \
	tree_node *parent, tree_node *current)
{
	if (parent == NULL)
		tree->root = current->right;
	else if (parent->left == current)
		parent->left = current->right;
	else
		parent->right = current->right;
	free(current->data);
	free(current);
	return (0);
}

static int	remove_node_with_left_child(binarytree *tree, \
	tree_node *parent, tree_node *current)
{
	if (parent == NULL)
		tree->root = current->left;
	else if (parent->left == current)
		parent->left = current->left;
	else
		parent->right = current->left;
	free(current->data);
	free(current);
	return (0);
}

static int	remove_node_with_two_children(binarytree *tree, tree_node *current)
{
	tree_node	*min_node;
	tree_node	*min_node_parent;

	min_node = current->right;
	min_node_parent = current;
	while (min_node->left != NULL)
	{
		min_node_parent = min_node;
		min_node = min_node->left;
	}
	free(current->data);
	current->data = strdup(min_node->data);
	if (min_node_parent->left == min_node)
		min_node_parent->left = min_node->right;
	else
		min_node_parent->right = min_node->right;
	free(min_node->data);
	free(min_node);
	return (0);
}

int	remove_data_iterative(binarytree *tree, char *data)
{
	tree_node	*parent;
	tree_node	*current;
	int			cmp;

	if (tree == NULL || tree->root == NULL)
		return (-1);
	current = tree->root;
	parent = NULL;
	while (current != NULL)
	{
		cmp = strcmp(data, current->data);
		if (cmp < 0)
			traverse_left(&parent, &current);
		else if (cmp > 0)
			traverse_right(&parent, &current);
		else
		{
			if (current->left == NULL && current->right == NULL)
				return (remove_leaf_node(tree, parent, current));
			else if (current->left == NULL)
				return (remove_node_with_right_child(tree, parent, current));
			else if (current->right == NULL)
				return (remove_node_with_left_child(tree, parent, current));
			else
				return (remove_node_with_two_children(tree, current));
		}
	}
	return (0);
}
