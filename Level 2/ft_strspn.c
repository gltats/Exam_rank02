// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if(*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;
		++i;
	}
	return (i);
}

int main(void)
{
	const char *str = "helo, world";
    const char *accept = "abcdefg,hijklmnopqrstuvwxyz";

    size_t length = ft_strspn(str, accept);
    printf("Length of initial segment: %zu\n", length);

    return 0;
}