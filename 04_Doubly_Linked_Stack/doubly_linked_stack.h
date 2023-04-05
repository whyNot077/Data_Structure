#ifndef LINKED_STACK_H
# define LINKED_STACK_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct stack_node {
	int			data;
	struct stack_node	*next;
	struct stack_node	*prev;
} stack_node;

typedef struct list {
	stack_node	*top;
	stack_node	*headnode;
} stack;

stack		*create_stack();
stack_node	*create_new_node(int data);
int			push(stack *list, int data);
int			pop(stack *list);
void		display_stack(stack *list);
void		destroy_stack(stack **list);

#endif