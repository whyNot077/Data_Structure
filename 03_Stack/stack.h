#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct node_type {
	int	data;
} node;

typedef struct stack_type {
	size_t	max_count;
	size_t	current_count;
	node	*stack;
} stack;

int		push(stack *list, int data);
int		pop(stack *list);
stack	*create_stack(size_t max_num);
void	display_stack(stack *list);
void	destroy_stack(stack **list);

#endif