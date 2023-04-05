#include "circular_queue.h"

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