// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);
#include <stdlib.h>
#include <stdio.h>

static int	count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		// Skip leading delimiters
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		// If we encounter a non-delimiter character, it's the beginning of a word
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			count++;
			// Skip the word by advancing to the next delimiter
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
		}
	}

	return count;
}

char	**ft_split(char *str)
{
	int		word_count;
	int		i;
	int		j;
	int		start;
	char	**result;

	word_count = count_words(str);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return NULL;

	i = 0;
	j = 0;
	while (str[i] && j < word_count)
	{
		// Skip leading delimiters
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		// Record the start of the word
		start = i;
		// Find the end of the word
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		// Allocate memory for the word and copy it
		result[j] = (char *)malloc((i - start + 1) * sizeof(char));
		if (!result[j])
			return NULL;
		int k = 0;
		while (k < (i - start))
		{
			result[j][k] = str[start + k];
			k++;
		}
		result[j][i - start] = '\0';
		j++;
	}

	result[j] = NULL;
	return result;
}

int main(void) 
{
	char	**tabstr;
	int		i;
	tabstr = ft_split("		jsb djfiaejf dajaiejrf daidf");
		while (tabstr[i] != NULL)
		{
			printf("%d = %s\n",i, tabstr[i]);
			i++;
		}
   return 0;
}