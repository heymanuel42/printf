/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:22:24 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/27 23:54:51 by ejanssen         ###   ########.fr       */
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

static int	handle_print(t_list *list, va_list arguments)
{
	char	*elem;
	int		length;

	length = 0;
	while (list)
	{
		elem = (char *)list->content;
		if (elem[0] == '%')
		{
			if (elem[1] == '\0')
				length += ft_print_str("%");
			else if (elem[ft_strlen((elem)) - 1] == 'c')
				length += ft_print_char(va_arg(arguments, int));
			else if (elem[ft_strlen(elem) - 1] == 's')
				length += ft_print_str(va_arg(arguments, char *));
			else if (elem[ft_strlen(elem) - 1] == 'd'
				|| elem[ft_strlen((elem)) - 1] == 'i')
				length += ft_print_dec(va_arg(arguments, int));
			else if (elem[ft_strlen(elem) - 1] == 'p')
				length += ft_print_str(list->content);
			else if (elem[ft_strlen(elem) - 1] == 'u')
				length += ft_print_str(list->content);
			else if (elem[ft_strlen(elem) - 1] == 'x')
				length += ft_print_str(list->content);
			else if (elem[ft_strlen(elem) - 1] == 'X')
				length += ft_print_str(list->content);
		}
		else
			length += ft_print_str(list->content);
		list = list->next;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	t_list	*list;
	int		length;

	(void)g_flags;
	list = NULL;
	build_list(&list, str);
	va_start(arguments, str);
	length = handle_print(list, arguments);
	ft_lstclear(&list, free);
	return (length);
}
