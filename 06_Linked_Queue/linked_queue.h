#ifndef LINKED_QUEUE_H
# define LINKED_QUEUE_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct queue_node {
	int			data;
	struct queue_node	*next;
} queue_node;

typedef struct list {
	queue_node	*headnode;
	queue_node	*rearnode;
} queue;

queue	*create_queue();
queue_node	*create_new_node(int data);
int		enqueue(queue *list, int data);
int		dequeue(queue *list);
void	display_queue(queue *list);
void	destroy_queue(queue **list);

#endif