/*Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.*/


#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
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

void	ft_putstr(char *str)
{
	int i = 0;

	while(str[i])
	{
		ft_putchar(str[i]);
		i++; 
	}
}

int main(void)
{
	int nb = 0;
	while(nb <= 100)
	{
		if(nb % 15 == 0)
			ft_putstr("fizzbuzz");
		else if(nb % 5 == 0)
			ft_putstr("buzz");
		else if(nb % 3 == 0)
			ft_putstr("fizz");
		else
			ft_putnumb(nb);
		ft_putchar('\n');
		nb++;
	}
	return(0);
}