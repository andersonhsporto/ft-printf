/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:09:18 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/09/12 21:09:23 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
