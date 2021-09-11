#include "../ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	j = 0;
	va_list	argo;

	if (!format)
		return (0);
	va_start(argo, format);
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspduixX%", *(format + 1)))
		{
				if (*(format + 1) == '%')
				{
					j += putchar_fd('%');
				}
				else if (*(format + 1) == 'c')
				{
					j += putchar_fd(va_arg(argo, int));
				}
				else if (*(format + 1) == 's')
				{
					j += putstring_fd(va_arg(argo, char *), 1);
				}
				else if (*(format + 1) == 'p')
				{
					j += hex_void(va_arg(argo, unsigned int));
				}
				else if (*(format + 1) == 'd' || *(format + 1) == 'i')
				{
					j += putnbr_fd(va_arg(argo, int));
				}
				else if (*(format + 1) == 'u')
				{
					j += unsigned_fd(va_arg(argo, unsigned int));
				}
				else if (*(format + 1) == 'x' || *(format + 1) == 'X')
				{
					j += hex_str(va_arg(argo, unsigned int), *(format + 1));
				}
				format++;
		}
		else
		{
			j += putchar_fd(*format);
		}
		format++;
	}
	va_end(argo);
	return(j);
}
