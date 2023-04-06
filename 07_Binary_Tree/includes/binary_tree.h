#ifndef BINARY_TREE_H
# define BINARY_TREE_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "linked_queue.h"
# include "linked_stack.h"
# include "structure.h"

binarytree	*create_tree(void);
int			insert_data_recursive(tree_node **node, char *data);
int			insert_data_iterative(tree_node **node, char *data);
int			remove_data(binarytree *tree, char *data);
void		inorder(binarytree *tree);
void		preorder(binarytree *tree);
void		postorder(binarytree *tree);
void		levelorder(binarytree *tree);
void		display_tree(binarytree *tree);
void		destroy_tree(binarytree **tree);

//linked queue
queue		*create_queue(void);
int			enqueue(queue *list, tree_node *data);
tree_node	*dequeue(queue *list);
void		display_queue(queue *list);
void		destroy_queue(queue **list);

//linked stack
stack		*create_stack(void);
int			push(stack *list, tree_node *data);
int			pop(stack *list);
void		display_stack(stack *list);
void		destroy_stack(stack **list);

#endif