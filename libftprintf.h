#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>
# include "libft/libft.h"

int	putchar_fd(char c, int fd);
int putstring_fd(char *s, int fd);
int putnbr_fd(int n, int fd);

int	ft_printf(const char *format, ...);

#endif