#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>
# include "./libft/libft.h"

int	putchar_fd(char c, int fd);
int putstring_fd(char *s, int fd);
int putnbr_fd(int n);

int	unsigned_fd(unsigned int n);

int	hex_str(unsigned int n, char c);

int	hex_void(unsigned int n);

int	ft_printf(const char *format, ...);

#endif