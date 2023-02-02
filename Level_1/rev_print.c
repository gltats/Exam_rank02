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

char *rev_print(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	while(i > 0)
	{
		i--;
		write(1, &str[i], 1);
	}
	return(0);
}

int main(void)
{
	rev_print("ponies are awesome");
    write(1, "\n", 1);
    rev_print("rainbow dash");
    write(1, "\n", 1);
	rev_print("");
	rev_print("\n");
    return (0);
}