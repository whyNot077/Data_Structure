
#include "dynamic_array.h"

int main(void)
{
	array	*list;
	node	new_node;

	list = create_list(5);
	for (int i = 0; i < 5; i++)
	{
		new_node.data = i;
		insert_node(list, new_node, i);
	}
	printf("\nmax = %zu, ", list->max_count);
	printf("current = %zu\n", list->current_count);
	display_list(list);

	new_node.data = 5;
	insert_node(list, new_node, 0);
	printf("\nmax = %zu, ", list->max_count);
	printf("current = %zu\n", list->current_count);
	display_list(list);

	new_node.data = 8;
	insert_node(list, new_node, 2);
	printf("\nmax = %zu, ", list->max_count);
	printf("current = %zu\n", list->current_count);
	display_list(list);

	new_node.data = 13;
	insert_node(list, new_node, 2);
	printf("\nmax = %zu, ", list->max_count);
	printf("current = %zu\n", list->current_count);
	display_list(list);

	destroy_list(&list);
	printf("list address: %p\n", list);
	display_list(list);
	return (0);
}