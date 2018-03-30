/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:05:23 by astrelov          #+#    #+#             */
/*   Updated: 2018/03/30 16:41:56 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	pre_padding_octal(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	size_t 	precis = arg->precision;
	size_t 	width = arg->width;
	char	char_to_fill;

	if ((arg->flags & FLAG_ZERO) && !(arg->flags & FLAG_GOT_PRECISION))
		char_to_fill = '0';
	else
		char_to_fill = ' ';
	if (width > precis && precis > nbr_len && !(arg->flags & FLAG_MINUS))
		push_chars(arg_buff, ' ', width - precis);
	if (width > nbr_len && nbr_len > precis && (arg->flags & FLAG_GOT_PRECISION) && !(arg->flags & FLAG_MINUS))
		push_chars(arg_buff, char_to_fill, width - nbr_len);
	if (width > precis && precis == nbr_len && !(arg->flags & FLAG_MINUS))
		push_chars(arg_buff, char_to_fill, width - precis);
	if (width > nbr_len && !(arg->flags & FLAG_GOT_PRECISION) && !(arg->flags & FLAG_MINUS))
		push_chars(arg_buff, char_to_fill, width - nbr_len);
	if (precis > nbr_len)
		push_chars(arg_buff, '0', precis - nbr_len);
}

void	fill_octal(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	if (arg->flags & FLAG_HASH)
	{
		push_chars(arg_buff, '0', 1);
		nbr_len--;
	}
	while (nbr_len--)
		(arg_buff->buff)[arg_buff->index++] = *nbr_str++;
}

void	post_padding_octal(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	if (arg->width > nbr_len && nbr_len > arg->precision)
		push_chars(arg_buff, ' ', arg->width - nbr_len);
	if (arg->width > arg->precision && arg->precision >= nbr_len)
		push_chars(arg_buff, ' ', arg->width - arg->precision);
}

void	octal(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	if (*nbr_str == '0' && nbr_len == 1 && arg->flags & FLAG_GOT_PRECISION)
		nbr_len = 0;
	if (arg->flags & FLAG_HASH)
		nbr_len += 1;
	pre_padding_octal(arg, arg_buff, nbr_len);
	fill_octal(arg, arg_buff, nbr_str, nbr_len);
	if (arg->flags & FLAG_MINUS)
		post_padding_octal(arg, arg_buff, nbr_len);
}