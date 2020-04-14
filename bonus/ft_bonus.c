#include "ft_turtles.h"

t_arena		ft_setarena(void)
{
	t_arena		arena;

	arena.max_y = 30;
	arena.max_x = 30;
	arena.cuc_y = 15;
	arena.cuc_x = 15;
	arena.f = &ft_makemove;
	arena.flags = 0;
	return (arena);
}

t_arena		ft_set_f(t_arena arena)
{
	arena.f = &ft_makeonemove;
	arena.flags++;
	return (arena);
}

t_arena		ft_customarena(t_arena arena, char *str)
{
	char		**arr;
	int			i;
	int			j;

	if (ft_n_words(str, ':') != 2)
		ft_errors(4);
	arr = ft_split_words(str, ':');
	if (!ft_str_is_num(arr[0]) || !ft_str_is_num(arr[1]))
		ft_errors(4);
	i = ft_atoi(arr[0]);
	j = ft_atoi(arr[1]);
	if (i < 0 || j < 0 || i * j == 0)
		ft_errors(4);
	arena.max_y = i;
	arena.max_x = j;
	arena.flags++;
	return (arena);
}

t_arena		ft_customcuc(t_arena arena, char *str)
{
	char		**arr;

	if (ft_n_words(str, ':') != 2)
		ft_errors(4);
	arr = ft_split_words(str, ':');
	if (!ft_num_is_ok(arr[0], arr[1], arena.max_y, arena.max_x))
		ft_errors(4);
	arena.cuc_y = ft_atoi(arr[0]);
	arena.cuc_x = ft_atoi(arr[1]);
	arena.flags++;
	return (arena);
}


t_turtle	*ft_makeonemove(t_turtle *trtl, t_arena arena)
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
			trtl = ft_go(trtl, arena.max_y, arena.max_x);
		i++;
	}
	return (trtl);
}
