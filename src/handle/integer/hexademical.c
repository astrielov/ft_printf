/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexademical.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:06:09 by astrelov          #+#    #+#             */
/*   Updated: 2018/03/30 15:46:48 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"


void	pre_padding_hexademical(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	arg += 0; arg_buff += 0; nbr_len += 0;
	if (arg->nbr_is_negative)
		(arg_buff->buff)[arg_buff->index++] = '-';
}

void	fill_hexademical(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	arg += 0; arg_buff += 0; nbr_len += 0;
	while (*nbr_str)
		(arg_buff->buff)[arg_buff->index++] = *nbr_str++;
}

void	post_padding_hexademical(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	arg += 0; arg_buff += 0; nbr_len += 0;
}

void	hexademical(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	pre_padding_hexademical(arg, arg_buff, nbr_len);
	fill_hexademical(arg, arg_buff, nbr_str, nbr_len);
	post_padding_hexademical(arg, arg_buff, nbr_len);
}
