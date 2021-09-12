#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>
# include "./libft/libft.h"

int	putchar_fd(char c);
int putstring_fd(char *s, int fd);
int putnbr_fd(int n);

int	unsigned_fd(unsigned int n);

int	hex_str(size_t n, char c);

int	hex_void(size_t n);

int	ft_printf(const char *format, ...);

#endif
