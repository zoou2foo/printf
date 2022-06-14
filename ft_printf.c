/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:14:02 by vjean             #+#    #+#             */
/*   Updated: 2022/06/14 12:00:21 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_machin(const char *str, va_list params, int *len)
{
	if (*str == 'c')
		ft_putchar(va_arg(params, int), len);
	if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(params, int), len);
	if (*str == 's')
		ft_putstr(va_arg(params, char *), len);
	if (*str == '%')
		ft_putchar(va_arg(params, int), len); //nah I don't think it can work.
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
			ft_print_machin(&format[++i], params, &len);
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(params);
	return (len);
}

int	main()
{
	int		a;
	int		b;
	int		d;
	char	c;
	char	str[] = "pew pew madafakas";
	char	*str2;

	a = -2147483648;
	b = 10;
	c = 'c';
	d = 6;
	str2 = NULL;
	printf("Flag c\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %c\n", c));
	printf("J'ai %d caractères\n", printf("REAL: %c\n", c));
	printf("Flag d\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %d\n", a));
	printf("J'ai %d caractères\n", printf("REAL: %d\n", a));
	printf("Flag i\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %i\n", d));
	printf("J'ai %d caractères\n", printf("REAL: %i\n", d));
	printf("Flag s\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %s\n", str));
	printf("J'ai %d caractères\n", printf("REAL: %s\n", str));
	return (0);
}
