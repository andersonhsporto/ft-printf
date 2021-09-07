#include "libftprintf.h"
#include "libft/libft.h"

int ft_argcount(char *string)
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
}


int	ft_printf(const char *format, ...)
{
	char *stringteste; 
	if (!format)
		return (0);
	if (!ft_strchr(format, '%'))
		ft_putstr_fd((char *)format, 1);
	return(1);
}

int main(void)
{
	/* int i = ft_argcount("%% %i"); */
	/* printf("%i", i); */
	ft_printf("String\n");
	return (0);
}