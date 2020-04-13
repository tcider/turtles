#ifndef FT_TURTLES_H
# define FT_TURTLES_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_MOVE 1000
# define SIZE 30

typedef struct		s_turtle
{
	int		y;
	int		x;
	char	*name;
	char	*stack;
	int		dir;
}					t_turtle;

void		ft_putstr(char *str);
int			ft_atoi(char *str);
int			ft_n_words(char *str, char space);
char		**ft_split_words(char *s, char space);
int			ft_checkargv(int argc, char **argv, int size);
void		ft_errors(int err);
t_turtle	**ft_maketurtles(int argc, char **argv);
t_turtle	*ft_makemove(t_turtle *trtl, int size);

#endif
