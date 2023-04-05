#include "stack.h"

int push(stack *list, int data)
{
	int top;

	if (list == NULL)
		return (-1);
	if (list->current_count >= list->max_count)
	{
		printf("list is full\n");
		printf("cannot push %d\n", data);
		return (-1);
	}
	top = list->current_count;
	list->stack[top].data = data;
	list->current_count++;
	return (1);
}

int	pop(stack *list)
{
	int top;
	int pop_data;

	if (list == NULL)
		return (-1);
	if (list->current_count <= 0)
	{
		printf("no data\n");
		return (-1);
	}
	list->current_count--;
	top = list->current_count;
	pop_data = list->stack[top].data;
	list->stack[top].data = 0;
	return (pop_data);
}

stack	*create_stack(size_t max_num)
{
	stack	*list;

	list = calloc(1, sizeof(stack));
	if (!list)
		return (NULL);
	list->max_count = max_num;
	list->stack = calloc(max_num, sizeof(node));
	if (!list->stack)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	return (list);
}

void	display_stack(stack *list)
{
	size_t	i;

	i = 0;
	if (!list)
	{
		printf("empty list\n");
		return ;
	}
	printf("\n----------------\n");
	printf(" --> list : ");
	while (i < list->current_count)
	{
		printf("%d ", list->stack[i].data);
		i++;
	}
	printf("\n----------------\n");
}

void	destroy_stack(stack **list)
{
	if (!*list)
		return ;
	if ((*list)->stack != NULL)
	{
		free((*list)->stack);
		(*list)->stack = NULL;
	}
	free(*list);
	*list = NULL;
}