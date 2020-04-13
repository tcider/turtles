#include "ft_turtles.h"

t_turtle	**ft_maketurtles(int argc, char **argv)
{
	int			i;
	char		**brgv;
	char		**crgv;
	t_turtle	**all;

	all = (t_turtle**)malloc(sizeof(t_turtle*) * argc);
	i = 0;
	while (argv[i + 1])
	{
		all[i] = (t_turtle*)malloc(sizeof(t_turtle));
		brgv = ft_split_words(argv[i + 1], '-');
		crgv = ft_split_words(brgv[0], ':');
		all[i]->y = ft_atoi(crgv[0]);
		all[i]->x = ft_atoi(crgv[1]);
		all[i]->name = brgv[2];
		all[i]->stack = brgv[1];
		all[i]->dir = 0;
		i++;
	}
	all[i] = NULL;
	return (all);
}

int			ft_changedir(int dir, char com)
{
	if (com == 'l')
		dir--;
	else if (com == 'r')
		dir++;
	if (dir == 4)
		dir = 0;
	if (dir == -1)
		dir = 3;
		return (dir);
}

t_turtle	*ft_go(t_turtle *trtl, int size)
{
	if (trtl->dir == 0)
		trtl->y++;
	else if (trtl->dir == 1)
		trtl->x++;
	else if (trtl->dir == 2)
		trtl->y--;
	else if (trtl->dir == 3)
		trtl->x--;
	if (trtl->y == size + 1)
		trtl->y = 1;
	else if (trtl->y == 0)
		trtl->y = size;
	if (trtl->x == size + 1)
		trtl->x = 1;
	else if (trtl->x == 0)
		trtl->x = size;
	return (trtl);
}

t_turtle	*ft_makemove(t_turtle *trtl, int size)
{
	int			i;
	char		*com;

	i = 0;
	com = trtl->stack;
	while (com[i])
	{
		if (com[i] == 'l' || com[i] == 'r')
			trtl->dir = ft_changedir(trtl->dir, com[i]);
		if (com[i] == 'g')
			trtl = ft_go(trtl, size);
		i++;
	}
	return (trtl);
}
