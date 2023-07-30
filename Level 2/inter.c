// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int charExists(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

// Function to check if a character is duplicated in a string
int isDuplicate(char *str, char c, int pos)
{
    int i = 0;
    while (i < pos)
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
		int i = 0;
		while (argv[1][i])
		{
			char current_char = argv[1][i];
			// Check if the character exists in both strings and is not a duplicate
			if (charExists(argv[2], current_char) && !isDuplicate(argv[1], current_char, i))
				ft_putchar(current_char);
			i++;
		}

    }
   ft_putchar('\n');
    return 0;
}