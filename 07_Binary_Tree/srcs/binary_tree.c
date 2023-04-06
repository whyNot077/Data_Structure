#include "../includes/binary_tree.h"

binarytree	*create_tree(void)
{
	binarytree	*tree;

	tree = calloc(sizeof(binarytree));
	if (!tree)
		return (NULL);
	return (tree);
}

static tree_node	*create_new_node(char *data)
{
	tree_node	*new_node;

	new_node = calloc(1, sizeof(tree_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}
