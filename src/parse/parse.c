/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:28:40 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/18 15:54:30 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../libft/libft.h"

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
//	printf("before flags: %s$\n", *format);
	parse_flags(format, *arg);
//	printf("before width: %s$\n", *format);
	parse_width(format, va, *arg);
//	printf("before precis: %s$\n", *format);
	parse_precision(format, va, *arg);
//	printf("before length: %s$\n", *format);
	parse_length(format, *arg);
//	printf("before specifier: %s$\n", *format - 1);
//	(*arg)->specifier = '1';
	(*arg)->specifier = *((*format)++);
	if (!(*arg)->specifier)
		(*format)--;
//	printf("specif == 0: %d$\n", (*arg)->specifier == '\0');
//	printf("after specifier: %s$\n", *format - 1);
//	printf("specifier = %c$\n", (*arg)->specifier);
}
