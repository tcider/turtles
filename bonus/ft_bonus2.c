#include "ft_turtles.h"

t_arena		ft_set_knock(t_arena arena)
{
	arena.knock = 1;
	arena.flags++;
	return (arena);
}

t_turtle	*ft_knock_back(t_turtle *trtl, t_arena ar)
{
	if (trtl->dir == 0)
		trtl->y--;
	else if (trtl->dir == 1)
		trtl->x--;
	else if (trtl->dir == 2)
		trtl->y++;
	else if (trtl->dir == 3)
		trtl->x++;
	if (trtl->y == ar.max_y + 1)
		trtl->y = 1;
	else if (trtl->y == 0)
		trtl->y = ar.max_y;
	if (trtl->x == ar.max_x + 1)
		trtl->x = 1;
	else if (trtl->x == 0)
		trtl->x = ar.max_x;
	trtl->knock = 1;
	return (trtl);
}

void		ft_check_knock(t_turtle **trtl, int i, t_arena arena)
{
	int			k;

	k = 0;
	while (trtl[k])
	{
		if (trtl[i]->y == trtl[k]->y && trtl[i]->x == trtl[k]->x && i != k)
		{
			trtl[i] = ft_knock_back(trtl[i], arena);
			trtl[k] = ft_knock_back(trtl[k], arena);
			return ;
		}
		k++;
	}
}

t_arena		ft_set_viz(t_arena arena)
{
	arena.viz = 1;
	arena.flags++;
	return (arena);
}
