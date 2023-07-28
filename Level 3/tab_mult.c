// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;

	while(str[i])
	{
		ft_putchar(str[i]);
		i++; 
	}
}

int ft_putnumb(int n)
{
	if (n > 0 && n <= 9)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putnumb(n / 10);
		ft_putnumb(n % 10);
	}
	return(n);
}

void tab_mult(int num)
{
    int i = 1;

    while (i <= 9)
    {
        ft_putnumb(i);
        ft_putstr(" x ");
        ft_putnumb(num);
		ft_putstr(" = ");
        ft_putnumb(i * num);
        ft_putchar('\n');
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int num = 0;
        int i = 0;

        while (argv[1][i])
        {
            num = num * 10 + (argv[1][i] - '0');
            i++;
        }
        tab_mult(num);
    }
	else
    	ft_putchar('\n');
    return 0;
}
