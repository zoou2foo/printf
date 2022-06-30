/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:14:02 by vjean             #+#    #+#             */
/*   Updated: 2022/06/30 12:28:48 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spec(const char *str, va_list params, int *len)
{
	if (*str == 'c')
		ft_putchar((unsigned char)va_arg(params, int), len);
	if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(params, int), len);
	if (*str == 's')
		ft_putstr(va_arg(params, char *), len);
	if (*str == 'u')
		ft_puthex((unsigned int)va_arg(params, int), *str, 10, len);
	if (*str == 'p')
	{	
		*len += 2;
		write(1, "0x", 2);
		ft_puthex_p(va_arg(params, unsigned long), *str, 16, len);
	}
	if (*str == 'x' || *str == 'X')
		ft_puthex(va_arg(params, unsigned int), *str, 16, len);
	if (*str == '%')
	{
		*len += 1;
		write(1, "%", 1);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	params;

	len = 0;
	va_start(params, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_print_spec(&format[++i], params, &len);
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(params);
	return (len);
}

/*int	main()
{
	int		a;
	int		b;
	int		c;
	char	d;
	long	e;
	long	f;
	char	str[] = "pew pew madafakas";
	char	*str2;

	a = INT_MIN;
	b = INT_MAX;
	c = 0;
	d = 'c';
	e = LONG_MIN;
	str2 = NULL;
	printf("Spec all fucking lined up\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %c%d%%%i%u%x%X%p%s\n", d, c, a, c, d, d, &e, str));
	printf("J'ai %d\n", printf("REAL: %c%d%%%i%u%x%X%p%s\n", d, c, a, c, d, d, &e, str));
	printf("\nSpec all fucking lined up and fucking mixed 1\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %d%%%i%u%x%X%p%s%c\n", c, a, c, d, d, &e, str, d));
	printf("J'ai %d\n", printf("REAL: %d%%%i%u%x%X%p%s%c\n", c, a, c, d, d, &e, str, d));
	printf("\nSpec all fucking lined up and fucking mixed 2\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %%%i%u%x%X%p%s%c%d\n", a, c, d, d, &e, str, d, c));
	printf("J'ai %d\n", printf("REAL: %%%i%u%x%X%p%s%c%d\n", a, c, d, d, &e, str, d, c));
	printf("\nSpec all fucking lined up and fucking mixed 3\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %i%u%x%X%p%s%c%d%%\n", c, c, d, d, &e, str, d, c));
	printf("J'ai %d\n", printf("REAL: %i%u%x%X%p%s%c%d%%\n", c, c, d, d, &e, str, d, c));
	printf("\nSpec all fucking lined up and fucking mixed 4\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %u%x%X%p%s%c%d%%%i\n", c, d, d, &e, str, d, c, c));
	printf("J'ai %d\n", printf("REAL: %u%x%X%p%s%c%d%%%i\n", c, d, d, &e, str, d, c, c));
	printf("\nSpec all fucking lined up and fucking mixed 5\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %x%X%p%s%c%d%%%i%u\n", d, d, &e, str, d, c, c, c));
	printf("J'ai %d\n", printf("REAL: %x%X%p%s%c%d%%%i%u\n", d, d, &e, str, d, c, c, c));
	printf("\nSpec all fucking lined up and fucking mixed 6\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %X%p%s%c%d%%%i%u%x\n", d, &e, str, d, c, c, c, d));
	printf("J'ai %d\n", printf("REAL: %X%p%s%c%d%%%i%u%x\n", d, &e, str, d, c, c, c, d));
	printf("\nSpec all fucking lined up and fucking mixed 7\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %p%s%c%d%%%i%u%x%X\n",  &e, str, d, c, c, c, d, d));
	printf("J'ai %d\n", printf("REAL: %p%s%c%d%%%i%u%x%X\n", &e, str, d, c, c, c, d, d));
	printf("\nSpec all fucking lined up and fucking mixed 8\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %s%c%d%%%i%u%x%X%p\n", str, d, c, c, c, d, d, &e));
	printf("J'ai %d\n", printf("REAL: %s%c%d%%%i%u%x%X%p\n", str, d, c, c, c, d, d, &e));
	
	printf("\nSpec all fucking mixed up 1\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %c%c%d %i %%fucking annoying\n", d, d, c, d));
	printf("J'ai %d\n", printf("REAL: %c%c%d %i %%fucking annoying\n", d, d, c, d));
	printf("\nSpec all fucking mixed up 2\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %%%%%%% %i %%fucking annoying\n", d, d, c, d));
	printf("J'ai %d\n", printf("REAL: %%%%%%% %i %%fucking annoying\n", d, d, c, d));
	printf("\nSpec all fucking mixed up 3\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %c%c%d %i %%fucking annoying\n", d, d, c, d));
	printf("J'ai %d\n", printf("REAL: %c%c%d %i %%fucking annoying\n", d, d, c, d));
	

    return (0);
}*/