/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:22:24 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/28 23:34:26 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libft_bonus.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static char	*g_params = "cspdiuxX";
//static char	*g_flags = "-0.# +";

static int	ft_parse_param(t_list **list, const char *str, int start)
{
	int	size;

	size = 0;
	if (str[start + 1] == '%')
	{
		ft_lstadd_back(list, ft_lstnew(ft_strdup("%")));
		start += 2;
	}
	else
	{
		while (ft_strchr(g_params, str[start + size]) == NULL )
			size++;
		ft_lstadd_back(list, ft_lstnew(ft_substr(str, start, size + 1)));
		start += size + 1;
	}
	return (start);
}

static void	build_list(t_list **str_lst, const char *str)
{
	size_t	i;
	size_t	r;

	i = 0;
	while (str[i] != '\0' && i < ft_strlen(str))
	{
		r = 0;
		if (str[i] == '%')
			i = ft_parse_param(str_lst, str, i);
		else
		{
			while (str[i + r] != '%' && str[i + r] != '\0')
				r++;
			ft_lstadd_back(str_lst, ft_lstnew(ft_substr(str, i, r)));
			i += r;
		}
	}
}

static	int	handle_d(void *param, int arg)
{
	char	*c;

	if (((unsigned char *)param)[1] == '0')
	{
		c = ft_itoa(arg);
		if (((unsigned char *)param)[2] == '-')
			ft_printf_padstr(c, 10, '0', RIGHT);
		else if (((unsigned char *)param)[2] == '+')
			ft_printf_padstr(ft_strjoin("+", c), 10, '0', LEFT);
	}
	else if (((unsigned char *)param)[1] == '-')
	{
		c = ft_itoa(arg);
		if (((unsigned char *)param)[2] == '0')
			ft_printf_padstr(c, 10, '0', RIGHT);
		else
			ft_printf_padstr(c, 10, '0', LEFT);
	}
	else
		ft_printf_dec(arg);
	return (1);
}
static int	print(char *data, va_list args)
{
	if (data[0] == '%')
	{
		if (data[ft_strlen(data) - 1] == 'c')
			return (ft_printf_char(va_arg(args, int)));
		else if (data[ft_strlen(data) - 1] == 's')
			return (ft_printf_str(va_arg(args, char *)));
		else if (data[ft_strlen(data) - 1] == 'd'
			|| data[ft_strlen(data) - 1] == 'i')
			return (handle_d(data, va_arg(args, int)));
		else if (data[ft_strlen(data) - 1] == 'p')
			return (ft_printf_ptr(va_arg(args, void *)));
		else if (data[ft_strlen(data) - 1] == 'u')
			return (ft_printf_unsigned_dec(va_arg(args, unsigned int)));
		else if (data[ft_strlen(data) - 1] == 'x')
			return (ft_printf_hex_low(va_arg(args, unsigned int)));
		else if (data[ft_strlen(data) - 1] == 'X')
			return (ft_printf_hex_up(va_arg(args, unsigned int)));
		else
			return (ft_printf_str(data));
	}
	return (ft_printf_str(data));
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	t_list	*list;
	char	*el;
	int		length;

	length = 0;
	list = NULL;
	build_list(&list, str);
	va_start(arguments, str);
	while (list)
	{
		el = (char *)list->content;
		length += print(el, arguments);
		list = list->next;
	}
	va_end(arguments);
	ft_lstclear(&list, free);
	return (length);
}
