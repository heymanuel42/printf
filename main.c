/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:41:57 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/28 16:18:23 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		length;
	length = ft_printf("%p\n",1);
		length = printf("%p\n ",  1);

	//printf("%d\n", length);
	//length = printf("%p\n","");
	//printf("%d\n", length);

	//length = ft_printf("%x\n",0);
	//printf("%d\n", length);
	//length = printf("%x\n",0);
	//printf("%d\n", length);

/*	ft_printf("%p\n", 0);
	ft_printf("%p\n", hello);
	ft_printf("%p\n", 99);
	ft_printf("%p\n", 16 * 16);
	printf("%x\n", 16);

	ft_printf("%p %p\n", LONG_MIN, LONG_MAX);
	ft_printf("%p %p\n", ULONG_MAX, -ULONG_MAX);

	printf("%p %p\n", LONG_MIN, LONG_MAX);
	printf("%p %p\n", ULONG_MAX, -ULONG_MAX);*/
	return (0);
}
