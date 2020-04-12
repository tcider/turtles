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
		ft_putstr("Wrong coordinate format. Use '21:3' style. 1-30 range.");
	if (err == 5)
		ft_putstr("Wrong or empty command format. Use only 'glr' letters.");
	if (err == 6)
		ft_putstr("Wrong or empty turtle name. Only letters allowed.");
	ft_putstr("\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_turtle	**turtle;

	ft_errors(ft_checkargv(argc, argv, 30));
	turtle = ft_maketurtles(argc, argv, 30);
	
	ft_putstr("All good");

	return (0);



}
