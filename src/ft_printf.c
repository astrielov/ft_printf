/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:56 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 12:51:41 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	buff_realloc(char **buff, int *buff_size)
{
	char	*new_buff;
	int		i;

	if (!*buff)
	{
		*buff = (char *)ft_memalloc((size_t )*buff_size);
		return ;
	}
	new_buff = (char *)ft_memalloc((size_t)*buff_size << 1);
	i = -1;
	while (++i < *buff_size)
		new_buff[i] = (*buff)[i];
	free(*buff);
	*buff = new_buff;
	*buff_size <<= 1;
}

int		inner_pf(char *format, va_list va, char **buff, int *buff_size)
{
	t_pf	*pf;
	int 	buff_ind;

	pf = NULL;
	buff_realloc(buff, buff_size);
	buff_ind = 0;
	while (*format)
	{
		if (buff_ind >= *buff_size)
			buff_realloc(buff, buff_size);
		if (*format != '%')
		{
			(*buff)[buff_ind++] = *format++;
			continue;
		}
		format++;
		parse(&format, va, &pf);
		handle_specifier(va, pf, );
		debug_print_pf(pf);
	}
	return buff_ind;
}

int 	ft_printf(const char *format, ...)
{
	va_list	va;
	char		*buffer;
	int			result;
	int			buff_size;

	buffer = NULL;
	buff_size = 1 << 10; // 1024
	buff_realloc(&buffer, &buff_size);
	va_start(va, format);
	result = inner_pf((char *)format, va, &buffer, &buff_size);
	va_end(va);
	write(1, buffer, (size_t )result);
	ft_memdel((void **) &buffer);
	return result;
}
