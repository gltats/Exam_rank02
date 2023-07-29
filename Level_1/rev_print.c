/*Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
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
	int lenght;
	
	if(argc == 2)
	{
		lenght = ft_strlen(argv[1]);
		while(lenght > 0)
		{
			ft_putchar(argv[1][lenght - 1]);
			lenght--;
		}
	}
	ft_putchar('\n');
	return(0);
}