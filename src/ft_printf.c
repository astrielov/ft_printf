/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:56 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/27 21:14:40 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		inner_pf(const char *format, va_list va, char **buff)
{

}

int 	ft_printf(const char *format, ...)
{
	va_list	va;
	char		*buffer;
	int			result;

	va_start(va, format);
	result = inner_pf(format, va, &buffer);
	ft_putstr(buffer);
	return result;
}
