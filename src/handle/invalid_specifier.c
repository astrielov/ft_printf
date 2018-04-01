/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:05:23 by astrelov          #+#    #+#             */
/*   Updated: 2018/04/01 19:19:54 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	invalid_specifier(t_pf *arg, t_buff *arg_buff)
{
	if (arg->width && !(arg->flags & FLAG_MINUS))
		push_chars(arg_buff, (char)(arg->flags & FLAG_ZERO ? '0' : ' '), arg->width - 1);
	push_chars(arg_buff, arg->specifier, 1);
	if (arg->width && arg->flags & FLAG_MINUS)
		push_chars(arg_buff, (char)(arg->flags & FLAG_ZERO ? '0' : ' '), arg->width - 1);
}
