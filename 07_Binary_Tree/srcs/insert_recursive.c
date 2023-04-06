#include "../includes/binary_tree.h"

int	insert_data_recursive(tree_node **node, char *data)
{
	int	cmp;

	if (*node == NULL)
	{
		*node = create_new_node(data);
		if (*node == NULL)
			return (-1);
		else
			return (0);
	}
	cmp = strcmp(data, (*node)->data);
	if (cmp < 0)
		return (insert_data_recursive(&(*node)->left, data));
	else if (cmp > 0)
		return (insert_data_recursive(&(*node)->right, data));
	else
		return (-1);
}
