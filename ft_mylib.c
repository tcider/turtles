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
