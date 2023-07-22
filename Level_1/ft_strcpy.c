/* Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/

#include <stdio.h>
#include <string.h>

/*S1 is dst and s2 src*/
char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s2 = '\0';
    return(s1);
}

int main(void)
{
    char *src;
    src = "hello";
    char dst[20];

    printf(ft_strcpy(dst, src));
    printf("\n");
    printf(strcpy(dst, src));
    return(0);
}