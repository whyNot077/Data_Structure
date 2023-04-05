#ifndef QUEUE_H
# define QUEUE_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct node_type {
	int	data;
} node;

typedef struct queue_type {
	size_t	size;
	size_t	front;
	size_t	rear;
	node	*queue;
} queue;

queue	*create_queue(size_t size);
int		enqueue(queue *list, int data);
int		dequeue(queue *list);
void	display_queue(queue *list);
void	destroy_queue(queue **list);

#endif