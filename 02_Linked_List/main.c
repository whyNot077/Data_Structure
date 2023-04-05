
#include "linked_list.h"

int main(void)
{
	list *linked_list;

	linked_list = create_linkedlist();
	for (int i = 0; i < 10; i++)
		add_node(linked_list, i);
	display_list(linked_list);

	remove_node(linked_list, -1111);
	display_list(linked_list);
	
	remove_node(linked_list, 0);
	display_list(linked_list);
	
	remove_node(linked_list, 1);
	display_list(linked_list);
	
	remove_node(linked_list, 9999);
	display_list(linked_list);
	
	remove_node(linked_list, 6);
	display_list(linked_list);
	
	insert_node(linked_list, 2, 100);
	display_list(linked_list);
	
	printf("\nsearch 100, index = %lld\n", search_list(linked_list, 100));
	insert_node(linked_list, 1111, 1000);
	display_list(linked_list);
	
	printf("\nsearch 1000, index = %lld\n", search_list(linked_list, 1000));
	destroy_list(&linked_list);
	printf("linked_list address: %p\n", linked_list);
	display_list(linked_list);
	
	printf("complete\n");
}