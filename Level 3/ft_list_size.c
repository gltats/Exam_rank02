// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure, and turn it in as a file called
// ft_list.h:

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

int ft_list_size(t_list *begin_list)
{
    if (begin_list == NULL)
        return 0;
    else
        return 1 + ft_list_size(begin_list->next);
}

// Function to create a new node and return a pointer to it
t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node)
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

// Function to free the memory allocated for the linked list
void free_list(t_list *begin_list)
{
    t_list *current = begin_list;
    while (current)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    // Create a linked list with some elements
    t_list *head = create_node("First");
    head->next = create_node("Second");
    head->next->next = create_node("Third");
    head->next->next->next = create_node("Fourth");
    head->next->next->next->next = create_node("Fifth");

    // Calculate and print the size of the linked list
    int size = ft_list_size(head);
    printf("Size of the linked list: %d\n", size);

    // Free the memory allocated for the linked list
    free_list(head);

    return 0;
}