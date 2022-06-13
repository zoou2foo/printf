/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:14:02 by vjean             #+#    #+#             */
/*   Updated: 2022/06/13 15:00:30 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	if (i == c)
		ft_putchar()
	
	if (i == s)
		ft_putstr()
	
	if (i == p)
		ft_puthex()
	
	if (i == d)
		ft_putnbr()
	
	if (i == i)
		ft_putnbr()
	if (i == u)
		ft_putnbr()
	if (i == x)
		ft_puthex()
	
	if (i == X)
		ft_puthex()
	if (i == %)
		ft_putchar() //to check; not sure...

}

int	main()
{
	int		a;
	int		b;
	char	c;
	char	str[];
	char	*str2;

	a = -2147483648;
	b = 10;
	c = 'c';
	str[] = "madafakas";
	str2 = NULL;
	printf("Flag c\n");
	ft_printf("J'ai %d caractères\n", ft_printf("MIEN: %c\n", c));
	printf("J'ai %d caractères\n", printf("REAL: %c\n", c));
	return (0);
}
