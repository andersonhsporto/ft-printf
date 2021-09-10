#include "../ft_printf.h"

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
		if (format[i] == '%' && ft_strchr("%cspdiuxX", format[i + 1]))
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
					j += hex_void(va_arg(argo, size_t));
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
				if (format[i + 1] == 'd' || format[i + 1] == 'i')
				{
					j += putnbr_fd(va_arg(argo, int));
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
				if (format[i + 1] == 'u')
				{
					j += unsigned_fd(va_arg(argo, unsigned int));
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
				if (format[i + 1] == '%')
				{
					j += putchar_fd('%', 1);
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
				if (format[i + 1] == 'x' || format[i + 1] == 'X')
				{
					j += hex_str(va_arg(argo, unsigned int), format[i + 1]);
					if (format[i + 2] == '\0')
						break ;
					i += 2;
				}
		}
		ft_putchar_fd(format[i], 1);
		j++;
		i++;
	}
	va_end(argo);
	return(j);
}

/* int main(void)
{ 	int i = ft_argcount("%% %i");
	printf("%i", i); 
	 char *casa = "string";
int	nb = -11;
	unsigned int j = nb; 
	printf("%p", "teste");
	printf("\n");
	ft_printf("%p", "teste");
	printf("\n");
	return (0);
}
 */