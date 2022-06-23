/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funct_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:21:04 by vjean             #+#    #+#             */
/*   Updated: 2022/06/23 12:42:56 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putnbr(int nb, int *len)
{
	if (nb <= -2147483647)
	{
		write(1, "-2147483648", 11);
		*len += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
		ft_putchar(nb + 48, len);
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_puthex(unsigned long nb, int *len)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, len);
		ft_puthex(nb % 16, len);
	}
	if (nb <= 9)
	{
		ft_putchar(nb + 48, len);
	}
	else
		ft_putchar(nb - 10 + 'a', len);
}
//oubli pas pour 2e if il faut additioner à '0' ou 48