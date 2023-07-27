// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);

// The strdup() function allocates sufficient memory for a copy 
// of the string s1, does the copy, and returns a pointer to it.  
// The pointer may subsequently be used as an argument to the function free(3).
// If insufficient memory is available, NULL is returned.
// The strndup() function copies at most n characters from the string s1 always 
// NUL terminating the copied string.

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}

char    *ft_strdup(char *src)
{
	char *dest;
	size_t i;

	i = ft_strlen(src) + 1;
	dest = (char *)malloc(sizeof(char) * i);
	if(!dest)
		return(0);
	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int main(void)
{
	char *src = "Hello world";
	char *dst = ft_strdup(src);

	printf("src = %s, dst = %s\n", src, dst);
	free(dst);
	return(0);
}