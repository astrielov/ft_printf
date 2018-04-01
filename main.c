/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:55:40 by astrelov          #+#    #+#             */
/*   Updated: 2018/04/01 20:04:32 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <locale.h>
#include <limits.h>

void	int_helper(int *failed, int *succeed, char *s, int n)
{
	int 	a = 0, b = 0;

	a = ft_printf(s, n);
	puts("$");
	b = printf(s, n);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;
}

void	string_helper(int *failed, int *succeed, char *s, char *s2)
{
	int 	a = 0, b = 0;

	a = ft_printf(s, s2);
	puts("$");
	b = printf(s, s2);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;
}

void	char_helper(int *failed, int *succeed, char *s, char chr)
{
	int a = 0, b = 0;

	a = ft_printf(s, chr);
	puts("$");
	b = printf(s, chr);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;
}

void	wide_char_helper(int *failed, int *succeed, char *s, wchar_t chr)
{
	int a = 0, b = 0;

	a = ft_printf(s, chr);
	puts("$");
	b = printf(s, chr);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;
}

void	wide_string_helper(int *failed, int *succeed, char *s, wchar_t *str)
{
	int a = 0, b = 0;

	a = ft_printf(s, str);
	puts("$");
	b = printf(s, str);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;
}

void	pointer_helper(int *failed, int *succeed, char *s, void *p)
{
	int a = 0, b = 0;

	a = ft_printf(s, p);
	puts("$");
	b = printf(s, p);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;
}

void	decimal_signed_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> DECIMAL SIGNED <<<<\033[0m\n\n\n");

	int_helper(failed, succeed, "%d", 42);
	int_helper(failed, succeed, "%D", 42);
	int_helper(failed, succeed, "%D", LONG_MAX);
	int_helper(failed, succeed, "%D", LONG_MIN);
	int_helper(failed, succeed, "%d", 0);
	int_helper(failed, succeed, "%.d", 0);
	int_helper(failed, succeed, "%8d", 2500);
	int_helper(failed, succeed, "%08d", 2500);
	int_helper(failed, succeed, "%6d", -2500);
	int_helper(failed, succeed, "%3d", 2500);
	int_helper(failed, succeed, "%3d", -2500);
	int_helper(failed, succeed, "%.6d", 2500);
	int_helper(failed, succeed, "%.3d", 2500);
	int_helper(failed, succeed, "%8.3d", -2500);
	int_helper(failed, succeed, "%6d", -2500);
	int_helper(failed, succeed, "%.3d", -2500);
	int_helper(failed, succeed, "%.6d", -2500);
	int_helper(failed, succeed, "% .3d", 2500);
	int_helper(failed, succeed, "%+.3d", -2500);
	int_helper(failed, succeed, "%+.6d", 2500);
	int_helper(failed, succeed, "% 15.3d", -2500);
	int_helper(failed, succeed, "% .7d", 2500);
	int_helper(failed, succeed, "%08d", 2500);
	int_helper(failed, succeed, "%015.3d", 2500);
	int_helper(failed, succeed, "%015.8d", 2500);
	int_helper(failed, succeed, "%15.4d", 2500);
	int_helper(failed, succeed, "%015.3d", -2500);
	int_helper(failed, succeed, "%015.13d", -2500);
	int_helper(failed, succeed, "%3.d", 0);
	int_helper(failed, succeed, "%03.d", 0);
	int_helper(failed, succeed, "%3.2d", 0);
	int_helper(failed, succeed, "%015.13d", -2500);
	int_helper(failed, succeed, "%hhD", USHRT_MAX);
	int_helper(failed, succeed, "%#8.3d", -2500);
	int_helper(failed, succeed, "%#15.3d", -2500);
	int_helper(failed, succeed, "%#6d", 2500);
	int_helper(failed, succeed, "%#3d", 2500);
	int_helper(failed, succeed, "%#.4d", 2500);
	int_helper(failed, succeed, "%#.d", 0);
	int_helper(failed, succeed, "%#3.d", 0);
	int_helper(failed, succeed, "%#3.2d", 0);
	int_helper(failed, succeed, "%#08d", 42);
	int_helper(failed, succeed, "%#.7d", 2500);
	int_helper(failed, succeed, "%#020.13d", -2500);
	int_helper(failed, succeed, "%#.3d", 2500);
	int_helper(failed, succeed, "%#.2d", 2500);
	int_helper(failed, succeed, "%#d", 0);

	printf("\033[32;1m\t\t\t>>>> DECIMAL SIGNED FLAG MINUS <<<<\033[0m\n\n\n");

	int_helper(failed, succeed, "%-d", 42);
	int_helper(failed, succeed, "%-D", 42);
	int_helper(failed, succeed, "%-D", LONG_MAX);
	int_helper(failed, succeed, "%-D", LONG_MIN);
	int_helper(failed, succeed, "%-d", 0);
	int_helper(failed, succeed, "%-.d", 0);
	int_helper(failed, succeed, "%-8d", 2500);
	int_helper(failed, succeed, "%-08d", 2500);
	int_helper(failed, succeed, "%-6d", -2500);
	int_helper(failed, succeed, "%-3d", 2500);
	int_helper(failed, succeed, "%-3d", -2500);
	int_helper(failed, succeed, "%-.6d", 2500);
	int_helper(failed, succeed, "%-.3d", 2500);
	int_helper(failed, succeed, "%-8.3d", -2500);
	int_helper(failed, succeed, "%-6d", -2500);
	int_helper(failed, succeed, "%-.3d", -2500);
	int_helper(failed, succeed, "%-.6d", -2500);
	int_helper(failed, succeed, "%- .3d", 2500);
	int_helper(failed, succeed, "%-+.3d", -2500);
	int_helper(failed, succeed, "%-+.6d", 2500);
	int_helper(failed, succeed, "%- 15.3d", -2500);
	int_helper(failed, succeed, "%- .7d", 2500);
	int_helper(failed, succeed, "%-08d", 2500);
	int_helper(failed, succeed, "%-015.3d", 2500);
	int_helper(failed, succeed, "%-015.8d", 2500);
	int_helper(failed, succeed, "%-15.4d", 2500);
	int_helper(failed, succeed, "%-015.3d", -2500);
	int_helper(failed, succeed, "%-015.13d", -2500);
	int_helper(failed, succeed, "%-3.d", 0);
	int_helper(failed, succeed, "%-03.d", 0);
	int_helper(failed, succeed, "%-3.2d", 0);
	int_helper(failed, succeed, "%-015.13d", -2500);
	int_helper(failed, succeed, "%-hhD", USHRT_MAX);
	int_helper(failed, succeed, "%-#8.3d", -2500);
	int_helper(failed, succeed, "%-#15.3d", -2500);
	int_helper(failed, succeed, "%-#6d", 2500);
	int_helper(failed, succeed, "%-#3d", 2500);
	int_helper(failed, succeed, "%-#.4d", 2500);
	int_helper(failed, succeed, "%-#.d", 0);
	int_helper(failed, succeed, "%-#3.d", 0);
	int_helper(failed, succeed, "%-#3.2d", 0);
	int_helper(failed, succeed, "%-#08d", 42);
	int_helper(failed, succeed, "%-#.7d", 2500);
	int_helper(failed, succeed, "%-#020.13d", -2500);
	int_helper(failed, succeed, "%-#.3d", 2500);
	int_helper(failed, succeed, "%-#.2d", 2500);
	int_helper(failed, succeed, "%-#d", 0);
}

void	decimal_unsigned_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> DECIMAL UNSIGNED <<<<\033[0m\n\n\n");

	int_helper(failed, succeed, "%u", 42);
	int_helper(failed, succeed, "%U", 42);
	int_helper(failed, succeed, "%U", LONG_MAX);
	int_helper(failed, succeed, "%U", LONG_MIN);
	int_helper(failed, succeed, "%u", 0);
	int_helper(failed, succeed, "%.u", 0);
	int_helper(failed, succeed, "%8u", 2500);
	int_helper(failed, succeed, "%08u", 2500);
	int_helper(failed, succeed, "%6u", -2500);
	int_helper(failed, succeed, "%3u", 2500);
	int_helper(failed, succeed, "%3u", -2500);
	int_helper(failed, succeed, "%.6u", 2500);
	int_helper(failed, succeed, "%.3u", 2500);
	int_helper(failed, succeed, "%8.3u", -2500);
	int_helper(failed, succeed, "%6u", -2500);
	int_helper(failed, succeed, "%.3u", -2500);
	int_helper(failed, succeed, "%.6u", -2500);
	int_helper(failed, succeed, "% .3u", 2500);
	int_helper(failed, succeed, "%+.3u", -2500);
	int_helper(failed, succeed, "%+.6u", 2500);
	int_helper(failed, succeed, "% 15.3u", -2500);
	int_helper(failed, succeed, "% .7u", 2500);
	int_helper(failed, succeed, "%08u", 2500);
	int_helper(failed, succeed, "%015.3u", 2500);
	int_helper(failed, succeed, "%015.8u", 2500);
	int_helper(failed, succeed, "%15.4u", 2500);
	int_helper(failed, succeed, "%015.3u", -2500);
	int_helper(failed, succeed, "%015.13u", -2500);
	int_helper(failed, succeed, "%3.u", 0);
	int_helper(failed, succeed, "%03.u", 0);
	int_helper(failed, succeed, "%3.2u", 0);
	int_helper(failed, succeed, "%015.13u", -2500);
	int_helper(failed, succeed, "%hhU", USHRT_MAX);
	int_helper(failed, succeed, "%#8.3u", -2500);
	int_helper(failed, succeed, "%#15.3u", -2500);
	int_helper(failed, succeed, "%#6u", 2500);
	int_helper(failed, succeed, "%#3u", 2500);
	int_helper(failed, succeed, "%#.4u", 2500);
	int_helper(failed, succeed, "%#.u", 0);
	int_helper(failed, succeed, "%#3.u", 0);
	int_helper(failed, succeed, "%#3.2u", 0);
	int_helper(failed, succeed, "%#08u", 42);
	int_helper(failed, succeed, "%#.7u", 2500);
	int_helper(failed, succeed, "%#020.13u", -2500);
	int_helper(failed, succeed, "%#.3u", 2500);
	int_helper(failed, succeed, "%#.2u", 2500);
	int_helper(failed, succeed, "%#u", 0);

	printf("\033[32;1m\t\t\t>>>> DECIMAL UNSIGNED FLAG MINUS <<<<\033[0m\n\n\n");

	int_helper(failed, succeed, "%-u", 42);
	int_helper(failed, succeed, "%-U", 42);
	int_helper(failed, succeed, "%-U", LONG_MAX);
	int_helper(failed, succeed, "%-U", LONG_MIN);
	int_helper(failed, succeed, "%-u", 0);
	int_helper(failed, succeed, "%-.u", 0);
	int_helper(failed, succeed, "%-8u", 2500);
	int_helper(failed, succeed, "%-08u", 2500);
	int_helper(failed, succeed, "%-6u", -2500);
	int_helper(failed, succeed, "%-3u", 2500);
	int_helper(failed, succeed, "%-3u", -2500);
	int_helper(failed, succeed, "%-.6u", 2500);
	int_helper(failed, succeed, "%-.3u", 2500);
	int_helper(failed, succeed, "%-8.3u", -2500);
	int_helper(failed, succeed, "%-6u", -2500);
	int_helper(failed, succeed, "%-.3u", -2500);
	int_helper(failed, succeed, "%-.6u", -2500);
	int_helper(failed, succeed, "%- .3u", 2500);
	int_helper(failed, succeed, "%-+.3u", -2500);
	int_helper(failed, succeed, "%-+.6u", 2500);
	int_helper(failed, succeed, "%- 15.3u", -2500);
	int_helper(failed, succeed, "%- .7u", 2500);
	int_helper(failed, succeed, "%-08u", 2500);
	int_helper(failed, succeed, "%-015.3u", 2500);
	int_helper(failed, succeed, "%-015.8u", 2500);
	int_helper(failed, succeed, "%-15.4u", 2500);
	int_helper(failed, succeed, "%-015.3u", -2500);
	int_helper(failed, succeed, "%-015.13u", -2500);
	int_helper(failed, succeed, "%-3.u", 0);
	int_helper(failed, succeed, "%-03.u", 0);
	int_helper(failed, succeed, "%-3.2u", 0);
	int_helper(failed, succeed, "%-015.13u", -2500);
	int_helper(failed, succeed, "%-hhU", USHRT_MAX);
	int_helper(failed, succeed, "%-#8.3u", -2500);
	int_helper(failed, succeed, "%-#15.3u", -2500);
	int_helper(failed, succeed, "%-#6u", 2500);
	int_helper(failed, succeed, "%-#3u", 2500);
	int_helper(failed, succeed, "%-#.4u", 2500);
	int_helper(failed, succeed, "%-#.u", 0);
	int_helper(failed, succeed, "%-#3.u", 0);
	int_helper(failed, succeed, "%-#3.2u", 0);
	int_helper(failed, succeed, "%-#08u", 42);
	int_helper(failed, succeed, "%-#.7u", 2500);
	int_helper(failed, succeed, "%-#020.13u", -2500);
	int_helper(failed, succeed, "%-#.3u", 2500);
	int_helper(failed, succeed, "%-#.2u", 2500);
	int_helper(failed, succeed, "%-#u", 0);
}

void	octal_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> OCTAL <<<<\033[0m\n\n\n");

	int_helper(failed, succeed, "%o", 42);
	int_helper(failed, succeed, "%O", 42);
	int_helper(failed, succeed, "%O", LONG_MAX);
	int_helper(failed, succeed, "%O", LONG_MIN);
	int_helper(failed, succeed, "%o", 0);
	int_helper(failed, succeed, "%.o", 0);
	int_helper(failed, succeed, "%8o", 2500);
	int_helper(failed, succeed, "%08o", 2500);
	int_helper(failed, succeed, "%6o", -2500);
	int_helper(failed, succeed, "%3o", 2500);
	int_helper(failed, succeed, "%3o", -2500);
	int_helper(failed, succeed, "%.6o", 2500);
	int_helper(failed, succeed, "%.3o", 2500);
	int_helper(failed, succeed, "%8.3o", -2500);
	int_helper(failed, succeed, "%6o", -2500);
	int_helper(failed, succeed, "%.3o", -2500);
	int_helper(failed, succeed, "%.6o", -2500);
	int_helper(failed, succeed, "% .3o", 2500);
	int_helper(failed, succeed, "%+.3o", -2500);
	int_helper(failed, succeed, "%+.6o", 2500);
	int_helper(failed, succeed, "% 15.3o", -2500);
	int_helper(failed, succeed, "% .7o", 2500);
	int_helper(failed, succeed, "%08o", 2500);
	int_helper(failed, succeed, "%015.3o", 2500);
	int_helper(failed, succeed, "%015.8o", 2500);
	int_helper(failed, succeed, "%15.4o", 2500);
	int_helper(failed, succeed, "%015.3o", -2500);
	int_helper(failed, succeed, "%015.13o", -2500);
	int_helper(failed, succeed, "%3.o", 0);
	int_helper(failed, succeed, "%03.o", 0);
	int_helper(failed, succeed, "%3.2o", 0);
	int_helper(failed, succeed, "%015.13o", -2500);
	int_helper(failed, succeed, "%#.o", 0);
	int_helper(failed, succeed, "%#3.2o", 0);
	int_helper(failed, succeed, "%#.7o", 2500);
	int_helper(failed, succeed, "%#8.3o", -2500);
	int_helper(failed, succeed, "%#3.o", 0);
	int_helper(failed, succeed, "%#15.3o", -2500);
	int_helper(failed, succeed, "%#6o", 2500);
	int_helper(failed, succeed, "%hhO", USHRT_MAX);

	printf("\033[32;1m\t\t\t>>>> OCTAL FLAG MINUS <<<<\033[0m\n\n\n");

	int_helper(failed, succeed, "%-.o", 0);
	int_helper(failed, succeed, "%-8o", 2500);
	int_helper(failed, succeed, "%-08o", 2500);
	int_helper(failed, succeed, "%-6o", -2500);
	int_helper(failed, succeed, "%-3o", 2500);
	int_helper(failed, succeed, "%-3o", -2500);
	int_helper(failed, succeed, "%-.3o", 2500);
	int_helper(failed, succeed, "%-8.3o", -2500);
	int_helper(failed, succeed, "%-6o", -2500);
	int_helper(failed, succeed, "%-.3o", -2500);
	int_helper(failed, succeed, "%-.6o", -2500);
	int_helper(failed, succeed, "%- .3o", 2500);
	int_helper(failed, succeed, "%-+.3o", -2500);
	int_helper(failed, succeed, "%-+.6o", 2500);
	int_helper(failed, succeed, "%- 15.3o", -2500);
	int_helper(failed, succeed, "%- .7o", 2500);
	int_helper(failed, succeed, "%-08o", 2500);
	int_helper(failed, succeed, "%-015.3o", 2500);
	int_helper(failed, succeed, "%-015.3o", -2500);
	int_helper(failed, succeed, "%-#.o", 0);
	int_helper(failed, succeed, "%-#.7o", 2500);
	int_helper(failed, succeed, "%-#8.3o", -2500);
	int_helper(failed, succeed, "%-#3.o", 0);
	int_helper(failed, succeed, "%-#15.3o", -2500);
	int_helper(failed, succeed, "%-#6o", 2500);
	int_helper(failed, succeed, "%-.6o", 2500);
	int_helper(failed, succeed, "%-015.8o", 2500);
	int_helper(failed, succeed, "%-015.13o", -2500);
	int_helper(failed, succeed, "%-3.2o", 0);
	int_helper(failed, succeed, "%-015.13o", -2500);
	int_helper(failed, succeed, "%-#3.2o", 0);
	int_helper(failed, succeed, "%-15.4o", 2500);
	int_helper(failed, succeed, "%-3.o", 0);
	int_helper(failed, succeed, "%-03.o", 0);
}

void	hexademical_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> HEXADEMICAL <<<<\033[0m\n\n\n");

	int_helper(failed, succeed, "%x", 42);
	int_helper(failed, succeed, "%X", 42);
	int_helper(failed, succeed, "%X", LONG_MAX);
	int_helper(failed, succeed, "%X", LONG_MIN);
	int_helper(failed, succeed, "%x", 0);
	int_helper(failed, succeed, "%.x", 0);
	int_helper(failed, succeed, "%8x", 2500);
	int_helper(failed, succeed, "%08x", 2500);
	int_helper(failed, succeed, "%6x", -2500);
	int_helper(failed, succeed, "%3x", 2500);
	int_helper(failed, succeed, "%3x", -2500);
	int_helper(failed, succeed, "%.6x", 2500);
	int_helper(failed, succeed, "%.3x", 2500);
	int_helper(failed, succeed, "%8.3x", -2500);
	int_helper(failed, succeed, "%6x", -2500);
	int_helper(failed, succeed, "%.3x", -2500);
	int_helper(failed, succeed, "%.6x", -2500);
	int_helper(failed, succeed, "% .3x", 2500);
	int_helper(failed, succeed, "%+.3x", -2500);
	int_helper(failed, succeed, "%+.6x", 2500);
	int_helper(failed, succeed, "% 15.3x", -2500);
	int_helper(failed, succeed, "% .7x", 2500);
	int_helper(failed, succeed, "%08x", 2500);
	int_helper(failed, succeed, "%015.3x", 2500);
	int_helper(failed, succeed, "%015.8x", 2500);
	int_helper(failed, succeed, "%15.4x", 2500);
	int_helper(failed, succeed, "%015.3x", -2500);
	int_helper(failed, succeed, "%015.13x", -2500);
	int_helper(failed, succeed, "%3.x", 0);
	int_helper(failed, succeed, "%03.x", 0);
	int_helper(failed, succeed, "%3.2x", 0);
	int_helper(failed, succeed, "%015.13x", -2500);
	int_helper(failed, succeed, "%hhX", USHRT_MAX);
	int_helper(failed, succeed, "%#8.3x", -2500);
	int_helper(failed, succeed, "%#15.3x", -2500);
	int_helper(failed, succeed, "%#6x", 2500);
	int_helper(failed, succeed, "%#3x", 2500);
	int_helper(failed, succeed, "%#.4x", 2500);
	int_helper(failed, succeed, "%#.x", 0);
	int_helper(failed, succeed, "%#3.x", 0);
	int_helper(failed, succeed, "%#3.2x", 0);
	int_helper(failed, succeed, "%#08x", 42);
	int_helper(failed, succeed, "%#.7x", 2500);
	int_helper(failed, succeed, "%#020.13x", -2500);
	int_helper(failed, succeed, "%#.3x", 2500);
	int_helper(failed, succeed, "%#.2x", 2500);
	int_helper(failed, succeed, "%#x", 0);

	printf("\033[32;1m\t\t\t>>>> HEXADEMICAL FLAG MINUS <<<<\033[0m\n\n\n");

	int_helper(failed, succeed, "%-x", 42);
	int_helper(failed, succeed, "%-X", 42);
	int_helper(failed, succeed, "%-X", LONG_MAX);
	int_helper(failed, succeed, "%-X", LONG_MIN);
	int_helper(failed, succeed, "%-x", 0);
	int_helper(failed, succeed, "%-.x", 0);
	int_helper(failed, succeed, "%-8x", 2500);
	int_helper(failed, succeed, "%-08x", 2500);
	int_helper(failed, succeed, "%-6x", -2500);
	int_helper(failed, succeed, "%-3x", 2500);
	int_helper(failed, succeed, "%-3x", -2500);
	int_helper(failed, succeed, "%-.6x", 2500);
	int_helper(failed, succeed, "%-.3x", 2500);
	int_helper(failed, succeed, "%-8.3x", -2500);
	int_helper(failed, succeed, "%-6x", -2500);
	int_helper(failed, succeed, "%-.3x", -2500);
	int_helper(failed, succeed, "%-.6x", -2500);
	int_helper(failed, succeed, "%- .3x", 2500);
	int_helper(failed, succeed, "%-+.3x", -2500);
	int_helper(failed, succeed, "%-+.6x", 2500);
	int_helper(failed, succeed, "%- 15.3x", -2500);
	int_helper(failed, succeed, "%- .7x", 2500);
	int_helper(failed, succeed, "%-08x", 2500);
	int_helper(failed, succeed, "%-015.3x", 2500);
	int_helper(failed, succeed, "%-015.8x", 2500);
	int_helper(failed, succeed, "%-15.4x", 2500);
	int_helper(failed, succeed, "%-015.3x", -2500);
	int_helper(failed, succeed, "%-015.13x", -2500);
	int_helper(failed, succeed, "%-3.x", 0);
	int_helper(failed, succeed, "%-03.x", 0);
	int_helper(failed, succeed, "%-3.2x", 0);
	int_helper(failed, succeed, "%-015.13x", -2500);
	int_helper(failed, succeed, "%-hhX", USHRT_MAX);
	int_helper(failed, succeed, "%-#8.3x", -2500);
	int_helper(failed, succeed, "%-#15.3x", -2500);
	int_helper(failed, succeed, "%-#6x", 2500);
	int_helper(failed, succeed, "%-#3x", 2500);
	int_helper(failed, succeed, "%-#.4x", 2500);
	int_helper(failed, succeed, "%-#.x", 0);
	int_helper(failed, succeed, "%-#3.x", 0);
	int_helper(failed, succeed, "%-#3.2x", 0);
	int_helper(failed, succeed, "%-#08x", 42);
	int_helper(failed, succeed, "%-#.7x", 2500);
	int_helper(failed, succeed, "%-#020.13x", -2500);
	int_helper(failed, succeed, "%-#.3x", 2500);
	int_helper(failed, succeed, "%-#.2x", 2500);
	int_helper(failed, succeed, "%-#x", 0);
}

void	integer_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> INTEGER <<<<\033[0m\n\n\n");

	decimal_signed_tests(failed, succeed);
	decimal_unsigned_tests(failed, succeed);
	octal_tests(failed, succeed);
	hexademical_tests(failed, succeed);
}

void	chr_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> CHAR <<<<\033[0m\n\n\n");

	char_helper(failed, succeed, "%05c", 42);
	char_helper(failed, succeed, "%c", 200);
}

void	string_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> STRING <<<<\033[0m\n\n\n");

	string_helper(failed, succeed, "%.4s", "012345678");
	string_helper(failed, succeed, "%5.0s", "012345678");
//	string_helper(failed, succeed, "%5.0s", 0);
	string_helper(failed, succeed, "%5.4s", "012345678");
	string_helper(failed, succeed, "%0.4s", "012345678");
//	string_helper(failed, succeed, "%05.s", 0);
}

void	wide_char_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> WIDE CHAR <<<<\033[0m\n\n\n");

	wide_char_helper(failed, succeed, "%C", L'猫');
	wide_char_helper(failed, succeed, "%C", L'米');
	wide_char_helper(failed, succeed, "%hhC", L'米');
//	wide_char_helper(failed, succeed, "%C", 0);
}

void	wide_string_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> WIDE STRING <<<<\033[0m\n\n\n");

	wide_string_helper(failed, succeed, "%8.S", L"是一只猫是一只猫");
	wide_string_helper(failed, succeed, "%8.4lls", L"是一只猫是一只猫");
	wide_string_helper(failed, succeed, "%8.4S", L"是一只猫是一只猫");
	wide_string_helper(failed, succeed, "%.4S", L"是一只猫是一只猫");
	wide_string_helper(failed, succeed, "%030S", L"是一只猫是一只猫");
	wide_string_helper(failed, succeed, "%0.4S", L"米米米");
	wide_string_helper(failed, succeed, "%5.4S", L"米米米");
	wide_string_helper(failed, succeed, "%.4S", L"米米米");
	wide_string_helper(failed, succeed, "%5.0S", L"米米米");
	wide_string_helper(failed, succeed, "%5S", 0);
	wide_string_helper(failed, succeed, "%5.0S", 0);
}

void	pointer_tests(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> POINTER <<<<\033[0m\n\n\n");

	pointer_helper(failed, succeed, "%05p", 0);
	pointer_helper(failed, succeed, "%09.2p", (void *)1234);
	pointer_helper(failed, succeed, "%-9.2p", (void *)1234);
	pointer_helper(failed, succeed, "%09.2p", &wide_string_tests);
	pointer_helper(failed, succeed, "%5p", 0);
	pointer_helper(failed, succeed, "%04.8p", 0);
	pointer_helper(failed, succeed, "%05.2p", 0);
	pointer_helper(failed, succeed, "%5p", 0);
	pointer_helper(failed, succeed, "%09.2p", (void *)1234);
	pointer_helper(failed, succeed, "%.p", 0);
	pointer_helper(failed, succeed, "%.0p", 0);
}

void	invalid_specifier_tests(int *failed, int *succeed)
{
	int a = 0, b = 0;

	printf("\033[32;1m\t\t\t>>>> INVALID SPECIFIER <<<<\033[0m\n\n\n");

	a = ft_printf("%5Zoo", 1234);
	puts("$");
	b = printf("%5Zoo", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%-5Zoo", 1234);
	puts("$");
	b = printf("%-5Zoo", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%+5Zoo", 1234);
	puts("$");
	b = printf("%+5Zoo", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("% Zoo", 1234);
	puts("$");
	b = printf("% Zoo", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%05Zoo", 1234);
	puts("$");
	b = printf("%05Zoo", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%05.3Zoo", 1234);
	puts("$");
	b = printf("%05.3Zoo", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%0.3Zoo", 1234);
	puts("$");
	b = printf("%0.3Zoo", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%", 1234);
	puts("$");
	b = printf("%", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%   %", "test");
	puts("$");
	b = printf("%   %", "test");
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%%", "test");
	puts("$");
	b = printf("%%", "test");
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%-5%");
	puts("$");
	b = printf("%-5%");
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%5%");
	puts("$");
	b = printf("%5%");
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

}

int 	main()
{
	int 	failed = 0, succeed = 0;

	setlocale(LC_ALL, "");
	for (int i = 0; i < 20; i++)
		puts("\n\n\n");

//	integer_tests(&failed, &succeed);
//	chr_tests(&failed, &succeed);
//	string_tests(&failed, &succeed);
//	wide_char_tests(&failed, &succeed);
	wide_string_tests(&failed, &succeed);
//	pointer_tests(&failed, &succeed);
//	invalid_specifier_tests(&failed, &succeed);

	printf("\n\n\033[32;1m...........................RETURNED VALUE EQUAL:\t%d\033[0m\n", succeed);
	printf("\033[31;1m...........................RETURNED VALUE NOT EQUAL:\t%d\033[0m\n\n\n", failed);
}
