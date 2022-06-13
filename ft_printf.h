/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:22:49 by vjean             #+#    #+#             */
/*   Updated: 2022/06/13 12:52:32 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

//mettre les fonctions utilisées ci-bas...

typedef struct s_list //pour printf probablement va_start et cie ou à ne pas faire?
{
	void				*content;
	struct s_list *next;
}						t_list;

//t_list ajouté après


#endif