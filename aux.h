#ifndef AUX_H
# define	AUX_H

int	count_words(char *str);
int	word_len(char *str);
char	*extract_word(char *str);
char	**free_array(char **array, int n);
char	**ft_split(char *str);

#endif
