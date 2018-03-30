/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:39:47 by astrelov          #+#    #+#             */
/*   Updated: 2018/03/30 13:42:40 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	push_chars(t_buff *buff, char c, size_t amount)
{
	while (buff->index + amount >= buff->size)
		buff_realloc(buff);

	while (amount--)
		buff->buff[buff->index++] = c;
}
