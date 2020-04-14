#include "ft_turtles.h"

int		ft_n_words(char *str, char space)
{
	int		i;
	int		counter;
	char	spaceflag;

	counter = 0;
	i = 0;
	spaceflag = 0;
	while (str[i])
	{
		if (str[i] != space)
		{
			if (spaceflag == 0)
				counter++;
			spaceflag = 1;
		}
		else
			spaceflag = 0;
		i++;
	}
	return (counter);
}

int		ft_l_word(char *w, char space)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (w[i] == space)
		i++;
	while (w[i] && w[i] != space)
	{
		l++;
		i++;
	}
	return (l);
}

char	**ft_split_words(char *s, char space)
{
	int		i;
	int		j;
	int		k;
	char	**p;

	i = 0;
	k = 0;
	p = (char**)malloc(sizeof(char*) * (ft_n_words(s, space) + 1));
	while (i < ft_n_words(s, space))
	{
		p[i] = (char*)malloc(sizeof(char) * (ft_l_word(&s[k], space) + 1));
		j = 0;
		while (s[k] == space)
			k++;
		while (s[k] && s[k] != space)
			p[i][j++] = s[k++];
		p[i][j] = '\0';
		i++;
	}
	p[i] = 0;
	return (p);
}
