/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);*/

#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while(s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return(s1[i] - s2[i]);
}

int main(int argc, char **argv)
{
    int result;
    if(argc == 3)
    {
        result = ft_strcmp(argv[1], argv[2]);
        if (result == 0) printf("They are equal\n");
        if (result > 0) printf("First(%s) string is not greater than second(%s)\n", argv[1], argv[2]);
        if (result < 0) printf("First(%s) string is greater than secont(%s)\n", argv[1], argv[2]);
    }
    return 0;
}