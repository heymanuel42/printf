/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:22:24 by ejanssen          #+#    #+#             */
/*   Updated: 2022/10/27 21:43:04 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static int	count_args(t_list **str_lst, const char *str)
{
	int		i;
	int		r;

	i = 0;
	while (str[i] != '\0')
	{
		r = 0;
		if (str[i] == '%')
		{
			while (ft_strchr(g_params, str[i + r]) == NULL )
				r++;
			ft_lstadd_back(str_lst, ft_lstnew(ft_substr(str, i, r + 1)));
			i += r;
		}
		else
		{
			while (str[i + r] != '%' && str[i + r] != '\0')
				r++;
			ft_lstadd_back(str_lst, ft_lstnew(ft_substr(str, i + 1, r - 1)));
			i += r;
		}
	}
	return (ft_lstsize(*str_lst));
}

static void	print_list(t_list *l)
{
	while (l)
	{
		ft_putendl_fd(l->content, 1);
		l = l->next;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	t_list	*list;

	list = NULL;
	(void)g_flags;
	(void) arguments;
	ft_putstr_fd((char *)str, 1);
	count_args(&list, str);
	print_list(list);
	ft_lstclear(&list, free);
	return (ft_strlen(str));
}
