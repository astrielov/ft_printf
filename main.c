/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:55:40 by astrelov          #+#    #+#             */
/*   Updated: 2018/03/29 18:32:06 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <locale.h>

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

void	decimal_signed(int *failed, int *succeed)
{
	int_helper(failed, succeed, "%d", 42);
	int_helper(failed, succeed, "%i", 42);
	int_helper(failed, succeed, "%D", 42);
	int_helper(failed, succeed, "%d", 0);
	int_helper(failed, succeed, "%3.d", 0);
	int_helper(failed, succeed, "%.d", 0);
	int_helper(failed, succeed, "%6d", 4242);
	int_helper(failed, succeed, "%6d", -4242);
	int_helper(failed, succeed, "%3d", 4242);
	int_helper(failed, succeed, "%3d", -4242);
	int_helper(failed, succeed, "%.6d", 4242);
	int_helper(failed, succeed, "%.3d", 4242);
	int_helper(failed, succeed, "%8.3d", -4242);
	int_helper(failed, succeed, "%6d", -4242);
	int_helper(failed, succeed, "%.3d", -4242);
	int_helper(failed, succeed, "%.6d", -4242);
	int_helper(failed, succeed, "%-8.3d", -4242);
	int_helper(failed, succeed, "% .3d", 4242);
	int_helper(failed, succeed, "% .6d", 4242);
	int_helper(failed, succeed, "%+.3d", -4242);
	int_helper(failed, succeed, "%+.6d", 4242);
	int_helper(failed, succeed, "%08.3d", -4242);
}

void	decimal_unsigned(int *failed, int *succeed)
{
	int_helper(failed, succeed, "%u", 42);
	int_helper(failed, succeed, "%U", 42);
	int_helper(failed, succeed, "%u", 0);
	int_helper(failed, succeed, "%3.u", 0);
	int_helper(failed, succeed, "%.u", 0);
	int_helper(failed, succeed, "%6u", 4242);
	int_helper(failed, succeed, "%6u", -4242);
	int_helper(failed, succeed, "%3u", 4242);
	int_helper(failed, succeed, "%3u", -4242);
	int_helper(failed, succeed, "%.6u", 4242);
	int_helper(failed, succeed, "%.3u", 4242);
	int_helper(failed, succeed, "%8.3u", -4242);
	int_helper(failed, succeed, "%6u", -4242);
	int_helper(failed, succeed, "%.3u", -4242);
	int_helper(failed, succeed, "%.6u", -4242);
	int_helper(failed, succeed, "%-8.3u", -4242);
	int_helper(failed, succeed, "% .3u", 4242);
	int_helper(failed, succeed, "% .6u", 4242);
	int_helper(failed, succeed, "%+.3u", -4242);
	int_helper(failed, succeed, "%+.6u", 4242);
	int_helper(failed, succeed, "%08.3u", -4242);
}

void	octal(int *failed, int *succeed)
{
	int_helper(failed, succeed, "%o", 42);
	int_helper(failed, succeed, "%O", 42);
	int_helper(failed, succeed, "%o", 0);
	int_helper(failed, succeed, "%3.o", 0);
	int_helper(failed, succeed, "%.o", 0);
	int_helper(failed, succeed, "%6o", 4242);
	int_helper(failed, succeed, "%6o", -4242);
	int_helper(failed, succeed, "%3o", 4242);
	int_helper(failed, succeed, "%3o", -4242);
	int_helper(failed, succeed, "%.6o", 4242);
	int_helper(failed, succeed, "%.3o", 4242);
	int_helper(failed, succeed, "%8.3o", -4242);
	int_helper(failed, succeed, "%6o", -4242);
	int_helper(failed, succeed, "%.3o", -4242);
	int_helper(failed, succeed, "%.6o", -4242);
	int_helper(failed, succeed, "%-8.3o", -4242);
	int_helper(failed, succeed, "% .3o", 4242);
	int_helper(failed, succeed, "% .7o", 4242);
	int_helper(failed, succeed, "%+.3o", -4242);
	int_helper(failed, succeed, "%+.6o", 4242);
	int_helper(failed, succeed, "%015.3o", -4242);
	int_helper(failed, succeed, "% 15.3o", -4242);
	int_helper(failed, succeed, "%#15.3o", -4242);
}

void	hexademical(int *failed, int *succeed)
{
	int_helper(failed, succeed, "%x", 42);
	int_helper(failed, succeed, "%X", 42);
	int_helper(failed, succeed, "%x", 0);
	int_helper(failed, succeed, "%3.x", 0);
	int_helper(failed, succeed, "%.x", 0);
	int_helper(failed, succeed, "%6x", 4242);
	int_helper(failed, succeed, "%6x", -4242);
	int_helper(failed, succeed, "%3x", 4242);
	int_helper(failed, succeed, "%3x", -4242);
	int_helper(failed, succeed, "%.6x", 4242);
	int_helper(failed, succeed, "%.3x", 4242);
	int_helper(failed, succeed, "%10.3x", -4242);
	int_helper(failed, succeed, "%6x", -4242);
	int_helper(failed, succeed, "%.3x", -4242);
	int_helper(failed, succeed, "%.6x", -4242);
	int_helper(failed, succeed, "%-10.3x", -4242);
	int_helper(failed, succeed, "% .3x", 4242);
	int_helper(failed, succeed, "% .6x", 4242);
	int_helper(failed, succeed, "%+.3x", -4242);
	int_helper(failed, succeed, "%+.10x", -4242);
	int_helper(failed, succeed, "%+10x", -4242);
	int_helper(failed, succeed, "%+.6x", 4242);
	int_helper(failed, succeed, "%0#12.3x", -4242);
}

void	integer(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> INTEGER <<<<\033[0m\n\n\n");

//	decimal_signed(failed, succeed);
//	decimal_unsigned(failed, succeed);
	octal(failed, succeed);
//	hexademical(failed, succeed);
}

void	string(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> STRING <<<<\033[0m\n\n\n");

	string_helper(failed, succeed, "%.4s", "012345678");
	string_helper(failed, succeed, "%5.0s", "012345678");
//	string_helper(failed, succeed, "%5.0s", 0);
	string_helper(failed, succeed, "%5.4s", "012345678");
	string_helper(failed, succeed, "%0.4s", "012345678");
//	string_helper(failed, succeed, "%05.s", 0);
}

void	wide_char(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> WIDE CHAR <<<<\033[0m\n\n\n");

	wide_char_helper(failed, succeed, "%C", L'猫');
	wide_char_helper(failed, succeed, "%C", L'米');
	wide_char_helper(failed, succeed, "%hhC", L'米');
//	wide_char_helper(failed, succeed, "%C", 0);
}

void	wide_string(int *failed, int *succeed)
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
//	wide_string_helper(failed, succeed, "%5.0S", 0);
}

void	pointer(int *failed, int *succeed)
{
	printf("\033[32;1m\t\t\t>>>> POINTER <<<<\033[0m\n\n\n");

	pointer_helper(failed, succeed, "%05p", 0);
	pointer_helper(failed, succeed, "%09.2p", (void *)1234);
	pointer_helper(failed, succeed, "%-9.2p", (void *)1234);
	pointer_helper(failed, succeed, "%09.2p", &wide_string);
	pointer_helper(failed, succeed, "%5p", 0);
	pointer_helper(failed, succeed, "%04.8p", 0);
	pointer_helper(failed, succeed, "%05.2p", 0);
	pointer_helper(failed, succeed, "%5p", 0);
	pointer_helper(failed, succeed, "%09.2p", (void *)1234);
	pointer_helper(failed, succeed, "%.p", 0);
	pointer_helper(failed, succeed, "%.0p", 0);
}

void	invalid_specifier(int *failed, int *succeed)
{
	int a = 0, b = 0;

	printf("\033[32;1m\t\t\t>>>> INVALID SPECIFIER <<<<\033[0m\n\n\n");

	a = ft_printf("%5Zoo", 1234);
	puts("$");
	b = printf("%5Zoo", 1234);
	puts("$\n");
	if (a != b)	printf("\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);
	if (a != b) *failed += 1; else *succeed += 1;

	a = ft_printf("%", 1234);
	puts("$");
	b = printf("%", 1234);
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

	integer(&failed, &succeed);
//	string(&failed, &succeed);
//	wide_char(&failed, &succeed);
//	wide_string(&failed, &succeed);
//	pointer(&failed, &succeed);
//	invalid_specifier(&failed, &succeed);

	printf("\n\n\033[32;1m...........................TESTS SUCCEED:\t%d\033[0m\n", succeed);
	printf("\033[31;1m...........................TESTS FAILED:\t%d\033[0m\n\n\n", failed);
}
