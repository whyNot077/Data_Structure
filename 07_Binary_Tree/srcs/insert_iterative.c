#include "../includes/binary_tree.h"

static int	insert_left_node(tree_node **node, tree_node *new_node)
{
	tree_node	*current;

	current = *node;
	if (current->left == NULL)
	{
		current->left = new_node;
		return (0);
	}
	else
	{
		current = current->left;
		return (insert_left_node(&current, new_node));
	}
}

static int	insert_right_node(tree_node **node, tree_node *new_node)
{
	tree_node	*current;

	current = *node;
	if (current->right == NULL)
	{
		current->right = new_node;
		return (0);
	}
	else
	{
		current = current->right;
		return (insert_right_node(&current, new_node));
	}
}

int	insert_data_iterative(tree_node **node, char *data)
{
	tree_node	*new_node;
	tree_node	*current;
	int			cmp;

	new_node = create_new_node(data);
	if (new_node == NULL)
		return (-1);
	if (*node == NULL)
	{
		*node = new_node;
		return (0);
	}
	current = *node;
	cmp = strcmp(data, current->data);
	if (cmp < 0)
		return (insert_left_node(node, new_node));
	else if (cmp > 0)
		return (insert_right_node(node, new_node));
	else
	{
		free(new_node->data);
		free(new_node);
		return (-1);
	}
}
