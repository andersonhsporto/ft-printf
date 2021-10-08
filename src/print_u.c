/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:09:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/08 00:07:24 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_fd(unsigned int n)
{
	unsigned int	i;
	static int	j;

	i = n;
	if (!j)
		j = 0;
	if (i > 9)
	{
		unsigned_fd(i / 10);
	}
	ft_putchar_fd((i % 10) + '0', 1);
	j++;
	if (n == 0)
		return (1);
	return (j);
}
