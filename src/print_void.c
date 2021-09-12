#include "../ft_printf.h"

int	putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstring_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], fd);
		i++;
	}
	return (i);
}

int	putnbr_fd(int n)
{
	int		i;
	char	*string;

	string = ft_itoa(n);
	i = putstring_fd(string, 1);
	free(string);
	string = NULL;
	return (i);
}

int	unsigned_fd(unsigned int n)
{
	unsigned int	i;
	int				j;

	i = n;
	j = 0;
	if (i > 9)
	{
		unsigned_fd(i / 10);
	}
	ft_putchar_fd(i % 10 + '0', 1);
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		j++;
	}
	return (j);
}
