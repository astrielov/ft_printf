/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:30:22 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 10:52:18 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	parse_length(char **format, t_pf *pf)
{
	if (**format == 'h')
		pf->length = (*(*format + 1) == 'h') ? LENGTH_SHORT_SHORT : LENGTH_SHORT;
	else if (**format == 'l')
		pf->length = (*(*format + 1) == 'l') ? LENGTH_LONG_LONG : LENGTH_LONG;
	else if (**format == 'j')
		pf->length = LENGTH_INTMAX;
	else if (**format == 'z')
		pf->length = LENGTH_SIZE_T;
	if (pf->length)
		*format += (pf->length == LENGTH_LONG_LONG ||
			pf->length == LENGTH_SHORT_SHORT) ? 2 : 1;
}
