# What is a Queue?
- FIFO : first-in, first-out order
- Enqueue: Insert data at the back of the queue
- Dequeue: Return and remove the front item from the queue

## main
```c
int main()
{
	queue *list;
	
	list = create_queue(5);
	for (int i = 0; i < 5; i++)
		enqueue(list, i);
	display_queue(list);
	printf("enqueue data = %d\n", enqueue(list, 10));
	display_queue(list);

	for (int i = 0; i < 5; i++)
	{
		printf("dequeue data = %d\n", dequeue(list));
		display_queue(list);
	}
	printf("dequeue data = %d\n", dequeue(list));
	destroy_queue(&list);
	display_queue(list);
}
```
## Header
```c
typedef struct node_type {
	int	data;
} node;

typedef struct stack_type {
	size_t	size;
	size_t	front;
	size_t	rear;
	node	*queue;
} queue;
```
## Functions
### create queue
Make and initialize queue. Make 'size + 1'. We need size spaces for data and one slot for '\0'. Because if there is no room for null, the circular queue data type is hard to distinguish between full and empty when the front and rear point to the same area. 
```c
queue	*create_queue(size_t size)
{
	queue	*list;

	list = calloc(1, sizeof(queue));
	if (!list)
		return (NULL);
	list->size = size + 1;
	list->queue = calloc(size + 1, sizeof(node));
	if (!list->queue)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	return (list);
}
```

### enqueue
Insert data at the back of the queue.  
Increment the rear by 1. If the rear is equal to the size, make this 0. 
```c
int enqueue(queue *list, int data)
{
	int rear;

	if (list == NULL)
		return (-1);
	if ((list->rear + 1) % (list->size) == list->front)
	{
		printf("list full\n");
		printf("cannot enqueue %d\n", data);
		return (-1);
	}
	rear = list->rear;
	list->queue[rear].data = data;
	list->rear = (list->rear + 1) % (list->size);
	return (1);
}
```

### dequeue
Return and remove the front item from the queue.  
Increment front by 1. If the front is equal to the size, make this 0. 
```c
int	dequeue(queue *list)
{
	int front;
	int data;

	if (list == NULL)
		return (-1);
	if (list->front == list->rear)
	{
		printf("no data\n");
		return (-1);
	}
	front = list->front;
	data = list->queue[front].data;
	list->queue[front].data = 0;
	list->front = (list->front + 1) % (list->size);
	return (data);
}
```

### display queue
```c
void	display_queue(queue *list)
{
	size_t	front;

	front = list->front;
	if (!list)
	{
		printf("no list\n");
		return ;
	}
	printf("\n----------------\n");
	printf("front : %zu , rear : %zu\n", list->front, list->rear);
	printf("list : ");
	while (front < list->rear)
	{
		printf("%d ", list->queue[front].data);
		front++;
	}
	printf("\n----------------\n");
}
```

### destroy queue
```c
void	destroy_queue(queue **list)
{
	if (!*list)
		return ;
	if ((*list)->queue != NULL)
	{
		free((*list)->queue);
		(*list)->queue = NULL;
	}
	free(*list);
	*list = NULL;
}
```