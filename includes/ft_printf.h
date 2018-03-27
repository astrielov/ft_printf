/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:38 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/27 21:10:21 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_NEW_FT_PRINTF_H
# define FT_PRINTF_NEW_FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>

#define PRINTF_BUFF_SIZE

typedef struct 		s_pf
{
	unsigned int		flags;
	char 						*buf;
	size_t 					buff_size;
}									t_pf;

#endif
