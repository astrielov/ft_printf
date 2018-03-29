/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:55:40 by astrelov          #+#    #+#             */
/*   Updated: 2018/03/29 10:58:40 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <locale.h>

int 	main()
{
	int 	a = 0, b = 0;

	setlocale(LC_ALL, "");

	for (int i = 0; i < 20; i++)
		puts("\n");

	/**
	 * STRING
	 */

	a = ft_printf("%.4s", "012345678");
	puts("$");
	b = printf("%.4s", "012345678");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%5.0s", "012345678");
	puts("$");
	b = printf("%5.0s", "012345678");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

//	a = ft_printf("%5.0s", 0);
//	puts("$");
//	b = printf("%5.0s", 0);
//	puts("$\n");
//	if (a != b)
//		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%5.4s", "012345678");
	puts("$");
	b = printf("%5.4s", "012345678");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%0.4s", "012345678");
	puts("$");
	b = printf("%0.4s", "012345678");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

//	a = ft_printf("{%05.s}", 0);
//	puts("$");
//	b = printf("{%05.s}", 0);
//	puts("$\n");
//	if (a != b)
//		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	/**
	 * WIDE STRING
	 */

	a = ft_printf("%8.S", L"是一只猫是一只猫");
	puts("$");
	b = printf("%8.S", L"是一只猫是一只猫");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%8.4S", L"是一只猫是一只猫");
	puts("$");
	b = printf("%8.4S", L"是一只猫是一只猫");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%.4S", L"是一只猫是一只猫");
	puts("$");
	b = printf("%.4S", L"是一只猫是一只猫");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%030S", L"是一只猫是一只猫");
	puts("$");
	b = printf("%030S", L"是一只猫是一只猫");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%0.4S", L"米米米");
	puts("$");
	b = printf("%0.4S", L"米米米");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%5.4S", L"米米米");
	puts("$");
	b = printf("%5.4S", L"米米米");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%.4S", L"米米米");
	puts("$");
	b = printf("%.4S", L"米米米");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%5.0S", L"米米米");
	puts("$");
	b = printf("%5.0S", L"米米米");
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

//	a = ft_printf("%5.0S", 0);
//	puts("$");
//	b = printf("%5.0S", 0);
//	puts("$\n");
//	if (a != b)
//		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	/**
	 * WIDE CHAR
	 */

	a = ft_printf("%C", L'米');
	puts("$");
	b = printf("%C", L'米');
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%hhC", L'米');
	puts("$");
	b = printf("%hhC", L'米');
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

//	a = ft_printf("%C", 0);
//	puts("$");
//	b = printf("%C", 0);
//	puts("$\n");
//	if (a != b)
//		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	/**
	 * POINTER
	 */

	a = ft_printf("{%05p}", 0);
	puts("$");
	b = printf("{%05p}", 0);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("{%5p}", 0);
	puts("$");
	b = printf("{%5p}", 0);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("{%04.8p}", 0);
	puts("$");
	b = printf("{%04.8p}", 0);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("{%05.2p}", 0);
	puts("$");
	b = printf("{%05.2p}", 0);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("{%5p}", 0);
	puts("$");
	b = printf("{%5p}", 0);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("{%.p, %.0p}", 0, 0);
	puts("$");
	b = printf("{%.p, %.0p}", 0, 0);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("{%9.2p}", 1234);
	puts("$");
	b = printf("{%9.2p}", 1234);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("{%-9.2p}", 1234);
	puts("$");
	b = printf("{%-9.2p}", 1234);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("{%09.2p}", 1234);
	puts("$");
	b = printf("{%09.2p}", 1234);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	/**
	 * INVALID SPECIFIER
	 */

	a = ft_printf("{%5Zoo}", 1234);
	puts("$");
	b = printf("{%5Zoo}", 1234);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

	a = ft_printf("%", 1234);
	puts("$");
	b = printf("%", 1234);
	puts("$\n");
	if (a != b)
		printf("\x1B[A\033[31;1m>>>> RESULT: ft_pf(%d), pf(%d) <<<<\033[0m\n\n\n", a, b);

}
