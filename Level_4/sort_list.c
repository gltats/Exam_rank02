// Assignment name  : sort_list
// Expected files   : sort_list.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following functions:

// t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

// This function must sort the list given as a parameter, using the function
// pointer cmp to select the order to apply, and returns a pointer to the
// first element of the sorted list.

// Duplications must remain.

// Inputs will always be consistent.

// You must use the type t_list described in the file list.h
// that is provided to you. You must include that file
// (#include "list.h"), but you must not turn it in. We will use our own
// to compile your assignment.

// Functions passed as cmp will always return a value different from
// 0 if a and b are in the right order, 0 otherwise.

// For example, the following function used as cmp will sort the list
// in ascending order:

// int ascending(int a, int b)
// {
// 	return (a <= b);
// }
#include <stdio.h> 

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

#include <stdlib.h>
// Function to create a new node
t_list *newNode(int data) {
    t_list *newNode = (t_list *)malloc(sizeof(t_list));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the list
void append(t_list **headRef, int data) {
    t_list *new_node = newNode(data);
    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    t_list *last = *headRef;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Function to print the linked list
void printList(t_list *head) {
    t_list *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to compare two integers in ascending order
int ascending(int a, int b) {
    return (a <= b);
}


t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int main() {
    // Create the linked list: 5 -> 1 -> 8 -> 3 -> 2
    t_list *head = NULL;
    append(&head, 5);
    append(&head, 1);
    append(&head, 8);
    append(&head, 3);
    append(&head, 2);

    printf("Original list: ");
    printList(head);

    // Sort the linked list in ascending order
    head = sort_list(head, ascending);

    printf("Sorted list: ");
    printList(head);

    // Free the memory used by the linked list
    t_list *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}