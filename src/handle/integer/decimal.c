/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:06:24 by astrelov          #+#    #+#             */
/*   Updated: 2018/03/30 15:47:38 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	pre_padding_decimal(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	arg += 0; arg_buff += 0; nbr_len += 0;
	if (arg->nbr_is_negative)
		(arg_buff->buff)[arg_buff->index++] = '-';
}

void	fill_decimal(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	arg += 0; arg_buff += 0; nbr_len += 0;
	while (*nbr_str)
		(arg_buff->buff)[arg_buff->index++] = *nbr_str++;
}

void	post_padding_decimal(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	arg += 0; arg_buff += 0; nbr_len += 0;
}

void	decimal(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	pre_padding_decimal(arg, arg_buff, nbr_len);
	fill_decimal(arg, arg_buff, nbr_str, nbr_len);
	post_padding_decimal(arg, arg_buff, nbr_len);
}
