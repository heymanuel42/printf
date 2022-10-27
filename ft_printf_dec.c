/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:20:24 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/27 23:20:46 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(int data)
{
	char	*str;
	int		length;

	str = ft_strdup((ft_itoa(data)));
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (length);
}
