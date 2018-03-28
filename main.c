/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:55:40 by astrelov          #+#    #+#             */
/*   Updated: 2018/03/28 12:31:10 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <locale.h>

int 	main()
{
	int 	a = 0, b = 0;

	for (int i = 0; i < 20; i++)
		puts("\n");


	ft_printf("%030S", L"是一只猫是一只猫");
	puts("\n\n");
	ft_printf("%.4S", L"是一只猫是一只猫");
	puts("\n\n");
	ft_printf("%8.4S", L"是一只猫是一只猫");
	puts("\n\n");
	ft_printf("%8.S", L"是一只猫是一只猫");
	puts("\n\n");
	ft_printf("%C", 0);
	puts("\n\n");
	ft_printf("%hhC", 0);
	puts("\n\n");
	ft_printf("%hhC", L'米');
	puts("\n\n");
	ft_printf("% C", 0);
	puts("\n\n");
	ft_printf("{%05.s}", 0);
	puts("\n\n");
	ft_printf("{%05p}", 0);
	puts("\n\n");
	ft_printf("{%5p}", 0);
	puts("\n\n");
	ft_printf("{%04.8p}", 0);
	puts("\n\n");
	ft_printf("{%05.2p}", 0);
	puts("\n\n");
	ft_printf("{%5p}", 0);
	puts("\n\n");
	ft_printf("{%05p}", 0);
	puts("\n\n");
	ft_printf("{%.p, %.0p}", 0, 0);
	puts("\n\n");
	ft_printf("{%9.2p}", 1234);
	puts("\n\n");
	ft_printf("{%-9.2p}", 1234);
	puts("\n\n");
	ft_printf("{%09.2p}", 1234);
	puts("\n\n");
	ft_printf("{%5Zoo}", 1234);
	puts("\n\n");
	ft_printf("%", 1234);
	puts("\n\n");
}
