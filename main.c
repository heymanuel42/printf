/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:41:57 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/27 23:55:23 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	length;

	length = ft_printf("Hello  world %c %s\n", 'x', "test");
	printf("len = %d\n", length);
	length = ft_printf("Hello  world %s\n", "Bonjour");
	printf("len = %d\n", length);
	length = ft_printf("Hello  world %d\n", 1234);
	printf("len = %d\n", length);
	length = ft_printf("Hello  world %d %%%d %x\n", 1234, 20, 100);
	printf("len = %d\n", length);
	ft_printf("%%%%%\n", 1234, 20);
	printf("\n\%%%%%\n", 10);
	return (0);
}
