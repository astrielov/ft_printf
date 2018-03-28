/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:28:40 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 11:36:27 by astrielov        ###   ########.fr       */
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

void	pf_realloc(t_pf **arg)
{
	if (*arg)
		free(*arg);
	*arg = (t_pf *)ft_memalloc(sizeof(t_pf));
}

void	parse(char **format, va_list va, t_pf **arg)
{
	pf_realloc(arg);
	parse_flags(format, *arg);
	parse_width(format, va, *arg);
	parse_precision(format, va, *arg);
	parse_length(format, *arg);
	(*arg)->specifier = *((*format)++);
}
