// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if(str[i] == '-')
    {
        sign = -1;
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

int is_prime(int num)
{
    int i = 2;

    if (num <= 1)
        return (0);
    while (i * i <= num)
    {
        if (num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int ft_putnumb(int n)
{
    if (n == 0)
    {
        ft_putchar('0');
        return n;
    }
    if (n > 0 && n <= 9)
        ft_putchar(n + '0');
    if (n > 9)
    {
        ft_putnumb(n / 10);
        ft_putnumb(n % 10);
    }
    return(n);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int nbr = ft_atoi(av[1]);
        int sum = 0;
        int current = 2; // Start from 2

        while (current <= nbr) // Loop from 2 to the input value
        {
            if (is_prime(current))
                sum += current;
            current++;
        }
        ft_putnumb(sum);
    }
    else
    {
        ft_putnumb(0);
    }
    write(1, "\n", 1);
    return (0);
}