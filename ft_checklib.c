#include "ft_turtles.h"

int		ft_str_is_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int		ft_str_is_name(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int		ft_str_is_com(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'g' && str[i] != 'l' && str[i] != 'r')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int		ft_num_is_ok(char *x, char *y, int size)
{
	int		i;
	int		j;

	if (!ft_str_is_num(x) || !ft_str_is_num(y))
		return (0);
	i = ft_atoi(x);
	j = ft_atoi(y);
	if (i * j == 0 || i > size || j > size)
		return (0);
	return (1);
}

int		ft_checkargv(int argc, char **argv, int size)
{
	int		i;
	char	**brgv;
	char	**crgv;

	if (argc == 1 || argc > 11)
		return (2);
	i = 0;
	while (argv[++i])
	{
		if (ft_n_words(argv[i], '-') != 3)
			return (3);
		brgv = ft_split_words(argv[i], '-');
		if (ft_n_words(brgv[0], ':') != 2)
			return (4);
		crgv = ft_split_words(brgv[0], ':');
		if (!ft_num_is_ok(crgv[0], crgv[1], size))
			return (4);
		if (!ft_str_is_com(brgv[1]))
			return (5);
		if (!ft_str_is_name(brgv[2]))
			return (6);
	}
	free(brgv);
	free(crgv);
	return (1);
}
