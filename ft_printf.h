/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:43:48 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/28 23:13:30 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_printf_char(char data);
int	ft_printf_dec(int data);
int	ft_printf_unsigned_dec(unsigned int data);
int	ft_printf_hex_low(unsigned long data);
int	ft_printf_hex_up(unsigned long data);
int	ft_printf_ptr(void *data);
int	ft_printf_str(void *data);

typedef enum e_padding{
	LEFT = 1,
	RIGHT = 2
}t_padding;

int	ft_printf_padstr(void *data, int n, char c, t_padding padding);

#endif
