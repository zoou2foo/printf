/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:14:02 by vjean             #+#    #+#             */
/*   Updated: 2022/06/14 20:33:17 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//%s: I need to send a char * as the type, otherwise segfault. It goes to the
//address of the pointer to get the string.

#include "ft_printf.h"

void	ft_print_machin(const char *str, va_list params, int *len)
{
	if (*str == 'c')
		ft_putchar(va_arg(params, int), len);
	if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(params, int), len);
	if (*str == 's')
		ft_putstr(va_arg(params, char *), len);
	if (*str == 'u')
		ft_putnbr(va_arg(params, int), len);
	if (*str == 'x' || *str == 'X')
		ft_puthex(va_arg(params, int), len);
		
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
	printf("Flag x\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %x\n", d));
	printf("J'ai %d caractères\n", printf("REAL: %x\n", d));
	printf("Flag X\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %X\n", d));
	printf("J'ai %d caractères\n", printf("REAL: %X\n", d));
	return (0);
}
/*printf("Flag c\n");
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
	printf("Flag u\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %u\n", b));
	printf("J'ai %d caractères\n", printf("REAL: %u\n", b)); */