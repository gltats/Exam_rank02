/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);*/

#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    return (n != 0 && (n & (n - 1)) == 0);
}

int main()
{
    // Test cases
    unsigned int numbers[] = {0, 1, 2, 3, 4, 8, 16, 32, 64, 128, 255, 256, 1024};

    printf("Testing is_power_of_2:\n");

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        printf("%u is %s a power of 2\n", numbers[i], is_power_of_2(numbers[i]) ? "" : "not");
    }

    return 0;
}