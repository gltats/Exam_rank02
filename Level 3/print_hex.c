// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

#include <unistd.h>

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int	ft_print_hex(unsigned int nb, char l)
{
	int	len;

	len = 0;
	if (nb < 10)
		len += ft_putchar(nb + '0');
	else if (nb < 16)
	{
		if (l == 'x')
			len += ft_putchar(nb + 'a' - 10);
		else if (l == 'X')
			len += ft_putchar(nb + 'A' - 10);
	}
	else
	{
			len += ft_print_hex(nb / 16, l);
			len += ft_print_hex(nb % 16, l);
	}
	return (len);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        ft_putchar('\n');
        return 0;
    }
    unsigned int num = 0;
    // Convert input string to an unsigned integer
	int i = 0;
    while (argv[1][i] != '\0')
	{
        if (argv[1][i] >= '0' && argv[1][i] <= '9')
            num = num * 10 + (argv[1][i] - '0');
        else {
            ft_putchar('\n');
            return 0;
        }
		i++;
    }
    // Call the function to convert and print the hexadecimal representation
    ft_print_hex(num, 'x');
    ft_putchar('\n');
    return 0;
}