#include "libftprintf.h"

int	putchar_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	putstring_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}

int	putnbr_fd(int n, int fd)
{
	int		i;
	char	*string;

	string = ft_itoa(n);
	i = putstring_fd(string, fd);
	free(string);
	string = NULL;
	return (i);
}
