#ifndef FT_TURTLES_H
# define FT_TURTLES_H

# include <unistd.h>
# include <stdlib.h>
//
# include <stdio.h>

typedef struct		s_turtle
{
	int		adr;
	char	*name;
	char	*stack;
	char	direction;
}					t_turtle;
//
int			ft_strlen(char *str);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
int			ft_getadr(int i, int j, int size);
int			ft_n_words(char *str, char space);
char		**ft_split_words(char *s, char space);
int			ft_checkargv(int argc, char **argv, int size);
void		ft_errors(int err);
t_turtle	**ft_maketurtles(int argc, char **argv, int size);




#endif
