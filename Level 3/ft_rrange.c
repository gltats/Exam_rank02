// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

#include <stdlib.h>
#include <stdio.h> 

int *ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int n = end - start + 1;

	if (start > end)
		return (ft_rrange(end, start));
	range = (int *)malloc(sizeof(int) * n);
	if (range)
	{
		while (i < n)
		{
			range[i] = end;
			end--;
			i++;
		}
	}
	return (range);
}

int main(void)
{
    // Test cases from examples in comments above...
    int start = 1, end = 3;
    int *array = ft_rrange(start, end);
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
