/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:38 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 11:10:46 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_NEW_FT_PRINTF_H
# define FT_PRINTF_NEW_FT_PRINTF_H

#include <stdio.h>

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#define FLAG_ZERO						(1 << 0)
#define FLAG_MINUS					(1 << 1)
#define FLAG_PLUS						(1 << 2)
#define FLAG_SPACE					(1 << 3)
#define FLAG_HASH						(1 << 4)
#define FLAG_UPPERCASE			(1 << 5)
#define FLAG_GOT_PRECISION	(1 << 6)
#define LENGTH_SHORT				(1 << 0)
#define LENGTH_SHORT_SHORT	(1 << 1)
#define LENGTH_LONG					(1 << 2)
#define LENGTH_LONG_LONG		(1 << 3)
#define LENGTH_INTMAX				(1 << 4)
#define LENGTH_SIZE_T				(1 << 5)

typedef struct 		s_pf
{
	unsigned int		flags;
	unsigned int		width;
	unsigned int		precision;
	unsigned int		length;
	char 						specifier;
}									t_pf;

int 							ft_printf(const char *format, ...);


unsigned int			parse_atoi(char **format);
void							parse(char **format, va_list va, t_pf **pf);
void							parse_flags(char **format, t_pf *pf);
void							parse_width(char **format, va_list va, t_pf *pf);
void							parse_precision(char **format, va_list va, t_pf *pf);
void							parse_length(char **format, t_pf *pf);
void							parse_specifier(char **format, t_pf *pf);


void	debug_print_pf(t_pf *pf);

#endif
