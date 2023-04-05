#include "linked_queue.h"

queue	*create_queue()
{
	queue	*list;

	list = calloc(1, sizeof(queue));
	if (!list)
		return (NULL);
	return (list);
}

queue_node	*create_new_node(int data)
{
	queue_node	*new_node;
	
	new_node = calloc(1, sizeof(queue_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}

int enqueue(queue *list, int data)
{
	queue_node	*new_node;
	if (list == NULL)
		return (-1);
	new_node = create_new_node(data);
	if (list->headnode == NULL)
		list->headnode = new_node;
	else
		list->rearnode->next = new_node;
	list->rearnode = new_node;
	return (0);
}

int	dequeue(queue *list)
{
	int		data;
	queue_node	*del_node;

	if (list == NULL || list->headnode == NULL)
		return (-1);
	data = list->headnode->data;
	del_node = list->headnode;
	list->headnode = list->headnode->next;
	free(del_node);
	del_node = NULL;
	return (data);
}

void	display_queue(queue *list)
{
	queue_node	*dummy;

	if (list == NULL || list->headnode == NULL)
	{
		printf("no list\n");
		return ;
	}
	dummy = list->headnode;
	printf("\n----------------\n");
	printf("\ndisplay_list\n");
	while (dummy)
	{
		printf("%d ", dummy->data);
		dummy = dummy->next;
	}
	printf("\n----------------\n");
}

void	destroy_queue(queue **list)
{
	queue_node *dummy;
	queue_node *remove;

	if (!*list)
		return ;	
	dummy = (*list)->headnode;
	while (dummy)
	{
		remove = dummy;
		dummy = dummy->next;
		free(remove);
		remove = NULL;
	}
	free(*list);
	*list = NULL;
	printf("destroy complete\n");
}