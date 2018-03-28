/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:56 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 21:51:57 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		inner_pf(char *format, va_list va, t_buff *buff)
{
	t_pf		*arg_params;
	t_buff	*arg_buff;

	arg_params = NULL;
	buff_realloc(buff);
	while (*format)
	{
		if (buff->index >= buff->size)
			buff_realloc(buff);
		if (*format != '%')
		{
			(buff->buff)[buff->index++] = (unsigned char)*format++;
			continue;
		}
		format++;
		parse(&format, va, &arg_params);
//		debug_print_pf(arg_params);
		arg_buff = handle_argument(va, arg_params);
		concat_buffs(buff, &arg_buff);
	}
	ft_memdel((void **) &arg_params);
	return ((int )buff->index);
}

int 	ft_printf(const char *format, ...)
{
	va_list	va;
	t_buff	*buff;
	int			result;

	buff = (t_buff *)ft_memalloc(sizeof(t_buff));
	buff_realloc(buff);
	va_start(va, format);
	result = inner_pf((char *)format, va, buff);
	va_end(va);
	write(1, buff->buff, buff->index);
	ft_memdel((void **) &(buff->buff));
	ft_memdel((void **) &buff);
	return result;
}
