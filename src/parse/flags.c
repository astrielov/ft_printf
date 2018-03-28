/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:28:14 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 09:52:03 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	parse_flags(char **format, t_pf *arg)
{
	while (1)
	{
		if (**format == '+')
			arg->flags |= FLAG_PLUS;
		else if (**format == '#')
			arg->flags |= FLAG_HASH;
		else if (**format == '-')
			arg->flags |= FLAG_MINUS;
		else if (**format == ' ')
			arg->flags |= FLAG_SPACE;
		else if (**format == '0')
			arg->flags |= FLAG_ZERO;
		else
			break;
		(*format)++;
	}
}
