// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdlib.h>
#include <stdio.h> 

int *ft_range(int start, int end)
{
    int size = (end >= start) ? (end - start + 1) : (start - end + 1);
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL)
        return NULL;

    int i = 0;
    while (i < size)
    {
        arr[i] = (start <= end) ? (start + i) : (start - i);
		i++;
    }

    return arr;
}

int main(void)
{
	// Test cases from examples in comments above...
	int start = 0, end = -1;
    int *array = ft_range(start, end);
    if (array)
    {
        printf("Array: ");
		int i = 0;
        while (i < abs(end - start) + 1)
        {
            printf("%d ", array[i]);
			i++;
        }
        printf("\n");

        free(array);
    }
    else
    {
        printf("Invalid range or memory allocation failed for Array.\n");
    }

	// Another test case.
	int start2 = 5, end2 = 2;
    int *array2 = ft_range(start2, end2);
    if (array2)
    {
        printf("Array2: ");
        int i = 0;
        while (i < abs(end2 - start2) + 1)
        {
            printf("%d ", array2[i]);
            i++;
        }
        printf("\n");

        free(array2);
    }
    else
    {
        printf("Invalid range or memory allocation failed for Array2.\n");
    }

    return 0;
}