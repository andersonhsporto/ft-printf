#include "libftprintf.h"
#include "libft/libft.h"

/* int ft_argcount(char *string)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string[j] != '\0')
	{
		if ((string[j] == '%'))
		{
			if (ft_strchr("cspdiuxX", string[j + 1]))
				i++;
		}
		j++;
	}
	return (i);
} */


int	ft_printf(const char *format, ...)
{
	if (!format)
		return (0);
	if (!ft_strchr(format, '%'))
		ft_putstr_fd((char *)format, 1);
	int i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX", format[i + 1]))
			printf("ok !");
		ft_putchar_fd(format[i], 1);
		i++;
	}
	return(1);
}

int main(void)
{
	/* int i = ft_argcount("%% %i"); */
	/* printf("%i", i); */
	ft_printf("String%iString2\n");
	return (0);
}

/* int	ft_printf(const char *format, ...)
{
	if (!format)
		return (0);
	if (!ft_strchr(format, '%'))
		ft_putstr_fd((char *)format, 1);
	int i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX", format[i + 1]))
			printf("ok !");
		ft_putchar_fd(format[i], 1);
		i++;
	}
	return(1);
} */
