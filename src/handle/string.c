/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:25:33 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/29 10:37:57 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../libft/libft.h"

size_t wstr_bytes_to_print(t_pf *arg, wchar_t *str)
{
	size_t	str_bytes;
	size_t	char_bytes;

	str_bytes = 0;
	while (*str)
	{
		char_bytes = wide_char_bytes(*str++);
		if ((arg->flags & FLAG_GOT_PRECISION) && (str_bytes + char_bytes) > arg->precision)
			break;
		str_bytes += char_bytes;
	}
	return str_bytes;
}

size_t str_bytes_to_print(t_pf *arg, char *str)
{
	size_t	str_bytes;

	str_bytes = ft_strlen(str);
	if ((arg->flags & FLAG_GOT_PRECISION) && str_bytes > arg->precision)
		str_bytes = arg->precision;
	return str_bytes;
}

void	str_pre_padding(t_pf *arg, t_buff *arg_buff, size_t str_bytes_to_print)
{
	char	char_to_fill;

	char_to_fill = (char)(arg->flags & FLAG_ZERO ? '0' : ' ');
	while (!(arg->flags & FLAG_MINUS) && arg->width-- > str_bytes_to_print)
		(arg_buff->buff)[arg_buff->index++] = char_to_fill;
}

void	str_post_padding(t_pf *arg, t_buff *arg_buff, size_t str_bytes_to_print)
{
	char	char_to_fill;

	char_to_fill = ' ';
	while ((arg->flags & FLAG_MINUS) && arg->width-- > str_bytes_to_print)
		(arg_buff->buff)[arg_buff->index++] = char_to_fill;
}

void	fill_str(t_pf *arg, t_buff *arg_buff, wchar_t *str, size_t str_bytes)
{
	char		*chrstr;
	size_t	char_bytes;

	if (arg->specifier == 's')
	{
		chrstr = (char *)str;
		while (str_bytes--)
			arg_buff->buff[arg_buff->index++] = *chrstr++;
	}
	if (arg->specifier == 'S')
	{
		char_bytes = wide_char_bytes(*str);
		while (str_bytes >= char_bytes)
		{
			handle_char(arg, arg_buff, *str++);
			str_bytes -= char_bytes;
			char_bytes = wide_char_bytes(*str);
		}
	}
}

void	handle_string(t_pf *arg, t_buff *arg_buff, wchar_t *str)
{
	size_t	str_bytes;

	if (arg->specifier == 'S')
		str_bytes = wstr_bytes_to_print(arg, str);
	else
		str_bytes = str_bytes_to_print(arg, (char *)str);

	str_pre_padding(arg, arg_buff, str_bytes);
	fill_str(arg, arg_buff, str, str_bytes);
	str_post_padding(arg, arg_buff, str_bytes);
}
