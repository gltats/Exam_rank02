/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

Scans str1 for the first occurrence of any of the characters that are part of str2, returning the number of characters of str1 read before this first occurrence.

The search includes the terminating null-characters. Therefore, the function will return the length of str1 if none of the characters of str2 are found in str1.

size_t	ft_strcspn(const char *s, const char *reject);*/
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;
    char *str = (char *)s;
    while(str[i])
    {
        j = 0;
        while(reject[j])
        {
            if(str[i] == reject[j])
                return(i);
            j++;
        }
        i++;
    }
    return (i);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = ft_strcspn(argv[1], argv[2]);
        printf("The first number in str is at position %d.\n", i + 1);
        return 0;
    }
    else
    {
        printf("Usage: %s <str> <reject>\n", argv[0]);
        return 1;
    }
}