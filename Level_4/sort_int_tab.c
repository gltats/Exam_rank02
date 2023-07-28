// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int temp;
    int sorted = 0; // Flag to check if the array is sorted

    while (!sorted)
    {
        sorted = 1; // Assume the array is sorted, change to 0 if a swap occurs
		unsigned int i = 0; 
       	while(i < size - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                // Swap elements if they are in the wrong order
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                sorted = 0; // Array is not sorted, continue sorting
            }
			i++;
        }
    }
}

int main()
{
    int arr[] = {9, 5, 2, 7, 1, 3};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
	unsigned int i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
		i++;
    }

    sort_int_tab(arr, size);

    printf("\nAfter sorting: ");
	unsigned int c = 0;
    while (c < size)
    {
        printf("%d ", arr[c]);
		c++;
    }

    return 0;
}
