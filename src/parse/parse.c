/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:28:40 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 11:23:30 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../libft/libft.h"

unsigned int	parse_atoi(char **format)
{
	unsigned int	res;

	res = 0;
	while (ft_isdigit(**format))
		res = res * 10 + *((*format)++) - '0';
	return (res);
}

void	pf_realloc(t_pf **pf)
{
	if (*pf)
		free(*pf);
	*pf = (t_pf *)ft_memalloc(sizeof(t_pf));
}

void	parse(char **format, va_list va, t_pf **pf)
{
	pf_realloc(pf);
	parse_flags(format, *pf);
	parse_width(format, va, *pf);
	parse_precision(format, va, *pf);
	parse_length(format, *pf);
	(*pf)->specifier = *((*format)++);
}
