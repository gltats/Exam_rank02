/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

Scans str1 for the first occurrence of any of the characters that are part of str2, returning the number of characters of str1 read before this first occurrence.

The search includes the terminating null-characters. Therefore, the function will return the length of str1 if none of the characters of str2 are found in str1.

size_t	ft_strcspn(const char *s, const char *reject);*/
char *ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if(*s == c)
			return((char *)s);
		s++;
	}
	return(0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	while(s[i])
	{
		if(ft_strchr(reject, s[i]) != 0)
			break;
		i++;
	}
	return(i);
}