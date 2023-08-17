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
    int i = 0;
    int len;

    // Calculate the length of the range without using abs()
    if (start < end)
        len = end - start + 1;
    else
        len = start - end + 1;

    int *res = (int *)malloc(sizeof(int) * len);
    if (res == NULL) {
        return NULL; // Handle memory allocation failure
    }

    while (i < len)
    {
        res[i] = start;
        if (start < end)
        {
            start++;
        }
        else
        {
            start--;
        }
        i++;
    }
    
    return res;
}
int main(void)
{
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
}