/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:56 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/18 15:20:25 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

void	debug_print_pf(t_pf *arg)
{
	char 	**flags = (char **)ft_memalloc(sizeof(char *) * 8);
	char 	**length = (char **)ft_memalloc(sizeof(char *) * 7);

	flags[0] = arg->flags & FLAG_GOT_PRECISION ? "GOT_PRECISION" : NULL;
	flags[1] = arg->flags & FLAG_MINUS ? "MINUS" : NULL;
	flags[2] = arg->flags & FLAG_ZERO ? "ZERO" : NULL;
	flags[3] = arg->flags & FLAG_PLUS ? "PLUS" : NULL;
	flags[4] = arg->flags & FLAG_HASH ? "HASH" : NULL;
	flags[5] = arg->flags & FLAG_SPACE ? "SPACE" : NULL;
	flags[6] = arg->flags & FLAG_UPPERCASE ? "UPPERCASE" : NULL;
	flags[7] = arg->flags ? NULL : "";

	length[0] = arg->length & LENGTH_SHORT_SHORT ? "SHORT_SHORT" : NULL;
	length[1] = arg->length & LENGTH_SHORT ? "SHORT" : NULL;
	length[2] = arg->length & LENGTH_LONG_LONG ? "LONG_LONG" : NULL;
	length[3] = arg->length & LENGTH_LONG ? "LONG" : NULL;
	length[4] = arg->length & LENGTH_SIZE_T ? "SIZE_T" : NULL;
	length[5] = arg->length & LENGTH_INTMAX ? "INTMAX" : NULL;
	length[6] = arg->length ? NULL : "";

	for (int i = 0; i < 8; i++)
		if (flags[i])
			printf("\tFLAG: %s \n", flags[i]);

	for (int i = 0; i < 7; i++)
		if (length[i])
			printf("\tLENGTH: %s \n", length[i]);

	free(flags);
	free(length);

	printf("\tflag = %u, width = %u, presicion = %u, length = %u, specifier = %c \n",
		   arg->flags, arg->width, arg->precision, arg->length, arg->specifier);
}

void		inner_pf(char *format, va_list va, t_buff *buff)
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
			push_chars(buff, *format++, 1);
			continue;
		}
		if (*(++format))
		{
			parse(&format, va, &arg_params);
//			debug_print_pf(arg_params);
			arg_buff = handle_argument(va, arg_params);
			concat_buffs(buff, &arg_buff);
		}
	}
	ft_memdel((void **) &arg_params);
}

int 	ft_printf(const char *format, ...)
{
	va_list	va;
	t_buff	*buff;
	int			result;

	buff = (t_buff *)ft_memalloc(sizeof(t_buff));
	buff_realloc(buff);
	va_start(va, format);
	inner_pf((char *)format, va, buff);
	va_end(va);
	result = (int)buff->index;
	write(1, buff->buff, buff->index);
	ft_memdel((void **) &(buff->buff));
	ft_memdel((void **) &buff);
	return result;
}
