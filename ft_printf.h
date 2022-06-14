/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:22:49 by vjean             #+#    #+#             */
/*   Updated: 2022/06/13 20:31:13 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(char c, int *len);
void	ft_putnbr(int nb, int *len);
/*void	ft_putstr(char *str, int *len);
void	ft_puthex(int nb, int *len);*/

#endif