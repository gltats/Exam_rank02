/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/

#include <stdio.h>

int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if(str[i] == '-')
    {
        sign = sign * -1;
        i++;
    }
    if(str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10;
        result = result + str[i] - '0';
        i++;
    }
    return(sign * result);
}

int main(void)
{
	const char* testString="42"; // should print "42"

	printf("this is my atoi result:\n");
	printf("%d\n", ft_atoi(testString));
	return(0);
}