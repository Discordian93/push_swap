#include <stdlib.h>
#include "push_swap.h"
#include <limits.h>

int	count_words(char *str)
{
	int	state;
	int	count;

	state = 0;
	count = 0;
	while (*str)
	{
		if (*str != ' ' && state == 0)
		{
			state = 1;
			count++;
		}
		if (*str == ' ')
			state = 0;
		str++;
	}
	return (count);
}

int	word_len(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != ' ')
	{
		len++;
		str++;
	}
	return (len);
}

char	*extract_word(char *str)
{
	char	*s;
	int		i;
	int		len;

	len = word_len(str);
	i = 0;
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (s);
	while (i < len)
	{
		s[i] = *str;
		str++;
		i++;
	}
	s[len] = '\0';
	return (s);
}

char	**free_array(char **array, int n)
{
	int	j;

	j = 0;
	while (j < n)
		free(array[j++]);
	free(array);
	return (NULL);
}

char	**ft_split(char *str)
{
	int		state;
	char	**array;
	int		wordcount;
	int		i;

	state = 0;
	wordcount = count_words(str);
	i = 0;
	array = malloc(sizeof(char *) * (wordcount + 1));
	if (array == NULL)
		return (array);
	array[wordcount] = NULL;
	while (*str)
	{
		if (*str != ' ' && state == 0)
		{
			array[i++] = extract_word(str);
			if (array[i - 1] == NULL)
				return (free_array(array, i - 1));
			state = 1;
		}
		if (*(str++) == ' ')
			state = 0;
	}
	return (array);
}
