// Assignment name	: ft_strpbrk
// Expected files	: ft_strpbrk.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strpbrk
// (man strpbrk).

// The function should be prototyped as follows:

// char	*ft_strpbrk(const char *s1, const char *s2);

#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	
	if (!s1 || !s2)
	{
		return (0);
	}
	while(*s1)
	{
		i = 0;
	   	while(s2[i])
		{
			if(*s1 == s2[i])
				return (char *) s1;
			i++;
		}
		s1++;	
	}
	return (0);
}

int main(void)
{
	char *s1 = "hello world";
	char *s2 = "soh";
	char *result = ft_strpbrk(s1, s2);
	if (*result != 0)
	    printf("Found: %c\n", *result);
    else {
        printf("No match found.\n");
    }
    return 0;
}