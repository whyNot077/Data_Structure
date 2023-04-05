#include "linked_list.h"

list	*create_linkedlist()
{
	list *linked_list;
	linked_list = calloc(1, sizeof(list));
	if (linked_list == NULL)
		return (NULL);
	return (linked_list);
}


node	*create_new_node(int data)
{
	node	*new_node;
	
	new_node = calloc(1, sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}

long long	search_list(list *linked_list, int star)
{
	size_t	index;
	node	*dummy;

	index = 0;
	if (linked_list == NULL || linked_list->headnode == NULL)
		return (-1);
	dummy = linked_list->headnode;
	while (dummy && dummy->next)
	{
		if (dummy->data == star)
			return (index);
		dummy = dummy->next;
		index++;
	}
	return (-1);
}

node	*get_node(list *linked_list, size_t index)
{
	size_t 	i;
	node	*dummy;

	i = 0;
	if (linked_list == NULL)
		return (NULL);
	dummy = linked_list->headnode;
	while ((i < index) && dummy && dummy->next)
	{
		dummy = dummy->next;
		i++;
	}
	if (i == index)
		return (dummy);
	return (NULL);
}

int		insert_node(list *linked_list, size_t index, int data)
{
	node	*before_node;
	node	*new_node;

	if (linked_list == NULL)
		return (0);
	new_node = create_new_node(data);
	if (new_node == NULL)
		return (0);
	if (index == 0)
	{
		new_node->next = linked_list->headnode;
		linked_list->headnode = new_node;
		return (1);
	}
	before_node = get_node(linked_list, index - 1);
	if (before_node == NULL)
		return (0);
	new_node->next = before_node->next;
	before_node->next = new_node;
	return (1);
}

int		add_node(list *linked_list, int data)
{
	node	*dummy;
	node	*new_node;

	if (linked_list == NULL)
		return (0);
	dummy = linked_list->headnode;
	new_node = create_new_node(data);
	if (dummy == NULL)
	{
		linked_list->headnode = new_node;
		return (1);
	}
	if (new_node == NULL)
		return (0);
	while (dummy && dummy->next)
		dummy = dummy->next;
	dummy->next = new_node;
	return (1);
}

int		remove_node(list *linked_list, size_t index)
{
	node *before_node;
	node *remove_node;

	if (index == 0)
	{
		remove_node = linked_list->headnode;
		linked_list->headnode = remove_node->next;
		free(remove_node);
		return (1);
	}
	before_node = get_node(linked_list, index - 1);
	if (before_node == NULL)
		return (0);
	remove_node = before_node->next;
	if (remove_node == NULL)
		return (0);
	before_node->next = remove_node->next;
	free(remove_node);
	return (1);
}

void	display_list(list *linked_list)
{
	node	*dummy;
	int		index;

	index = 0;
	if (!linked_list || !linked_list->headnode)
	{
		printf("no list\n");
		return ;
	}
	dummy = linked_list->headnode;
	printf("\ndisplay_list\n");
	while (dummy)
	{
		printf("[%d] %d ", index++, dummy->data);
		dummy = dummy->next;
	}
	printf("\n");
}

void	destroy_list(list **linked_list)
{
	node *dummy;
	node *remove;

	if (!*linked_list)
		return ;	
	dummy = (*linked_list)->headnode;
	while (dummy)
	{
		remove = dummy;
		dummy = dummy->next;
		free(remove);
		remove = NULL;
	}
	free(*linked_list);
	*linked_list = NULL;
	printf("destroy complete\n");
}