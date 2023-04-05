# What is a Queue?
- Linked Queue data type is useful when you don't know about the length of the queue. 
- FIFO : first-in, first-out order
- Enqueue: Insert data at the back of the queue
- Dequeue: Return and remove the front item from the queue

## main
```c
int main()
{
	queue *list;
	
	list = create_queue();
	for (int i = 0; i < 5; i++)
		enqueue(list, i);
	display_queue(list);
	printf("enqueue data = %d\n", enqueue(list, 10));
	display_queue(list);
	printf("enqueue data = %d\n", enqueue(list, 10));
	display_queue(list);

	for (int i = 0; i < 10; i++)
	{
		printf("dequeue data = %d\n", dequeue(list));
		display_queue(list);
	}
	destroy_queue(&list);
	display_queue(list);
}
```
## Header
'headnode' ensures access to the first element of the queue, and 'rearnode' helps to access the last element of the queue.
```c
typedef struct queue_node {
	int			data;
	struct queue_node	*next;
} queue_node;

typedef struct list {
	queue_node	*headnode;
	queue_node	*rearnode;
} queue;
```
## Functions
### create queue
```c
queue	*create_queue()
{
	queue	*list;

	list = calloc(1, sizeof(queue));
	if (!list)
		return (NULL);
	return (list);
}
```
### create new node
```c
queue_node	*create_new_node(int data)
{
	queue_node	*new_node;
	
	new_node = calloc(1, sizeof(queue_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}
```
### enqueue
```c
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
```

### dequeue
```c
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
```

### display queue
```c
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
```

### destroy queue
```c
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
```