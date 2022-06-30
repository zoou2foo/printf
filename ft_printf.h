/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:22:49 by vjean             #+#    #+#             */
/*   Updated: 2022/06/30 08:35:47 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

void	ft_putchar(char c, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putstr(char *str, int *len);
void	ft_puthex(unsigned int nb, char str, size_t base, int *len);
void	ft_puthex_p(unsigned long nb, char str, size_t base, int *len);
int		ft_printf(const char *format, ...);

#endif