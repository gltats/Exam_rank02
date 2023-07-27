// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.
#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	if (len == 0)
		return(0);
	
	unsigned int result;
	unsigned int i = 0;
	
	result = tab[i];
	while(i < len)
	{
		if (result <  tab[i])
		{
			result = tab[i];
		}
		i++;
	}
	return result;
}

int main(void) 
{
    int arr1[] = {3, 7, 1, 9, 5};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Max value in arr1: %d\n", max(arr1, len1)); // Output: 9

    int arr2[] = {-1, -5, -3, -7, -2};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Max value in arr2: %d\n", max(arr2, len2)); // Output: -1

    int arr3[] = {1};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Max value in arr3: %d\n", max(arr3, len3)); // Output: 1

    int arr4[] = {};
    int len4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Max value in arr4: %d\n", max(arr4, len4)); // Output: 0

    return 0;
}