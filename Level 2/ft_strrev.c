// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

#include <stdio.h>

int	ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}

char    *ft_strrev(char *str)
{
	int lenght = ft_strlen(str);
	int start = 0;
	int end = lenght - 1;
	char temp;

	while(start < end)
	{
		temp = str[start];
		str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    return str;
}

int main(void)
{
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);

    ft_strrev(str);
    printf("Reversed string: %s\n", str);

    return 0;
}