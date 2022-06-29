/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:14:02 by vjean             #+#    #+#             */
/*   Updated: 2022/06/29 16:32:18 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spec(const char *str, va_list params, int *len)
{
	if (*str == 'c')
		ft_putchar(va_arg(params, int), len);
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
		ft_puthex(va_arg(params, unsigned long), *str, 16, len);
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

int	main()
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
	c = 10;
	d = 'c';
	e = LONG_MIN;
	f = LONG_MAX
	str2 = NULL;
	printf("Flag all fucked up together\n");
	ft_printf("J'ai %d\n", ft_printf("MIEN: %c%X%s%u %i %d %%%p%x\n", d));
	printf("J'ai %d\n", printf("REAL: %c%p%s%% % \n", c, &c, str));

	return (0);