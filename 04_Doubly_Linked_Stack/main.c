#include "doubly_linked_stack.h"

int main()
{
	stack *list;
	
	list = create_stack();
	for (int i = 0; i < 5; i++)
	{
		printf("i = %d, push data = %d\n", i, i);
		push(list, i);
	}
	display_stack(list);
	push(list, 10);
	printf("push data = %d\n", 10);
	display_stack(list);
	push(list, 10);
	printf("push data = %d\n", 10);
	display_stack(list);

	for (int i = 0; i < 10; i++)
	{
		printf("i = %d, pop data = %d\n", i, pop(list));
		display_stack(list);
	}
	destroy_stack(&list);
	display_stack(list);
}