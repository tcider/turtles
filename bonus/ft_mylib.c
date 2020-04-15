#include "ft_turtles.h"

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

int		ft_atoi(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num > 214748364) || (num == 214748364 && (str[i] - '0') > 7))
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
