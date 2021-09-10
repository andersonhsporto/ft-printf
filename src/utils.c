#include "../ft_printf.h"

int	putchar_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	putstring_fd(char *s, int fd)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
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
	while (n)
	{
		n /= 10;
		j++;
	}
	return (j);
}

static int	ft_printhex(char *str, char c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (c == 'X')
		{
			ft_putchar_fd(ft_toupper(str[i]), 1);
		}
		if (c == 'x')
		{
			ft_putchar_fd(str[i], 1);
		}
		i--;
	}
	return (ft_strlen(str));
}

static int	ft_decimal(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

int	hex_str(unsigned int n, char c)
{
	int				i;
	int				remain;
	char			*str;

	i = 0;
	remain = 0;
	str = malloc(ft_decimal(n) + 1);
	if (str == 0)
		return (0);
	str[ft_decimal(n)] = '\0';
	while (n > 0)
	{
		remain = n % 16;
		if (remain < 10)
			str[i] = '0' + remain;
		else
			str[i] = 'a' + (remain - 10);
		n = n / 16;
		i++;
	}
	i = ft_printhex(str, c);
	free(str);
	str = NULL;
	return (i);
}

int	hex_void(unsigned int n)
{
	int i = 0;

	i += putstring_fd("0x", 1);	
	i += hex_str(n, 'x');
	return(i);
}

