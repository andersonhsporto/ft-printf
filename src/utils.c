/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:30:50 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/09/11 21:30:51 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
