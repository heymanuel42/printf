/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:22:24 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/28 15:23:12 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static char	*g_params = "cspdiuxX";
static char	*g_flags = "-0.# +";

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
		{
			i = ft_parse_param(str_lst, str, i);
		}
		else
		{
			while (str[i + r] != '%' && str[i + r] != '\0')
				r++;
			ft_lstadd_back(str_lst, ft_lstnew(ft_substr(str, i, r)));
			i += r;
		}
	}
}

static void	handle_print(t_list *list, va_list args, int *l)
{
	char	*el;

	while (list)
	{
		el = (char *)list->content;
		if (el[0] == '%')
		{
			if (el[1] == '\0')
				*l += ft_printf_str("%");
			else if (el[ft_strlen((el)) - 1] == 'c')
				*l += ft_printf_char(va_arg(args, int));
			else if (el[ft_strlen(el) - 1] == 's')
				*l += ft_printf_str(va_arg(args, char *));
			else if (el[ft_strlen(el) - 1] == 'd'
				|| el[ft_strlen((el)) - 1] == 'i')
				*l += ft_printf_dec(va_arg(args, int));
			else if (el[ft_strlen(el) - 1] == 'p')
				*l += ft_printf_ptr(va_arg(args, void *));
			else if (el[ft_strlen(el) - 1] == 'u')
				*l += ft_printf_unsigned_dec(va_arg(args, unsigned int));
			else if (el[ft_strlen(el) - 1] == 'x')
				*l += ft_printf_hex_low(va_arg(args, unsigned int));
			else if (el[ft_strlen(el) - 1] == 'X')
				*l += ft_printf_hex_up(va_arg(args, unsigned int));
			else
				*l += ft_printf_str(list->content);
		}
		else
			*l += ft_printf_str(list->content);
		list = list->next;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	t_list	*list;
	int		length;

	length = 0;
	(void)g_flags;
	list = NULL;
	build_list(&list, str);
	va_start(arguments, str);
	handle_print(list, arguments, &length);
	va_end(arguments);
	ft_lstclear(&list, free);
	return (length);
}
