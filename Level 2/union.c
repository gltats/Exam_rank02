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

int charExists(char *str, char c) 
{
    while (*str) 
	{
        if (*str == c)
            return 1;
        str++;
    }
    return 0;
}

int main(int argc, char *argv[]) 
{
    if (argc == 3)
	{
			char printed[256] = {0}; // Initialize a boolean array to keep track of printed characters
			char *str1 = argv[1];
			char *str2 = argv[2];

			while (*str1) {
				if (!printed[(unsigned char)*str1]) 
				{
					write(1, str1, 1);
					printed[(unsigned char)*str1] = 1; // Mark the character as printed
				}
				str1++;
			}

			while (*str2) {
				if (!charExists(argv[1], *str2) && !printed[(unsigned char)*str2]) 
				{
					write(1, str2, 1);
					printed[(unsigned char)*str2] = 1; // Mark the character as printed
				}
				str2++;
			}
    }
    write(1, "\n", 1);
    return 0;
}