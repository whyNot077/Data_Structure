#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct node {
	int			data;
	struct node	*next;
} node;

typedef struct list {
	node	*headnode;
} list;

list	*create_linkedlist();
node	*create_new_node(int data);
long long	search_list (list *linked_list, int star);
node	*get_node(list *linked_list, size_t index);
int		insert_node(list *linked_list, size_t index, int data);
int		add_node(list *linked_list, int data);
int		remove_node(list *linked_list, size_t index);
void	display_list(list *linked_list);
void	destroy_list(list **linked_list);

#endif