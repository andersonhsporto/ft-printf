#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int	j = 0;
	va_list	argo;

	if (!format)
		return (0);
	i = 0;
	va_start(argo, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX", format[i + 1]))
		{
				if (format[i + 1] == 'c')
				{
					j += putchar_fd(va_arg(argo, int), 1);
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
				if (format[i + 1] == 's')
				{
					j += putstring_fd(va_arg(argo, char *), 1);
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
				if (format[i + 1] == 'p')
				{
					ft_putchar_fd(va_arg(argo, int), 1); //void teste
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
				if (format[i + 1] == 'd' || format[i + 1] == 'i')
				{
					j += putnbr_fd(va_arg(argo, int), 1);
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
		}
		ft_putchar_fd(format[i], 1);
		i++;
		j++;
	}
	va_end(argo);
	printf("%i", j);
	return(j);
}

int main(void)
{
/* 	int i = ft_argcount("%% %i");
	printf("%i", i); */
	/* char *casa = "string"; */
	ft_printf("%d", 111);
	printf("\n");
	printf("%d", 111);
	return (0);
}
