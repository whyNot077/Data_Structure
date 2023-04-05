#include "linked_queue.h"

int main()
{
	queue *list;
	
	list = create_queue();
	for (int i = 0; i < 5; i++)
		enqueue(list, i);
	display_queue(list);
	printf("enqueue data = %d\n", enqueue(list, 10));
	display_queue(list);
	printf("enqueue data = %d\n", enqueue(list, 10));
	display_queue(list);

	for (int i = 0; i < 10; i++)
	{
		printf("dequeue data = %d\n", dequeue(list));
		display_queue(list);
	}
	destroy_queue(&list);
	display_queue(list);
}