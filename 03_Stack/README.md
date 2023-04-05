# What is a Stack?
- LIFO : last-in, first-out order
- Push: Insert data at the top of stack s
- Pop: Return and remove the top item of stack s

## main
```c
#include "stack.h"

int main()
{
	stack *list;
	
	list = create_stack(5);
	for (int i = 0; i < 5; i++)
		push(list, i);
	display_stack(list);
	push(list, 10);
	display_stack(list);

	for (int i = 0; i < 5; i++)
	{
		printf("\npop data = %d\n", pop(list));
		display_stack(list);
	}
	printf("pop data = %d\n", pop(list));
	destroy_stack(&list);
	display_stack(list);
}
```

## Header
```c
typedef struct node_type {
	int	data;
} node;

typedef struct stack_type {
	size_t	max_count;
	size_t	current_count;
	node	*stack;
} stack;
```
The header components look similar to Dynamic Arrays because this stack is based on the array. The current_count means to the 'top,' which is the benchmark of push and pop. 

## Functions
### push
Put the data on the top of the stack.
```c
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
```

### pop
Pop the data on the top of the stack

```c
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
```

### create stack
Create, display, and destroy stack is similar to the [Dynamic Arrays](https://github.com/democracyKim/CS_Study/tree/main/Data_Structure/01_Dynamic_Arrays)
 
```c
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
```

### display stack
```c
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
```

### destroy_stack
```c
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
```
