#include "stack.h"

int main()
{
	stack *list;
	
	list = create_stack(5);
	for (int i = 0; i < 5; i++)
		push(list, i);
	display_stack(list);
	push(list, 10);
	display_stack(list);

	for (int i = 0; i < 5; i++)
	{
		printf("\npop data = %d\n", pop(list));
		display_stack(list);
	}
	printf("pop data = %d\n", pop(list));
	destroy_stack(&list);
	display_stack(list);
}