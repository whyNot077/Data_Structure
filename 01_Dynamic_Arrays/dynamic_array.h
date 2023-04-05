#ifndef DYNAMIC_ARRAY_H
# define DYNAMIC_ARRAY_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct node_type {
	int	data;
} node;

typedef struct array_type {
	size_t	max_count;
	size_t	current_count;
	node	*array;
} array;

array	*create_list(size_t max_num);
node	*get_node(array *list, size_t index);
int		is_full(array *list);
int		insert_node(array *list, node new_node, size_t index);
int		remove_node(array *list, size_t index);
void	display_list(array *list);
void	destroy_list(array **list);

#endif