#ifndef FT_TURTLES_H
# define FT_TURTLES_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_MOVE 1000

typedef struct		s_turtle
{
	int			y;
	int			x;
	char		*name;
	char		*stack;
	int			dir;
	int			sp;
	char		knock;
}					t_turtle;

typedef struct		s_arena
{
	int			max_y;
	int			max_x;
	int			cuc_y;
	int			cuc_x;
	t_turtle	*(*f)(t_turtle *, struct s_arena);
	int			flags;
	char		knock;
	char		cuc;
}					t_arena;

void		ft_putstr(char *str);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
int			ft_str_is_num(char *str);
int			ft_n_words(char *str, char space);
int			ft_num_is_ok(char *y, char *x, int maxy, int maxx);
char		**ft_split_words(char *s, char space);
int			ft_checkargv(int argc, char **argv, t_arena arena);
void		ft_errors(int err);
t_turtle	**ft_maketurtles(int argc, char **argv, int flags);
t_turtle	*ft_makemove(t_turtle *trtl, t_arena arena);
void		ft_findwinner(t_turtle **trtl, t_arena arena);
t_arena		ft_setarena(void);
t_arena		ft_customarena(t_arena arena, char *str);
t_arena		ft_customcuc(t_arena arena, char *str);
t_arena		ft_set_f(t_arena arena);
t_turtle	*ft_makeonemove(t_turtle *trtl, t_arena arena);
int			ft_changedir(int dir, char com);
t_turtle	*ft_go(t_turtle *trtl, int maxy, int maxx);
t_turtle	*ft_knock_back(t_turtle *trtl, t_arena ar);
void		ft_check_knock(t_turtle **trtl, int i, t_arena arena);
t_arena		ft_set_knock(t_arena arena);
t_arena		ft_set_viz(t_arena arena);

#endif
