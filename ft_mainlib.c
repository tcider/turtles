#include "ft_turtles.h"

t_turtle	**ft_maketurtles(int argc, char **argv, int sz)
{
	int			i;
	char		**brgv;
	char		**crgv;
	t_turtle	**all;

	all = (t_turtle**)malloc(sizeof(t_turtle*) * (argc - 1));
	i = 0;
	while (argv[i + 1])
	{
		all[i] = (t_turtle*)malloc(sizeof(t_turtle));
		brgv = ft_split_words(argv[i + 1], '-');
		crgv = ft_split_words(brgv[0], ':');
		all[i]->adr = ft_getadr(ft_atoi(crgv[0]), ft_atoi(crgv[1]), sz);
		all[i]->name = brgv[2];
		all[i]->stack = brgv[1];
		all[i]->direction = 'n';
		i++;
	}
	return (all);
}
