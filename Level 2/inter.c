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
    if (argc == 3) {
        char printed[256] = {0}; // Initialize a boolean array to keep track of printed characters
        char *str1 = argv[1];
        char *str2 = argv[2];

        while (*str1) {
            if (charExists(str2, *str1) && !printed[(unsigned char)*str1]) {
                write(1, str1, 1);
                printed[(unsigned char)*str1] = 1; // Mark the character as printed
            }
            str1++;
        }
    }
    write(1, "\n", 1);
    return 0;
}