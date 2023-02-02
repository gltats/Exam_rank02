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

void ft_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		nb = nb + '0';
		write(1, &nb, 1);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int ft_fizzbuzz(int nb)
{
	nb = 1;
	while(nb <= 100)
	{
	if (nb % 15 == 0)
		write(1, "fizzbuzz", 8);
	else if (nb % 3 == 0)
		write(1, "fizz", 4);
	else if (nb % 5 == 0)
		write(1, "buzz", 4);
	else
		ft_putnbr(nb);
	nb++;
	write (1, "\n", 1);
	}
	return(nb);
}

int main(void)
{
	int nb;
	ft_fizzbuzz(nb);
	return(0);
}