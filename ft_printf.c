/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:14:02 by vjean             #+#    #+#             */
/*   Updated: 2022/06/13 20:31:51 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_machin(const char *str, va_list params, int *len)
{
	if (*str == 'c')
		ft_putchar(va_arg(params, int), len);
	if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(params, int), len);
	/*if (*str == 's')
		ft_putstr(va_arg(params, int), len);*/
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
	char	c;
	char	str[] = "madafakas";
	char	*str2;

	a = -2147483648;
	b = 10;
	c = 'c';
	str2 = NULL;
	printf("Flag c\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %c\n", c));
	printf("J'ai %d caractères\n", printf("REAL: %c\n", c));
	printf("Flag d\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %c\n", a));
	printf("J'ai %d caractères\n", printf("REAL: %c\n", a));
	return (0);
}
