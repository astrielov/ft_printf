/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:30:22 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 15:56:03 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		parse_length(char **format, t_pf *arg)
{
	int 			found;
	unsigned int	length;

	found = 0;
	length = 0;
	if (**format == 'h')
	{
		found = 1;
		length = (*(*format + 1) == 'h') ? LENGTH_SHORT_SHORT : LENGTH_SHORT;
		*format += length == LENGTH_SHORT ? 1 : 2;
	}
	else if (**format == 'l')
	{
		found = 1;
		length = (*(*format + 1) == 'l') ? LENGTH_LONG_LONG : LENGTH_LONG;
		*format += length == LENGTH_LONG ? 1 : 2;
	}
	else if (**format == 'j')
	{
		found = 1;
		length = LENGTH_INTMAX;
		*format += 1;
	}
	else if (**format == 'z')
	{
		found = 1;
		length = LENGTH_SIZE_T;
		*format += 1;
	}
	if (!arg->length && length)
		arg->length = length;
	return (found);
}
