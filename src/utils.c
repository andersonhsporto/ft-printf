#include "../ft_printf.h"

int	putchar_fd(char c)
{
	write(1, &c, 1);
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
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		j++;
	}
	return (j);
}


static int	ft_decimal(size_t n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n != 0)
	{
		n = n / 16;
		++count;
	}
	return (count);
}

int	ft_printhex(char *str, char c)
{
	int i;

	i = 0;
	if (c == 'X')
	{
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	i = putstring_fd(str, 1);
	return (i);
}

int	hex_str(size_t n, char c)
{
	char			*str;
	char			*digits;
	unsigned int	i;

	i = ft_decimal(n);
	digits = "0123456789abcdef";
	str = malloc(i * sizeof(char));
	if (!str)
		return (0);
	while (i)
	{
		str[--i] = base[n % 16];
		n = n / 16;
	}
	i = ft_printhex(str, c);
	free(str);
	return (i);
}

int	hex_void(size_t n)
{
	int i = 0;

	i += putstring_fd("0x", 1);
	i += hex_str(n, 'x');
	return(i);
}
