/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:43:48 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/27 23:23:46 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(char data);
int	ft_print_dec(int data);
int	ft_print_str(void *data);

#endif
