/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:28:47 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/08 00:28:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(size_t n)
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

static int	void_str(size_t n)
{
	t_types			strc;
	unsigned int	i;

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
	i = putstring_fd(strc.str);
	free(strc.str);
	strc.str = NULL;
	return (i);
}

int	hex_void(size_t n)
{
	int	i;

	i = 0;
	i += putstring_fd("0x");
	i += void_str(n);
	return (i);
}
