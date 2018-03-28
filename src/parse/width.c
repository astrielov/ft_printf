/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:55:43 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 10:12:39 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../libft/libft.h"

void	parse_width(char **format, va_list va, t_pf *arg)
{
	int 	w;

	while (1)
	{
		if (ft_isdigit(**format))
			arg->width = parse_atoi(format);
		else if (**format == '*')
		{
			if ((w = va_arg(va, int)) < 0)
			{
				arg->flags |= FLAG_MINUS;
				arg->width = (unsigned int)-w;
			}
			else
				arg->width = (unsigned int)w;
			(*format)++;
		}
		else
			break;
	}
}
