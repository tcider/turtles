#include "ft_turtles.h"

void	ft_errors(int err)
{
	if (err == 1)
		return ;
	ft_putstr("Error. ");
	if (err == 2)
		ft_putstr("Wrong arguments number. 1-10 turtles expected.");
	if (err == 3)
		ft_putstr("Wrong argument format. Valid examle '4:3-grl-Max'");
	if (err == 4)
		ft_putstr("Wrong coordinate format. Use '21:3' style. Within arena.");
	if (err == 5)
		ft_putstr("Wrong or empty command format. Use only 'glr' letters.");
	if (err == 6)
		ft_putstr("Wrong or empty turtle name. Only letters allowed.");
	ft_putstr("\n");
	exit(1);
}

void	ft_findwinner(t_turtle **trtl, t_arena arena)
{
	int			i;
	int			n;

	n = 0;
	while (n < MAX_MOVE)
	{
		i = 0;
		while (trtl[i])
		{
			trtl[i] = arena.f(trtl[i], arena);
			//
			printf("%s - %d:%d\n", trtl[i]->name, trtl[i]->y, trtl[i]->x);
			if (trtl[i]->y == arena.cuc_y && trtl[i]->x == arena.cuc_x)
			{
				ft_putstr("The winner is ");
				ft_putstr(trtl[i]->name);
				ft_putstr(".\n");
				return ;
			}
			i++;
		}
		n++;
	}
	ft_putstr("Unfortunately, there is no winner:(\n");
}

int		main(int argc, char **argv)
{
	t_turtle	**trtl;
	t_arena		arena;
	int			i;

	arena = ft_setarena();
	i = 0;
	while (argv[++i])
	{
		if (ft_strcmp("-s\0", argv[i]) == 0 && argv[i + 1])
			arena = ft_customarena(arena, argv[i + 1]);
		if (ft_strcmp("-l\0", argv[i]) == 0 && argv[i + 1])
			arena = ft_customcuc(arena, argv[i + 1]);
		if (ft_strcmp("-a\0", argv[i]) == 0)
			arena = ft_set_f(arena);
	}
	printf("%d", arena.flags);
	ft_errors(ft_checkargv(argc, argv, arena));
	trtl = ft_maketurtles(argc, argv, arena.flags);
	ft_findwinner(trtl, arena);

	return (0);
}
