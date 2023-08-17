// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int charExists(char c, char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == c)
		{
			return(1);
		}
		i++;
	}
	return(0);
}

int isDuplicated(char c, char *str, int pos)
{
	int i = 0;
	while(str[i] && i < pos)
	{
		if(str[i] == c)
		{
			return(1);
		}
		i++;
	}
	return(0);
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
        int i = 0;
        int j = 0;
        while (argv[1][i])
        {
            if (!isDuplicated(argv[1][i], argv[1], i))
                ft_putchar(argv[1][i]);
            i++;
        }
        while (argv[2][j])
        {
            if (!charExists(argv[2][j], argv[1]) && !isDuplicated(argv[2][j], argv[2], j))
                ft_putchar(argv[2][j]);
            j++;
        }

	}
	else
		ft_putchar('\n')\
	return(0);
}