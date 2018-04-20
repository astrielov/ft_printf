/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:21:37 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 15:24:27 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../libft/libft.h"

void	parse_precision(char **format, va_list va, t_pf *arg)
{
	int	precis;

	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			arg->precision = parse_atoi(format);
			arg->flags |= FLAG_GOT_PRECISION;
		}
		else if (**format == '*')
		{
			if ((precis = va_arg(va, int)) >= 0)
			{
				arg->precision = (unsigned int)precis;
				arg->flags |= FLAG_GOT_PRECISION;
			}
			(*format)++;
		}
		else
		{
			arg->flags |= FLAG_GOT_PRECISION;
			arg->precision = 0;
		}
	}
}
