/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:57:19 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/08 00:29:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int n)
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

static int	print_hex(char *str, char c)
{
	int	i;

	i = 0;
	if (c == 'X')
	{
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	i = putstring_fd(str);
	return (i);
}

static int	hex_c(unsigned int n, char c)
{
	t_types	strc;
	int		i;

	i = hex_len(n);
	strc.digits = "0123456789abcdef";
	strc.str = ft_calloc((i + 1), sizeof(char));
	if (!strc.str)
		return (0);
	while (i)
	{
		i--;
		strc.str[i] = strc.digits[n % 16];
		n = n / 16;
	}
	i = print_hex(strc.str, c);
	free(strc.str);
	strc.str = NULL;
	return (i);
}

int	hex_str(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i += putchar_fd('0');
		return (i);
	}
	return (hex_c(n, c));
}
