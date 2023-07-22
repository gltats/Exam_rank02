/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/

#include <stdio.h>
void	ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(void)
{
    int a = 3;
    int b = 4;

    printf("NO changes:\n");
    printf("%i\n", a);
    printf("%i\n", b);
    ft_swap(&a, &b);
    printf("After changes:\n");
    printf("%i\n", a);
    printf("%i\n", b);

}