/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csdui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:57:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/09/12 18:43:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstring_fd(char *s)
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
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	putnbr_fd(int n)
{
	int		i;
	char	*string;

	string = ft_itoa(n);
	i = putstring_fd(string);
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
	ft_putchar_fd((i % 10) + '0', 1);
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		j++;
	}
	return (j);
}
