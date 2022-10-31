/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:41:57 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/29 09:55:57 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		length;

	ft_printf("%d hello\n", 3);
	printf("%+-0123d hello\n", 3);
	return (0);
}

/**
 * length = ft_printf("%%%%% p\n", NULL);
	length = printf("%%%%% p\n", NULL);
	printf("%d\n", length);
	length = printf("%p\n", "");
	printf("%d\n", length);
	length = ft_printf("%x\n", 0);
	printf("%d\n", length);
	length = printf("%x\n", 0);
	printf("%d\n", length);
	ft_printf("%p\n", 0);
	ft_printf("%p\n", "hello");
	ft_printf("%p\n", 99);
	ft_printf("%p\n", 16 * 16);
	printf("%x\n", 16);
	ft_printf("%p %p\n", LONG_MIN, LONG_MAX);
	ft_printf("%p %p\n", ULONG_MAX, -ULONG_MAX);
	printf("%p %p\n", LONG_MIN, LONG_MAX);
	printf("%p %p\n", ULONG_MAX, -ULONG_MAX);
	printf("%0-20d hello\n", 3875623);
	printf("%d\n", ft_atoi("#10d"));
	ft_printf_padstr(ft_strdup("hello world\n\n"),
	 ft_strlen("hello world\n\n"), '0');
*/
