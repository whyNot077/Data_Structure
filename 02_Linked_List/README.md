# What is Linked Lists?
Whereas arrays are contiguously-allocated structures composed of single slobs of memory, linked lists are composed of distinct chunks of memory bound together by pointers which are assumed to give the address in memory where a particular chunk of data is located. 

The comparison between linked lists and arrays, referenced from "The Algorithm Design Manuel, Steven S. Skiena."  
The relative advantages of linked lists over static arrays include the following:
- Overflow on linked structures can never occur unless the memory is actually full.
- Insertions and deletions are simpler than for contiguous array lists. 
- With large records, moving pointers is easier and faster than moving the items themselves.  

The relative advantages of arrays include the following:
- Linked structures require extra space for storing pointer fields.
- Linked lists do not allow efficient random access to items. 
- Arrays allow better memory locality and cache performance than random pointer jumping. 

## main
We will append, insert, remove, display, search and destroy linked lists. 
```c
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
```

## Header
- Struct 'list' is the entire linked list consisting of nodes.
- each 'node' contains the data and the address of the next node. 
- 'headnode' is the first list of linked lists. It ensures access to other linked nodes. 

```c
typedef struct node {
	int			data;
	struct node	*next;
} node;

typedef struct list {
	node	*headnode;
} list;
```

## Functions
### create_linkedlist
Create a list by allocating memory on the heap. 
```c
list	*create_linkedlist()
{
	list *linked_list;
	linked_list = calloc(1, sizeof(list));
	if (linked_list == NULL)
		return (NULL);
	return (linked_list);
}
```

### create_new_node
Create a new node with data.
```c
node	*create_new_node(int data)
{
	node	*new_node;
	
	new_node = calloc(1, sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}
```

### search_list
Let's find the 'star' data in the linked list. Until the linked list is finished, I should look at each node's value. Then, return the index when I find the 'star' value. In this case, the return value is long long (int) because size_t can't get a minus value, although I want to return -1 when it is an error.
```c
long long	search_list(list *linked_list, int star)
{
	size_t	index;
	node	*dummy;

	index = 0;
	if (linked_list == NULL || linked_list->headnode == NULL)
		return (-1);
	dummy = linked_list->headnode;
	while (dummy && dummy->next)
	{
		if (dummy->data == star)
			return (index);
		dummy = dummy->next;
		index++;
	}
	return (-1);
}
```
### get_node
Get the index-th node. While 'i' is smaller than the index, move the dummy to the next. But if the dummy or dummy next is none, then exit the loof. After escaping the loof, if 'i' has the same value as the index, you can find the index-th dummy. On the other hand, if 'i' and the index value are different, you can't access the index-th dummy, return NULL. 

```c
node	*get_node(list *linked_list, size_t index)
{
	size_t 	i;
	node	*dummy;

	i = 0;
	if (linked_list == NULL)
		return (NULL);
	dummy = linked_list->headnode;
	while ((i < index) && dummy && dummy->next)
	{
		dummy = dummy->next;
		i++;
	}
	if (i == index)
		return (dummy);
	return (NULL);
}
```

### insert_node
Insert node having 'data' to the index position. If you insert the new data into the first index, the former head node should be moved to the next, and the new data node becomes the head node. Else find the 'index - 1'th node and link it to the new node. The next of the 'before node' become the newnode and the next of the new node become the 'index'th node. If the insertion is successful, return 1.


```c
int		insert_node(list *linked_list, size_t index, int data)
{
	node	*before_node;
	node	*new_node;

	if (linked_list == NULL)
		return (0);
	new_node = create_new_node(data);
	if (new_node == NULL)
		return (0);
	if (index == 0)
	{
		new_node->next = linked_list->headnode;
		linked_list->headnode = new_node;
		return (1);
	}
	before_node = get_node(linked_list, index - 1);
	if (before_node == NULL)
		return (0);
	new_node->next = before_node->next;
	before_node->next = new_node;
	return (1);
}
```

### add_node
Append a new node with new data to the linked list. If the head node is null, the new node becomes the head node. If it isn't, move the dummy to the end of the linked list, and the next node of the end node becomes the new node. 

```c
int		add_node(list *linked_list, int data)
{
	node	*dummy;
	node	*new_node;

	if (linked_list == NULL)
		return (0);
	dummy = linked_list->headnode;
	new_node = create_new_node(data);
	if (dummy == NULL)
	{
		linked_list->headnode = new_node;
		return (1);
	}
	if (new_node == NULL)
		return (0);
	while (dummy && dummy->next)
		dummy = dummy->next;
	dummy->next = new_node;
	return (1);
}
```

### remove_node
Remove index-th node. If you want to remove the first node, move the head node to the next and remove the old head node. If not, link the before and after of the 'index' node. The before->next node becomes the remove->next node and frees the remove_node. 
```c
int		remove_node(list *linked_list, size_t index)
{
	node *before_node;
	node *remove_node;

	if (index == 0)
	{
		remove_node = linked_list->headnode;
		linked_list->headnode = remove_node->next;
		free(remove_node);
		return (1);
	}
	before_node = get_node(linked_list, index - 1);
	if (before_node == NULL)
		return (0);
	remove_node = before_node->next;
	if (remove_node == NULL)
		return (0);
	before_node->next = remove_node->next;
	free(remove_node);
	return (1);
}
```

### display_list
This function shows every data of the node in order. 
```c
void	display_list(list *linked_list)
{
	node	*dummy;
	int		index;

	index = 0;
	printf("linked_list %p\n", linked_list);
	if (!linked_list || !linked_list->headnode)
	{
		printf("no list\n");
		return ;
	}
	dummy = linked_list->headnode;
	printf("\ndisplay_list\n");
	while (dummy)
	{
		printf("[%d] %d ", index++, dummy->data);
		dummy = dummy->next;
	}
	printf("\n");
}
```

### destroy_list
The list and nodes are allocated on the heap, so you should free every linked list before the end of the function. 

```c
void	destroy_list(list **linked_list)
{
	node *dummy;
	node *remove;

	if (!*linked_list)
		return ;	
	dummy = (*linked_list)->headnode;
	while (dummy)
	{
		remove = dummy;
		dummy = dummy->next;
		free(remove);
		remove = NULL;
	}
	free(*linked_list);
	*linked_list = NULL;
	printf("destroy complete\n");
}
```