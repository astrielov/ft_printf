/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:34:17 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 17:38:11 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		prepare_number(t_pf *arg)
{
	if (arg->specifier == 'X' || arg->specifier == 'x')
		arg->base = 16;
	else if (arg->specifier == 'o' || arg->specifier == 'O')
		arg->base = 8;
	else
	{
		arg->base = 10;
		arg->flags &= ~FLAG_HASH;
	}

	if (arg->specifier == 'X' || arg->specifier == 'O')
		arg->flags |= FLAG_UPPERCASE;

	if (arg->specifier == 'D' || arg->specifier == 'U')
	{
		arg->specifier += 32;
		arg->length = LENGTH_LONG;
	}

	if (!(arg->specifier == 'i' || arg->specifier == 'd'))
		arg->flags &= ~(FLAG_PLUS | FLAG_SPACE);
}

void	handle_number(t_pf *arg, t_buff *arg_buff, uintmax_t nbr)
{
	prepare_number(arg);

}
