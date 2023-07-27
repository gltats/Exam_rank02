// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}

int main(int argc, char **argv)
{
	int i = ft_strlen(argv[1]) - 1;

	if (argc == 2)
	{
		while(argv[1][i] == 32)
			i--;
		int start = i;
		while(i >= 0 && argv[1][i] >= 33 && argv[1][i] <= 'z')
			i--;
		while(i < start)
		{	
			ft_putchar(argv[1][i + 1]);
			i++;
		}
	}
	ft_putchar('\n');
	return(0);
	}