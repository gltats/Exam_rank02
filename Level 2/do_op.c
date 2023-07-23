/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$*/
#include <unistd.h>

int	ft_atoi(const char *s)
{
    char *str = (char *)s;
    int i = 0;
    int sign = 1;
    int result = 0;

    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
           || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
    {
        i++;
    }
    if(str[i] == '-')
    {
        sign = sign * -1;
        i++;
    }
    if(str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10;
        result = result + str[i] - '0';
        i++;
    }
    return( sign * result);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnumb(long int numb)
{
    if (numb < 0)
    {
        ft_putchar('-');
        numb = -numb;
    }
    if (numb >= 0 && numb <= 9)
        ft_putchar(numb + '0');
    else if (numb > 9)
    {
        ft_putnumb(numb / 10);
        ft_putnumb(numb % 10);
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        int numb1 = ft_atoi(argv[1]);
        int numb2 = ft_atoi(argv[3]);
        char operator = argv[2][0];

        if (operator == '+')
            ft_putnumb(numb1 + numb2);
        else if (operator == '-')
            ft_putnumb(numb1 - numb2);
        else if (operator == '*')
            ft_putnumb(numb1 * numb2);
        else if (operator == '/')
        {
            if (numb2 != 0)
                ft_putnumb(numb1 / numb2);
            else
                write(1, "Error: Division by zero\n", 24);
        }
        else if (operator == '%')
        {
            if (numb2 != 0)
                ft_putnumb(numb1 % numb2);
            else
                write(1, "Error: Modulo by zero\n", 22);
        }
    }

    ft_putchar('\n');
    return 0;
}