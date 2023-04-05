# Why use a doubly-linked Stack?
- Linked Stack data type is useful when you are not sure about the length of the stack. 
- LIFO : last-in, first-out order
- Push: Insert data at the top of stack s
- Pop: Return and remove the top item of stack s

## main
```c
int main()
{
	stack *list;
	
	list = create_stack();
	for (int i = 0; i < 5; i++)
	{
		printf("i = %d, push data = %d\n", i, i);
		push(list, i);
	}
	display_stack(list);
	push(list, 10);
	printf("push data = %d\n", 10);
	display_stack(list);
	push(list, 10);
	printf("push data = %d\n", 10);
	display_stack(list);

	for (int i = 0; i < 10; i++)
	{
		printf("i = %d, pop data = %d\n", i, pop(list));
		display_stack(list);
	}
	destroy_stack(&list);
	display_stack(list);
}
```
## Header
'headnode' ensures access to the first element of the stack, and 'top' helps to access the last element of the stack.
```c
typedef struct stack_node {
	int			data;
	struct stack_node	*next;
	struct stack_node	*prev;
} stack_node;

typedef struct list {
	stack_node	*top;
	stack_node	*headnode;
} stack;
```
## Functions
### create stack
```c
stack	*create_stack()
{
	stack	*list;

	list = calloc(1, sizeof(stack));
	if (!list)
		return (NULL);
	return (list);
}
```
### create new node
```c
stack_node	*create_new_node(int data)
{
	stack_node	*new_node;
	
	new_node = calloc(1, sizeof(stack_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}
```
### push
```c
int push(stack *list, int data)
{
	stack_node	*new_node;
	if (list == NULL)
		return (-1);
	new_node = create_new_node(data);
	if (list->headnode == NULL)
		list->headnode = new_node;
	else
	{
		list->top->next = new_node;
		new_node->prev = list->top;
	}
	list->top = new_node;
	return (0);
}
```

### pop
```c
int	pop(stack *list)
{
	int			data;
	stack_node	*del_node;

	if (list == NULL || list->top == NULL)
		return (-1);
	data = list->top->data;
	del_node = list->top;
	if (list->top->prev == NULL)
	{
		list->top = NULL;
		list->headnode = NULL;
	}
	else
	{
		list->top = list->top->prev;
		list->top->next = NULL;
		del_node->prev = NULL;
	}
	free(del_node);
	del_node = NULL;
	return (data);
}
```

### display stack
```c
void	display_stack(stack *list)
{
	stack_node	*dummy;

	if (list == NULL || list->top == NULL)
	{
		printf("empty list\n");
		return ;
	}
	dummy = list->headnode;
	printf("\n----------------\n");
	printf("\ndisplay_list\n");
	while (dummy != NULL)
	{
		printf("%d ", dummy->data);
		dummy = dummy->next;
	}
	printf("\n----------------\n");
}
```

### destroy stack
```c
void	destroy_stack(stack **list)
{
	stack_node *dummy;
	stack_node *remove;

	if (!*list)
		return ;	
	dummy = (*list)->headnode;
	while (dummy != NULL)
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
```